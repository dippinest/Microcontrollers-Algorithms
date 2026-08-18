

#include <util/delay.h>

#include "adc.h"
#include "ftoa.h"
#include "ntc.h"
#include "uart.h"



// коэффициенты в этом примере рассчитаны для
// терморезистора 10K3A1 10 кОм
// -------------------------------------------------------------------------------
// the coefficients in this example are calculated
// for the 10K3A1 10 kOm thermistor


// коэффициенты A, B и C
// -------------------------------------------------------------------------------
// A, B and C coefficients
//
#define A_COEF    1.129241e-3
#define B_COEF    2.341077e-4
#define C_COEF    8.767411e-8


// сопротивление постоянного резистора в Омах (измеряется мультиметром)
// -------------------------------------------------------------------------------
// resistance of a constant resistor in Ohms (measured by a multimeter)
//
#define R_SERIAL     99650


// напряжение питания измерительной цепи (в Вольтах)
// -------------------------------------------------------------------------------
// supply voltage of the measuring circuit (in Volts)
//
#define U_GEN        5.03f


// опорное напряжение АЦП (в Вольтах)
// -------------------------------------------------------------------------------
// ADC reference voltage (in Volts)
//
#define U_REF        5.00f


// максимальное цифровое значение АЦП
// -------------------------------------------------------------------------------
// maximum digital value of the ADC
//
#define ADC_MAX_VAL  1023 // max value 10-bit ADC for AVR





char string_buffer[16];


int main(void)
{
	ADC_Initialize(0, ADC_PRESCALER_128, ADC_VREF_SOURCE_EXTERNAL_AVCC, true);
	
	UART_Initialize(9600, true, false);
	


	// создание и инициализация структуры с данными для NTC термометра
	// -------------------------------------------------------------------------------
	// creating and initializing a structure with data for an NTC thermometer
	//
	NTC_Data_Struct_t ntc_data;
	
	ntc_data.U_ref    = U_REF;
	ntc_data.U_gen    = U_GEN;
	ntc_data.R_serial = R_SERIAL;
	
	ntc_data.A_coef   = A_COEF;
	ntc_data.B_coef   = B_COEF;
	ntc_data.C_coef   = C_COEF;
	
	ntc_data.adc_max_val = ADC_MAX_VAL;
	
	
	
	
	while (1)
	{
		// расчёт температуры в градусах Кельвина
		// -------------------------------------------------------------------------------
		// calculation of temperature in degrees Kelvin
		//
		const float temp_to_kelvin     = NTC_Get_Temperature_To_Kelvin(&ntc_data, ADC_Get_Value_10bit());


		// конвертация температуры из градусов Кельвина в градусы Цельсия и Фаренгейта
		// -------------------------------------------------------------------------------
		// conversion of temperature from Kelvin to Celsius and Fahrenheit
		//
		const float temp_to_celsius    = NTC_Convert_Temperature_Kelvin_To_Celsius(temp_to_kelvin);
		const float temp_to_fahrenheit = NTC_Convert_Temperature_Kelvin_To_Fahrenheit(temp_to_kelvin);
		
		
		
		
		UART_String_Transmit("Temp (*K) "); UART_StringLn_Transmit(FTOA_Float32_To_String(string_buffer, temp_to_kelvin,     3, 1, '.'));
		UART_String_Transmit("Temp (*C) "); UART_StringLn_Transmit(FTOA_Float32_To_String(string_buffer, temp_to_celsius,    3, 1, '.'));
		UART_String_Transmit("Temp (*F) "); UART_StringLn_Transmit(FTOA_Float32_To_String(string_buffer, temp_to_fahrenheit, 3, 1, '.'));
		
		UART_NEW_LINE;
		
		
		
		_delay_ms(1000);
	}
}




