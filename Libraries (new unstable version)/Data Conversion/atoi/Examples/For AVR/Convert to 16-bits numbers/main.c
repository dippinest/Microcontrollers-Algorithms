
#include "atoi.h"
#include "uart.h"


int main(void)
{
	UART_Initialize(9600, true, false);
	
	
	char str[] = " -12345";
	
	int16_t number = ATOI_String_To_Int16(str, 8);
	
	UART_StringFmt_Transmit("String: \"%s\" ---> Number: %d", str, number);
	
	while (1)
	{
	}
}


