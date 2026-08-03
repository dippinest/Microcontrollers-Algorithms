
#include <util/delay.h>

#include "uart.h"
#include "itoa.h"

char string_buffer[8];

int main(void)
{
	UART_Initialize(9600, true, false);
	
	int8_t i = 0;
	
	
	while (1)
	{
		UART_String_Transmit("Counter = "); UART_StringLn_Transmit( ITOA_Int8_To_String(string_buffer, i, 4) ); // 4 = 3 digits + sign '-'
		
		++i;
		
		
		_delay_ms(200);
	}
}



