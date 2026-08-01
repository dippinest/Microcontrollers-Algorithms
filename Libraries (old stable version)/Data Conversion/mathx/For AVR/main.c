
#include <util/delay.h>

#include "adc.h"
#include "uart.h"
#include "mathx.h"

int main(void)
{
	ADC_Initialize(0, ADC_PRESCALER_128, ADC_VREF_SOURCE_EXTERNAL_AVCC, true);
	
	uint16_t adc_val, rescaling_adc_val;
	
	
	UART_Initialize(9600, true, false);
	
	
	while (1)
	{
		adc_val = ADC_Get_Value_10bit();
		
		// линейно масштабируем значение АЦП из области (0 .. 1023) в область (0 .. 99)
		// -------------------------------------------------------------------------------
		// linearly scale the ADC value from the area (0 .. 1023) to the area (0 .. 99)
		rescaling_adc_val = MATHX_Scaling_UInt32(adc_val, 0, 1023, 0, 99);
		
		UART_StringFmt_Transmit("ADC value (%d) (0 .. 1023) -> (%d) (0 .. 99)\r\n", adc_val, rescaling_adc_val);
		
		_delay_ms(200);
	}
}


