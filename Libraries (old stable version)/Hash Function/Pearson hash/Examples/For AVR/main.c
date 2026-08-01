

#include "uart.h"
#include "pearsonhash.h"


// в данном примере в качестве входных данных используется массив байт
// длиной DATA_SIZE (8 байт), однако в качестве данных может быть строка,
// структура и другие сущности
// -------------------------------------------------------------------------------
// in this case, an array of bytes with a length of DATA_SIZE (8 bytes)
// is used as input data, however, a string, structure, and other entities
// can be used as data.
#define DATA_SIZE 8

char data[DATA_SIZE] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };


// в данном случае длина хэша будет равной 16 байт (128 бит)
// -------------------------------------------------------------------------------
// in this case, the hash size will be 16 bytes (128 bits)
#define HASH_SIZE  16

uint8_t hash[HASH_SIZE];


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

		
		PearsonHash_Get_Arbitrary_Size_Hash(data, DATA_SIZE, hash, HASH_SIZE);
		
		print_data(hash, HASH_SIZE);
	}
	
	while (1)
	{
	}
}





