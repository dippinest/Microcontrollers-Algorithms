

// ===============================================================================
//
// Эта библиотека реализует криптографический шифр Виженера
// в стандартном и модифицированном варианте.
// В стандартном варианте использует алфавит, содержащий символы ASCII
// (алфавит задаётся индивидуально и может содержать произвольный набор символов).
// В модифицированном варианте алгоритма работа производится с отдельными байтами,
// используя процедуры сложения или фунции XOR.
//
// В данной реализации шифра Виженера те символы в открытом тексте,
// которые отсутствуют в алфавите игнорируются и не шифруются. В тоже время такие
// символы в ключе шифрования влияют на процесс шифрования, что усиливает
// сложность дешифрования
//
// Кроме того, данные типы шифра Виженера можно использовать в потоковом режиме
//
//
// Внимание! Данный шифр в современных условиях не является криптостойким,
// библиотека была написана just for fun. Для серьёзных применений рекомендуется
// использовать более совершенные алгоритмы шифрования
//
// -------------------------------------------------------------------------------
//
// This library implements the Vigener cryptographic cipher
// in a standard and modified version.
// The standard version uses an alphabet containing ASCII characters
// (the alphabet is set individually and can contain any set of characters).
// In a modified version of the algorithm, work is performed with individual bytes
// using the addition or XOR function procedures.
//
// In this implementation of the Vigener cipher, those characters in
// the plaintext that are missing from the alphabet are ignored and not encrypted.
// At the same time, such characters in the encryption key affect the encryption
// process, which increases the complexity of decryption.
//
// In addition, these types of Vigener cipher can be used in streaming mode
//
//
// Attention! This cipher is not cryptographically secure in modern conditions,
// the library was written just for fun. For serious applications,
// it is recommended to use more advanced encryption algorithms.
//
// ===============================================================================


#ifndef VIGENERE_H_
#define VIGENERE_H_


#include <stdint.h>


typedef struct
{
	uint16_t key_char_counter;
	
	void *key;
	uint16_t key_size;
	
} Vigenere_Stream_Data_t;


Vigenere_Stream_Data_t Vigenere_Stream_Data_Create_Object(void *key, uint16_t key_size);


// ===============================================================================


uint16_t Vigenere_Standart_Encrypt(void *alphabet, uint8_t alphabet_size, void *data, uint16_t data_size, void *key, uint16_t key_size);

uint16_t Vigenere_Standart_Decrypt(void *alphabet, uint8_t alphabet_size, void *data, uint16_t data_size, void *key, uint16_t key_size);


uint16_t Vigenere_Standart_Stream_Encrypt(void *alphabet, uint8_t alphabet_size, void *data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream);

uint16_t Vigenere_Standart_Stream_Decrypt(void *alphabet, uint8_t alphabet_size, void *data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream);


// ===============================================================================


uint16_t Vigenere_Bytes_Encrypt(void *data, uint16_t data_size, void *key, uint16_t key_size);

uint16_t Vigenere_Bytes_Decrypt(void *data, uint16_t data_size, void *key, uint16_t key_size);


uint16_t Vigenere_Bytes_Stream_Encrypt(void *data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream);

uint16_t Vigenere_Bytes_Stream_Decrypt(void *data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream);


// ===============================================================================


// если в случае использования данной функции длина ключа будет равна или больше длины
// шифруемого сообщения, то шифрование будет происходить по методу Вернама
// -------------------------------------------------------------------------------
// if, in the case of using this function, the key length is equal to or greater
// than the length of the encrypted message, then encryption will be performed using the Vernam method
uint16_t Vigenere_XOR_Bytes_Encrypt(void *data, uint16_t data_size, void *key, uint16_t key_size);

uint16_t Vigenere_XOR_Bytes_Decrypt(void *data, uint16_t data_size, void *key, uint16_t key_size);


uint16_t Vigenere_XOR_Bytes_Stream_Encrypt(void *data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream);

uint16_t Vigenere_XOR_Bytes_Stream_Decrypt(void *data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream);


#endif






