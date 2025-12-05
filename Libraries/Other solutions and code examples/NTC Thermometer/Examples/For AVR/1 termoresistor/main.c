
#include <util/delay.h>

#include "ftoa.h"
#include "adc.h"
#include "ntc.h"
#include "uart.h"

static char str_buf[16];



// коэффициенты в этом примере рассчитаны для
// терморезистора MF52 NTC-MF52AT 100 кОм
// -------------------------------------------------------------------------------
// the coefficients in this example are calculated
// for the MF52 NTC-MF52AT 100 kOhm thermistor


// коэффициенты A, B и C
// -------------------------------------------------------------------------------
// A, B and C coefficients
//
#define A_COEF    1.044253909E-3
#define B_COEF    1.807648763E-4
#define C_COEF    1.498221745E-7


// сопротивление постоянного резистора в Омах (измеряется мультиметром)
// -------------------------------------------------------------------------------
// resistance of a constant resistor in Ohms (measured by a multimeter)
//
#define R_SERIAL     97500


// напряжение питания измерительной цепи (в Вольтах)
// -------------------------------------------------------------------------------
// supply voltage of the measuring circuit (in Volts)
//
#define U_GEN        5.07f


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
	
	float temp_to_kelvin, temp_to_celsius, temp_to_fahrenheit;
	
	while (1)
	{
		temp_to_kelvin     = NTC_Get_Temperature_To_Kelvin(ADC_Get_Value_10bit(), ADC_MAX_VAL, U_REF, U_GEN, R_SERIAL, A_COEF, B_COEF, C_COEF);

		temp_to_celsius    = NTC_Convert_Temperature_Kelvin_To_Celsius(temp_to_kelvin);
		temp_to_fahrenheit = NTC_Convert_Temperature_Kelvin_To_Fahrenheit(temp_to_kelvin);
		
		UART_String_Transmit("Temp (*K) "); UART_StringLn_Transmit(FTOA_Float32_To_String(temp_to_kelvin,     3, 1));
		UART_String_Transmit("Temp (*C) "); UART_StringLn_Transmit(FTOA_Float32_To_String(temp_to_celsius,    3, 1));
		UART_String_Transmit("Temp (*F) "); UART_StringLn_Transmit(FTOA_Float32_To_String(temp_to_fahrenheit, 3, 1));
		
		UART_NEW_LINE;
		
		_delay_ms(1000);
	}
}


