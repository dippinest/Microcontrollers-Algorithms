
#include <util/delay.h>

#include "uart.h"
#include "itohexa.h"

static char str_buf[8];


int main(void)
{
	UART_Initialize(9600, true, false);
	
	
	uint8_t i = 0;
	
	
	while (1)
	{
		UART_String_Transmit(ITOHEXA_8bitNum_To_HexString(str_buf, i, false)); UART_String_Transmit("; ");
		
		++i;
		
		
		_delay_ms(200);
	}
}


