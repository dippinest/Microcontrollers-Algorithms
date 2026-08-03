
#include <util/delay.h>

#include "adc.h"
#include "uart.h"
#include "fixpoint.h"


char string_buffer[16];



int main(void)
{
	ADC_Initialize(0, ADC_PRESCALER_128, ADC_VREF_SOURCE_EXTERNAL_AVCC, true);
	
	// maximum value of the ADC voltage multiplied by 100 (to shift the decimal point to the end to the right)
	const int32_t FIXPOINT_MAX_VOLTAGE = 481; // (4.81 * 100)
	
	
	UART_Initialize(9600, true, false);
	
	
	
	while (1)
	{
		// working with fixed-type numbers
		int32_t FIXPOINT_voltage = (((FIXPOINT_MAX_VOLTAGE * 10000) / 1023) * ADC_Get_Value_10bit()) / 10000;
		
		UART_StringFmt_Transmit("Voltage = %s\r\n", FIXPoint_Int32FP_To_String(string_buffer, 2, FIXPOINT_voltage, 1, 2, ' ', '.'));
		
		
		_delay_ms(200);
	}
}






