
#include "atof.h"
#include "uart.h"


int main(void)
{
	UART_Initialize(9600, true, false);
	
	
	char str[] = " -12.345";
	
	float number = ATOF_String_To_Float32(str, 8);
	
	UART_StringFmt_Transmit("String: \"%s\" ---> Number: %f", str, number);
	
	while (1)
	{
	}
}




