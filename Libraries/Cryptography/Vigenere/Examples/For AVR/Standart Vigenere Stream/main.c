

#include <string.h>

#include "uart.h"
#include "uart_async.h"

#include "vigenere.h"



// определения экземпляров структур, содержащих данные для работы
// шифра Виженера в потоковом режиме
//
// -------------------------------------------------------------------------------
// definitions of instances of structures containing data
// for the operation of the Vigenere cipher in streaming mode
//
Vigenere_Stream_Data_t v_stream_encrypt, v_stream_decrypt;


// алфавит, использующийся для шифра Виженера.
// Символы теста входных данных, если они отсутствуют в алфавите,
// шифроваться не будут (аналогично с символами ключа).
//
// В алфавите помимо буквенных символов можно определить символы цифр,
// знаков препинания и прочих печатных символов. Кроме того, порядок следования
// символов может быть произвольным. Чем разнообразнее и запутаннее алфавит,
// тем сложнее получится шифр.
//
// -------------------------------------------------------------------------------
// this alphabet used for the Vigеnere cipher.
// The characters of the input data test, if they are missing from
// the alphabet, will not be encrypted (similar to the characters of the key).
//
// In the alphabet, in addition to alphabetic characters, you can identify
// the symbols of numbers, punctuation marks, and other printed characters.
// In addition, the order of the characters can be arbitrary. The more diverse
// and confusing the alphabet, the more complex the cipher will be
//
char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

// ключ шифрования
//
// -------------------------------------------------------------------------------
// encryption key
//
char key[] = "This is my supersecret key!";




// определение приёмного буфера UART
//
// -------------------------------------------------------------------------------
// definition the UART receiving buffer
//
#define RX_BUFFER_SIZE 128

uint8_t data_buf[RX_BUFFER_SIZE];


// символ терминатора строки. Пока он не будет найден в строке,
// заполнение приёмного буфера будет продолжаться
//
// -------------------------------------------------------------------------------
// the character of the line terminator. Until it is found
// in the line, the filling of the receiving buffer will continue
//
#define TERMINATOR_SYMBOL ';'




// коллбэк приёмника UART. Когда приём строки закончится
// (встретиться символ терминатора), он прекратится и управление
// перейдёт данной функции
//
// -------------------------------------------------------------------------------
//
// the UART receiver's callback. When the line reception ends
// (the terminator character is encountered), it will stop and
// control will pass to this function
//
void send_buffer()
{
	// получение значения длины алфавита
	//
	// -------------------------------------------------------------------------------
	// getting the alphabet length value
	//
	uint16_t alphabet_size = strlen(alphabet);
	
	
	// получение значения количества принятых символов в буфере,
	// кроме символа терминатора
	//
	// -------------------------------------------------------------------------------
	// getting the value of the number of received characters in the buffer,
	// except for the terminator character
	//
	uint16_t data_size = UART_Async_Get_Reception_Buffer_Counter() - 1;
	
	
	
	UART_StringFmt_Transmit("Open data:    %s\r\n", data_buf);
	
	
	Vigenere_Standart_Stream_Encrypt(alphabet, alphabet_size, data_buf, data_size, &v_stream_encrypt);

	UART_StringFmt_Transmit("Encrypt data: %s\r\n", data_buf);


	Vigenere_Standart_Stream_Decrypt(alphabet, alphabet_size, data_buf, data_size, &v_stream_decrypt);

	UART_StringFmt_Transmit("Decrypt data: %s\r\n\r\n", data_buf);
	
	
	
	// после отработки коллбека снова включаем режим приёма данных в буфер
	//
	// -------------------------------------------------------------------------------
	// after working out the callback, we turn on the data receiving mode
	// in the buffer again
	//
	UART_Async_Start_Reception_Data_To_Buffer();
}


int main(void)
{
	UART_Initialize(9600, true, true);
	
	
	UART_Async_Set_Reception_Enable(true);
	
	UART_Async_Set_Reception_Buffer_Ptr(data_buf);
	UART_Async_Set_Reception_Buffer_Size(RX_BUFFER_SIZE);
	
	UART_Async_Set_Reception_Terminator(TERMINATOR_SYMBOL);
	UART_Async_Set_Reception_Terminator_Enable(true);
	
	UART_Async_Set_Reception_CallBack_Function(send_buffer);
	
	UART_Async_Start_Reception_Data_To_Buffer();
	
	
	// инициализация экземпляров структур, содержащих данные для работы
	// шифра Виженера в потоковом режиме
	//
	// -------------------------------------------------------------------------------
	// initialize of instances of structures containing data
	// for the operation of the Vigener cipher in streaming mode
	v_stream_encrypt = Vigenere_Stream_Data_Create_Object(key, strlen(key));
	v_stream_decrypt = Vigenere_Stream_Data_Create_Object(key, strlen(key));
	
	
	sei();
	

	while (1)
	{
	}
}





