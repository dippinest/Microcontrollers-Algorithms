

#include <util/delay.h>

#include "ftoa.h"
#include "uart.h"

char string_buffer[16];


int main(void)
{
	UART_Initialize(9600, true, false);
	
	
	float f = -5.0;
	
	while (1)
	{
		UART_StringLn_Transmit(FTOA_Float32_To_String(string_buffer, f, 5, 4, '.')); // 5 int sign = 4 digits + sign '-'
		
		f += 0.125;
		
		
		_delay_ms(200);
	}
}



