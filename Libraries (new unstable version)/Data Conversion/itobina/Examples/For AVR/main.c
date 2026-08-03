
#include <util/delay.h>

#include "uart.h"
#include "itobina.h"


static char string_buffer[16];


int main(void)
{
	UART_Initialize(9600, true, false);
	
	uint8_t val = 0;
	
	
	while (1)
	{
		UART_StringFmt_Transmit("val = %d -> 0b%s\r\n", val, ITOBINA_8bitNum_To_BinString(string_buffer, val));
		
		++val;
		
		
		_delay_ms(500);
	}
}



