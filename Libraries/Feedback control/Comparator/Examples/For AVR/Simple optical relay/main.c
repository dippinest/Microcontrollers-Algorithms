

#include <util/delay.h>

#include "adc.h"
#include "comparator.h"



// функции включения и выключения нагрузки (светодиода)
//
// -------------------------------------------------------------------------------
//
// functions of switching on and off the load (LED)
//
inline void Led_On()
{
	PORTB &= ~(1 << 1);
}

inline void Led_Off()
{
	PORTB |=  (1 << 1);
}


// переменная состояния компаратора
//
// -------------------------------------------------------------------------------
//
// comparator state variable
//
bool comparator_state = false;


int main(void)
{
	// настройка внешних GPIO
	//
	// -------------------------------------------------------------------------------
	//
	// configuring external GPIOs
	//
	PORTB &= ~(1 << 1);
	DDRB  |=  (1 << 1);
	
	
	ADC_Initialize(0, ADC_PRESCALER_128, ADC_VREF_SOURCE_EXTERNAL_AVCC, true);
	
	
	// период опроса датчика и обновления значения компаратора (в миллисекундах)
	//
	// -------------------------------------------------------------------------------
	//
	// callback for processing a single button press (in milliseconds)
	//
	#define DELTA_T 50
	
	
	while (1)
	{
		int16_t adc_val = ADC_Get_Value_10bit();
		
		
		// если значение adc_val станет равным или превысит значение
		// (input_negative + high_hysteresys) (500 + 50),
		// то компаратор перейдёт в состояние COMPARATOR_OUTPUT_IS_HIGH (true)
		//
		// если значение adc_val станет равным или снизится ниже значения
		// (input_negative + low_hysteresys) (500 + (-50)),
		// то компаратор перейдёт в состояние COMPARATOR_OUTPUT_IS_LOW (false)
		//
		// в зависимости от состояния компаратора включаем либо отключаем нагрузку
		//
		// -------------------------------------------------------------------------------
		//
		// if the value of adc_val becomes equal to or exceeds the value
		// (input_negative + high_hysteresys) (500 + 50),
		// then the comparator will switch to the COMPARATOR_OUTPUT_IS_HIGH (true) state
		//
		// if the value of adc_val becomes equal to or drops below the value
		// (input_negative + low_hysteresys) (500 + (-50)),
		// then the comparator will switch to the COMPARATOR_OUTPUT_IS_LOW (false) state
		//
		// depending on the state of the comparator, we turn on or turn off the load
		//
		if (Comparator_Int16_Update_And_Get_Output_Value(&comparator_state, adc_val, 500, 50, -50) == COMPARATOR_OUTPUT_IS_HIGH)
		{
			Led_On();
		}
		else
		{
			Led_Off();
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




