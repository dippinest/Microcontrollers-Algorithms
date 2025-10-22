
#include <string.h>

#include "uart.h"
#include "vigenere.h"


// алфавит, использующийся для шифра Вижинера.
// Символы теста входных данных, если они отсутствуют в алфавите,
// шифроваться не будут (аналогично с символами ключа).
//
// В алфавите помимо буквенных символов можно определить символы цифр,
// знаков препинания и прочих печатных символов. Кроме того, порядок следования
// символов может быть произвольным. Чем разнообразнее и запутаннее алфавит,
// тем сложнее получится шифр.
//
// -------------------------------------------------------------------------------
// this alphabet used for the Vizhiner cipher.
// The characters of the input data test, if they are missing from
// the alphabet, will not be encrypted (similar to the characters of the key).
//
// In the alphabet, in addition to alphabetic characters, you can identify
// the symbols of numbers, punctuation marks, and other printed characters.
// In addition, the order of the characters can be arbitrary. The more diverse
// and confusing the alphabet, the more complex the cipher will be//
char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";


// ключ шифрования
//
// -------------------------------------------------------------------------------
// encryption key
//
char key[] = "Supersecret key!";

// данные для шифрования
//
// -------------------------------------------------------------------------------
// data for encryption
//
char data[] = "This is my a supersecret data";


int main(void)
{
	UART_Initialize(9600, true, false);
	
	// получение значения длины строк, с которыми работаем
	// -------------------------------------------------------------------------------
	// getting the length of the strings
	const uint16_t alphabet_size = strlen(alphabet);
	const uint16_t data_size = strlen(data);
	const uint16_t key_size = strlen(key);
	
	

	UART_StringFmt_Transmit("Open data:    %s\r\n\r\n", data);





	Vigenere_Standart_Encrypt(alphabet, alphabet_size, data, data_size, key, key_size);

	UART_StringFmt_Transmit("Encrypt data: %s\r\n\r\n", data);




	Vigenere_Standart_Decrypt(alphabet, alphabet_size, data, data_size, key, key_size);

	UART_StringFmt_Transmit("Decrypt data: %s\r\n\r\n", data);
	

	while (1)
	{
	}
}







