

#include <util/delay.h>

#include "ftoa.h"
#include "uart.h"

static char buffer[16];


int main(void)
{
	UART_Initialize(9600, true, false);
	
	FTOA_Set_String_Buffer(buffer);
	
	
	float f = -5.0;
	
	while (1)
	{
		UART_StringLn_Transmit(FTOA_Float32_To_String(f, 5, 4)); // 5 int sign = 4 digits + sign '-'
		
		f += 0.125;
		
		_delay_ms(200);
	}
}



