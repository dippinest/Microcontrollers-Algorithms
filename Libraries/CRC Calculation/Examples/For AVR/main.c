
#include "uart.h"
#include "itohexa.h"
#include "crc.h"

typedef struct
{
	char c;
	uint16_t u16_val_1;
	uint16_t u16_val_2;
	int64_t  i64_val;

} Data_t;

static char str_buf[16];


int main(void)
{
	UART_Initialize(9600, true, false);
	
	ITOHEXA_Set_String_Buffer(str_buf);
	
	
	Data_t d = { 'a', 232, 7633, 684567387573458769 };
	
	
	UART_StringLn_Transmit(
		ITOHEXA_32bitNum_To_HexString(
			CRC32_Get_Value(&d, sizeof(Data_t), 0xA0435757, 0xFF457436, true, false, 0x00446774), false));
	
	while (1)
	{
	}
}


