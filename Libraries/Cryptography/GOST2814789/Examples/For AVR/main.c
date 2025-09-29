

#include "uart.h"
#include "gost2814789.h"


#define DATA_SIZE 64
#define KEY_SIZE  32

char       data[DATA_SIZE] = "This is my a supersecret data";
const char key[KEY_SIZE]   = "Supersecret key!";


void print_data(void* data, uint16_t data_size)
{
	for (uint16_t i = 0; i < data_size; ++i)
	{
		UART_StringFmt_Transmit("%X ", ((uint8_t*)data)[i]);
	}
}

int main(void)
{
	UART_Initialize(9600, true, false);
	
	
	UART_StringFmt_Transmit("\r\n\r\nOpen data:    "); print_data(data, DATA_SIZE);
	
	uint16_t encrypt_data_size = GOST2814789_Encrypt_ECB(data, DATA_SIZE, key);
	UART_StringFmt_Transmit("\r\n\r\nEncrypt data: "); print_data(data, encrypt_data_size);
	
	uint16_t decrypt_data_size = GOST2814789_Decrypt_ECB(data, encrypt_data_size, key);
	UART_StringFmt_Transmit("\r\n\r\nDecrypt data: "); print_data(data, decrypt_data_size);
	
	while (1)
	{
	}
}


