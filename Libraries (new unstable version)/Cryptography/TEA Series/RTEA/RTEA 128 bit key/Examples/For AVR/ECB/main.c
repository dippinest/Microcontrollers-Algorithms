


#include "uart.h"
#include "rtea128bitkey.h"


// длина буфера данных должна быть кратна 8 байтам (64 битам)!
// -------------------------------------------------------------------------------
// data buffer length must be a multiple of 8 bytes (64 bits)!
#define DATA_SIZE 64

char data[DATA_SIZE] = "This is my a supersecret data";


// длина ключа должна быть равна 16 байтам (128 битам)!
// -------------------------------------------------------------------------------
// key length must be 16 bytes (256 bits)!
#define KEY_SIZE  16

const char key[KEY_SIZE]   = "Supersecret key";


void print_data(void *data, uint16_t data_size)
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
	
	uint16_t encrypt_data_size = RTEA128BitKey_Encrypt_ECB(data, DATA_SIZE, key);
	UART_StringFmt_Transmit("\r\n\r\nEncrypt data: "); print_data(data, encrypt_data_size);
	
	uint16_t decrypt_data_size = RTEA128BitKey_Decrypt_ECB(data, encrypt_data_size, key);
	UART_StringFmt_Transmit("\r\n\r\nDecrypt data: "); print_data(data, decrypt_data_size);
	
	while (1)
	{
	}
}


