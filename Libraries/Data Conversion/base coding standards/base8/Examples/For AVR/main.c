


#include <string.h>

#include "base8.h"
#include "uart.h"



// размер массива данных
//
// -------------------------------------------------------------------------------
// size of the data array
//
#define DATA_SIZE 128


// определение массивов для кодированных и декодированных данных
//
// -------------------------------------------------------------------------------
// defining arrays for encoded and decoded data
//
char encoded_data_buf[DATA_SIZE * 2]; // // overhead = 166%
char decoded_data_buf[DATA_SIZE];


// данные для кодирования
//
// -------------------------------------------------------------------------------
// data for encoding
//
char data[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";



int main(void)
{
	UART_Initialize(9600, true, false);


	UART_StringFmt_Transmit("Original data:\r\n\r\n%s", data);


	uint32_t encoded_data_size = Base8_Encode(data, strlen(data), encoded_data_buf);

	UART_StringFmt_Transmit("\r\n\r\n\r\nEncoded data:\r\n\r\n"); UART_String_Transmit(encoded_data_buf);


	uint32_t decoded_data_size = Base8_Decode(encoded_data_buf, encoded_data_size, decoded_data_buf);

	UART_StringFmt_Transmit("\r\n\r\n\r\nDecoded data:\r\n\r\n"); UART_String_Transmit(decoded_data_buf);
	
	
	if ((strlen(data) == decoded_data_size) && !memcmp(data, decoded_data_buf, decoded_data_size))
	{
		UART_String_Transmit("\r\n\r\n\r\n=========== The test passed successfully! ===========\r\n");
	}
	else
	{
		UART_String_Transmit("\r\n\r\n\r\n=========== TEST FAILED! ===========\r\n");
	}
	
	
	while (1)
	{
	}
}




