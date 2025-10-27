


#include <util/delay.h>

#include <string.h>

#include "uart.h"
#include "gost2814789.h"


// длина блока данных должна быть равна 8 байтам (64 битам)!
// -------------------------------------------------------------------------------
// data block length must be 8 bytes (64 bits)!
#define DATA_SIZE 8

char data_encode[DATA_SIZE];
char data_decode[DATA_SIZE];



// длина ключа должна быть равна 32 байтам (256 битам)!
// -------------------------------------------------------------------------------
// key length must be 32 bytes (256 bits)!
#define KEY_SIZE  32

const char key[KEY_SIZE]  = "Supersecret key!";



// длина инициализирующих векторов должна быть равна 8 байтам (64 битам)!
// -------------------------------------------------------------------------------
// length of the initializing vectors must be 8 bytes (64 bits)!
#define INITIAL_VECTOR_SIZE  8

char initial_vector_encode_64bit[INITIAL_VECTOR_SIZE];
char initial_vector_decode_64bit[INITIAL_VECTOR_SIZE];


void print_data(void *data, uint16_t data_size)
{
	for (uint16_t i = 0; i < data_size; ++i)
	{
		UART_StringFmt_Transmit("%02X ", ((uint8_t*)data)[i]);
	}
}



int main(void)
{
	UART_Initialize(9600, true, false);
	
	
	
	while (1)
	{
		// вычисляем гамму в режиме CTR шифрования
		//
		// -------------------------------------------------------------------------------
		// calculating the gamma in CTR encryption mode
		//
		GOST2814789_Encrypt_CTR(initial_vector_encode_64bit, data_encode, key);
		
		UART_String_Transmit("data encode = < "); print_data(data_encode, DATA_SIZE);
		
		
		
		// копируем data_encode в data_decode
		//
		// -------------------------------------------------------------------------------
		// copy data_encode to data_decode
		//
		memcpy(data_decode, data_encode, DATA_SIZE);
		
		
		// вычисляем гамму в режиме CTR дешифрования
		//
		// -------------------------------------------------------------------------------
		// calculating the gamma in CTR decryption mode
		//
		GOST2814789_Decrypt_CTR(initial_vector_decode_64bit, data_decode, key);
		
		UART_String_Transmit(">\r\ndata decode = < "); print_data(data_decode, DATA_SIZE); UART_String_Transmit(">\r\n\r\n");
		
		
		_delay_ms(1000);
	}
}




