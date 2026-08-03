

#include "uart.h"
#include "simplehash.h"


// в данном примере в качестве входных данных используется массив байт
// длиной DATA_SIZE (8 байт), однако в качестве данных может быть строка,
// структура и другие сущности
// -------------------------------------------------------------------------------
// in this case, an array of bytes with a length of DATA_SIZE (8 bytes)
// is used as input data, however, a string, structure, and other entities
// can be used as data.
#define DATA_SIZE 8

char data[DATA_SIZE] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };


void print_data(void *data, uint16_t data_size)
{
	for (uint16_t i = 0; i < data_size; ++i)
	{
		UART_StringFmt_Transmit("%.2X ", ((uint8_t*)data)[i]);
	}
}

int main(void)
{
	UART_Initialize(9600, true, false);
	
	
	for (uint16_t i = 0; i < 256; ++i)
	{
		// с каждой итерацией изменяем данные
		// путём изменения ячейки массива с индексом '1'
		// -------------------------------------------------------------------------------
		// with each iteration, we change the data
		// by changing the array cell with index '1'
		data[1] = (uint8_t)i;
		
		
		UART_StringFmt_Transmit("\r\nData: "); print_data(data, DATA_SIZE); UART_StringFmt_Transmit("   | Hash: ");

		
		uint32_t hash = SimpleHash_Jenkins(data, DATA_SIZE);
		
		print_data(&hash, sizeof(uint32_t));
	}
	
	while (1)
	{
	}
}




