

#include <util/delay.h>

#include "adc.h"
#include "max6675.h"
#include "softspi.h"
#include "uart.h"

#include "comparator.h"



// функции переключения вывода CS (Chip Select Pin)
//
// ===============================================================================
//
// CS output switching functions (Chip Select Pin)
//
void CS_Set_Active()
{
	PORTA &= ~(1 << 3);
}

void CS_Set_Inactive()
{
	PORTA |=  (1 << 3);
}



// функции включения и выключения нагрузки (резистивный нагревательный элемент)
//
// -------------------------------------------------------------------------------
//
// functions of switching on and off the load (resistive heating element)
//
inline void Heater_On()
{
	PORTB |=  (1 << 1);
}

inline void Heater_Off()
{
	PORTB &= ~(1 << 1);
}


// функции аварийного отключения нагрузки
// (вызывается при неисправности термодатчика и прочих аварийных ситуациях)
//
// -------------------------------------------------------------------------------
//
// emergency load shutdown functions
// (triggered in case of malfunction of the temperature sensor
// and other emergency situations)
//
inline void Heater_Emergency_Shutdown()
{
	PORTB &= ~(1 << 1);
}




// переменная состояния компаратора
//
// -------------------------------------------------------------------------------
//
// comparator state variable
//
bool comparator_state = false;


// определение значений переменных:
//
// target_temp - целевое значение температуры (его можно менять извне)
// current_temp - текущее значение температуры (получается от датчика)
//
// -------------------------------------------------------------------------------
//
// determining the values of variables:
//
// target_temp - the target temperature value (it can be changed from the outside)
// current_temp - the current temperature value (obtained from the sensor)
//
int16_t target_temp = 70;
int16_t current_temp;


// счётчик периодов обновления значения компаратора
// -------------------------------------------------------------------------------
// counter for comparator value update periods
//
uint16_t sensor_time_counter = 0;


// переменная, хранящая информацию о работоспособности термопары
// -------------------------------------------------------------------------------
// a variable that stores information about the health of the thermocouple
//
bool is_temperature_sensor_working_properly;


// период опроса датчика и обновления значения компаратора (в миллисекундах)
//
// -------------------------------------------------------------------------------
//
// callback for processing a single button press (in milliseconds)
//
#define DELTA_T 25


// счётчик периодов времени для получения значения от датчика температуры
// (используемый датчик температуры на основе термопары K-типа
// нельзя опрашивать чаще времени DELTA_T_SENSOR)
//
// -------------------------------------------------------------------------------
//
// time period counter for receiving the value from the temperature sensor
// (the temperature sensor used based on the K-type
// thermocouple cannot be interrogated more often than the DELTA_T_SENSOR time)
//
#define DELTA_T_SENSOR 250




int main(void)
{
	// настройка внешних GPIO
	//
	// -------------------------------------------------------------------------------
	//
	// configuring external GPIOs
	//
	DDRA  |=  (1 << 3);
	
	PORTB &= ~(1 << 1);
	DDRB  |=  (1 << 1);
	
	
	
	ADC_Initialize(0, ADC_PRESCALER_128, ADC_VREF_SOURCE_EXTERNAL_AVCC, true);
	
	SOFTSPI_Initialize();
	SOFTSPI_Set_CS_Callback_Functions(CS_Set_Active, CS_Set_Inactive);
	
	UART_Initialize(9600, true, false);
	
	
	while (1)
	{
		// опрос датчика температуры с периодом DELTA_T_SENSOR
		//
		// -------------------------------------------------------------------------------
		//
		// polling a temperature sensor with a DELTA_T_SENSOR period
		//
		if (sensor_time_counter == (DELTA_T_SENSOR / DELTA_T))
		{
			sensor_time_counter = 0;
			
			is_temperature_sensor_working_properly = MAX6675_Get_Temperature_In_Celsius_Integer( (uint16_t*)(&current_temp) );
		}
		
		++sensor_time_counter;
		
		
		
		// опрос датчика температуры с периодом DELTA_T_SENSOR
		//
		// -------------------------------------------------------------------------------
		//
		// polling a temperature sensor with a DELTA_T_SENSOR period
		//
		if (is_temperature_sensor_working_properly)
		{
			
			// отправка данных на плоттер
			// (для визуализации процесса регулирования температуры)
			//
			// -------------------------------------------------------------------------------
			//
			// sending data to the plotter
			// (to visualize the temperature control process)
			//
			UART_Data_Transmit(&target_temp,  sizeof(int16_t));
			UART_Data_Transmit(&current_temp, sizeof(int16_t));
			
			
			
			// если значение current_temp станет равным или превысит значение
			// (target_temp + high_hysteresys), то компаратор перейдёт в состояние
			// COMPARATOR_OUTPUT_IS_HIGH (true)
			//
			// если значение current_temp станет равным или снизится ниже значения
			// (target_temp + low_hysteresys),
			// то компаратор перейдёт в состояние COMPARATOR_OUTPUT_IS_LOW (false)
			//
			// в зависимости от состояния компаратора включаем либо отключаем нагрузку
			//
			//
			// значения гистерезиса (high_hysteresys и low_hysteresys)
			// подобраны экспериментально для используемого нагревателя
			//
			// -------------------------------------------------------------------------------
			//
			// if the current_temp value becomes equal to or exceeds the value
			// (target_temp + high_hysteresys), the comparator will switch
			// to the COMPARATOR_OUTPUT_IS_HIGH (true) state
			//
			// if the current_temp value becomes equal to or drops below the value
			// (target_temp + low_hysteresys) (500 + (-50)),
			// the comparator will switch to the COMPARATOR_OUTPUT_IS_LOW (false) state
			//
			// depending on the state of the comparator, we turn on or turn off the load
			//
			//
			// the hysteresis values (high_hysteresys and low_hysteresys)
			// were selected experimentally for the heater used
			//
			if (Comparator_Int16_Update_And_Get_Output_Value(&comparator_state, current_temp, target_temp, -1, -2) == COMPARATOR_OUTPUT_IS_HIGH)
			{
				Heater_Off();
			}
			else
			{
				Heater_On();
			}
		}
		else
		{
			// если датчик температуры неисправен - немедленно отключаем нагрузку
			//
			// -------------------------------------------------------------------------------
			//
			// if the temperature sensor is faulty, turn off the load immediately
			//
			Heater_Emergency_Shutdown();
		}
		
		
		// опрос компаратора и датчика каждые DELTA_T (мс)
		//
		// -------------------------------------------------------------------------------
		//
		// comparator and sensor polling every DELTA_T (ms)
		//
		_delay_ms(DELTA_T);
	}
}



