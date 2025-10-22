
#include <string.h>

#include "uart.h"
#include "vigenere.h"


static void print_hex_data(char *data, uint16_t data_size)
{
	for (uint16_t i = 0; i < data_size; ++i)
	{
		UART_StringFmt_Transmit("%X ", data[i]);
	}
}


char key[] = "Supersecret key!";



char data[] = "This is my a supersecret data";


int main(void)
{
	UART_Initialize(9600, true, false);
	
	// получение значения длины строк, с которыми работаем, включая нуль-терминатор
	// -------------------------------------------------------------------------------
	// getting the length of the strings we are working with, including the null terminator
	const uint16_t data_size = strlen(data) + 1;
	const uint16_t key_size = strlen(key) + 1;
	
	
	UART_String_Transmit("Open data:    "); print_hex_data(data, data_size); UART_String_Transmit("\r\n\r\n");
	
	
	// если в случае использования данной функции длина ключа будет равна или больше длине
	// шифруемого сообщения, то шифрование будет происходить по методу Вернама
	// -------------------------------------------------------------------------------
	// if, in the case of using this function, the key length is equal to or greater
	// than the length of the encrypted message, then encryption will be performed using the Vernam method
	Vigenere_XOR_Bytes_Encrypt(data, data_size, key, key_size);



	UART_String_Transmit("Encrypt data: "); print_hex_data(data, data_size); UART_String_Transmit("\r\n\r\n");
	Vigenere_XOR_Bytes_Decrypt(data, data_size, key, key_size);

	UART_String_Transmit("Decrypt data: "); print_hex_data(data, data_size); UART_String_Transmit("\r\n\r\n");
	
	while (1)
	{
	}
}



