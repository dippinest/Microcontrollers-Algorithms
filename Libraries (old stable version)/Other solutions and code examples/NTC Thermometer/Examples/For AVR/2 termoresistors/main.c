
#include <util/delay.h>

#include "ftoa.h"
#include "adc.h"
#include "ntc.h"
#include "uart.h"

static char str_buf[16];



// коэффициенты в этом примере рассчитаны для
// терморезисторы MF52 NTC-MF52AT 100 кОм
// -------------------------------------------------------------------------------
// the coefficients in this example are
// calculated for MF52 NTC-MF52AT 100K thermistors


// коэффициенты A, B и C для обоих термисторов
// -------------------------------------------------------------------------------
// A, B and C coefficients for both thermistors
//
#define A_COEF    1.044253909E-3
#define B_COEF    1.807648763E-4
#define C_COEF    1.498221745E-7


// сопротивление постоянных резисторов в Омах (измеряется мультиметром)
// -------------------------------------------------------------------------------
// resistance of permanent resistors in ohms (measured by a multimeter)
//
#define R_SERIAL     97500


// напряжение питания измерительной цепи (в Вольтах)
// -------------------------------------------------------------------------------
// supply voltage of the measuring circuit (in Volts)
//
#define U_GEN        5.09f


// опорное напряжение АЦП (в Вольтах)
// -------------------------------------------------------------------------------
// ADC reference voltage (in Volts)
//
#define U_REF        5.07f


// максимальное цифровое значение АЦП
// -------------------------------------------------------------------------------
// maximum digital value of the ADC
//
#define ADC_MAX_VAL  1023 // max value 10-bit ADC for AVR


int main(void)
{
	ADC_Initialize(1, ADC_PRESCALER_128, ADC_VREF_SOURCE_EXTERNAL_AVCC, true);
	
	UART_Initialize(9600, true, false);
	
	FTOA_Set_String_Buffer(str_buf);
	
	
	// переменные для хранения температуры
	// -------------------------------------------------------------------------------
	// variables for temperature storage
	//
	float temp_to_kelvin_1, temp_to_celsius_1, temp_to_fahrenheit_1;	
	float temp_to_kelvin_2, temp_to_celsius_2, temp_to_fahrenheit_2;
	
	while (1)
	{
		// переключение АЦП на 1 канал и расчёт температуры
		// с помощью первого терморезистора
		// -------------------------------------------------------------------------------
		// switching the ADC to 1 channel and calculating
		// the temperature using the first thermistor
		//
		ADC_Set_Channel(1);
		temp_to_kelvin_1     = NTC_Get_Temperature_To_Kelvin(ADC_Get_Value_10bit(), ADC_MAX_VAL, U_REF, U_GEN, R_SERIAL, A_COEF, B_COEF, C_COEF);

		temp_to_celsius_1    = NTC_Convert_Temperature_Kelvin_To_Celsius(temp_to_kelvin_1);
		temp_to_fahrenheit_1 = NTC_Convert_Temperature_Kelvin_To_Fahrenheit(temp_to_kelvin_1);
		
		
		// переключение АЦП на 2 канал и расчёт температуры
		// с помощью второго терморезистора
		// -------------------------------------------------------------------------------
		// switching the ADC to 2 channel and calculating
		// the temperature using the second thermistor
		//
		ADC_Set_Channel(2);
		temp_to_kelvin_2     = NTC_Get_Temperature_To_Kelvin(ADC_Get_Value_10bit(), ADC_MAX_VAL, U_REF, U_GEN, R_SERIAL, A_COEF, B_COEF, C_COEF);

		temp_to_celsius_2    = NTC_Convert_Temperature_Kelvin_To_Celsius(temp_to_kelvin_2);
		temp_to_fahrenheit_2 = NTC_Convert_Temperature_Kelvin_To_Fahrenheit(temp_to_kelvin_2);
		
		
		UART_String_Transmit("1 Temp (*K) "); UART_StringLn_Transmit(FTOA_Float32_To_String(temp_to_kelvin_1,     3, 1));
		UART_String_Transmit("1 Temp (*C) "); UART_StringLn_Transmit(FTOA_Float32_To_String(temp_to_celsius_1,    3, 1));
		UART_String_Transmit("1 Temp (*F) "); UART_StringLn_Transmit(FTOA_Float32_To_String(temp_to_fahrenheit_1, 3, 1));
		UART_NEW_LINE;
		
		
		UART_String_Transmit("2 Temp (*K) "); UART_StringLn_Transmit(FTOA_Float32_To_String(temp_to_kelvin_2,     3, 1));
		UART_String_Transmit("2 Temp (*C) "); UART_StringLn_Transmit(FTOA_Float32_To_String(temp_to_celsius_2,    3, 1));
		UART_String_Transmit("2 Temp (*F) "); UART_StringLn_Transmit(FTOA_Float32_To_String(temp_to_fahrenheit_2, 3, 1));
		UART_NEW_LINE;
		
		
		_delay_ms(1000);
	}
}


