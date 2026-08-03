
#include "uart.h"
#include "itoa.h"
#include "deftypes.h"


char string_buffer[32];


int main(void)
{
	UART_Initialize(9600, true, false);
	
	
	UART_String_Transmit("Converting 64-bits numbers to C-type string\r\n\r\n");
	
	
	UART_String_Transmit("Macro \"MIN_INT64_VAL\"     = "); UART_StringLn_Transmit(ITOA_Int64_To_String(string_buffer, MIN_INT64_VAL,      21));
	UART_String_Transmit("Macro \"MAX_INT64_VAL\"     = "); UART_StringLn_Transmit(ITOA_Int64_To_String(string_buffer, MAX_INT64_VAL,      21));
	
	UART_String_Transmit("Macro \"MIN_UINT64_VAL\"    = "); UART_StringLn_Transmit(ITOA_UInt64_To_String(string_buffer, MIN_UINT64_VAL,    21));
	UART_String_Transmit("Macro \"MAX_UINT64_VAL\"    = "); UART_StringLn_Transmit(ITOA_UInt64_To_String(string_buffer, MAX_UINT64_VAL,    21));
	
	UART_String_Transmit("Macro \"MIN_I64_VAL\"       = "); UART_StringLn_Transmit(ITOA_Int64_To_String(string_buffer, MIN_I64_VAL,        21));
	UART_String_Transmit("Macro \"MAX_I64_VAL\"       = "); UART_StringLn_Transmit(ITOA_Int64_To_String(string_buffer, MAX_I64_VAL,        21));
	
	UART_String_Transmit("Macro \"MIN_U64_VAL\"       = "); UART_StringLn_Transmit(ITOA_UInt64_To_String(string_buffer, MIN_U64_VAL,       21));
	UART_String_Transmit("Macro \"MAX_U64_VAL\"       = "); UART_StringLn_Transmit(ITOA_UInt64_To_String(string_buffer, MAX_U64_VAL,       21));
	
	UART_String_Transmit("Macro \"MIN_NATURAL64_VAL\" = "); UART_StringLn_Transmit(ITOA_UInt64_To_String(string_buffer, MIN_NATURAL64_VAL, 21));
	UART_String_Transmit("Macro \"MAX_NATURAL64_VAL\" = "); UART_StringLn_Transmit(ITOA_UInt64_To_String(string_buffer, MAX_NATURAL64_VAL, 21));
	
	UART_NEW_LINE;
	
	
	while (1)
	{
	}
}



