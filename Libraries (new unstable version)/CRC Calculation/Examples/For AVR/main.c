
#include "uart.h"
#include "itohexa.h"
#include "crc.h"

char string_buffer[16];


typedef struct
{
	char c;
	uint16_t u16_val_1;
	uint16_t u16_val_2;
	int64_t  i64_val;

} Data_t;


int main(void)
{
	UART_Initialize(9600, true, false);
	
	
	Data_t d = { 'a', 232, 7633, 684567387573458769 };
		
	uint32_t crc32 = CRC32_Get_Value(&d, sizeof(Data_t), 0xA0435757, 0xFF457436, true, false, 0x00446774);	
	
	
	
	UART_StringLn_Transmit(
		ITOHEXA_32bitNum_To_HexString(string_buffer, crc32, false)
	);
	
	while (1)
	{
	}
}


