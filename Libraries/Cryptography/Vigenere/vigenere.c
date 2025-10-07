
#include "vigenere.h"


static int16_t _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(const void* alphabet, const uint8_t alphabet_size, char b)
{
	for (int16_t i = 0; i < alphabet_size; ++i)
	{
		if (((char*)alphabet)[i] == b)
		{
			return i;
		}
	}

	return -1;
}


uint16_t Vigenere_Standart_Encrypt(void* alphabet, uint8_t alphabet_size, void* data, uint16_t data_size, void* key, uint16_t key_size)
{
	uint16_t i = 0;

	uint8_t new_data_char_pos = 0;


	for (i = 0; i < data_size; ++i)
	{
		int16_t data_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)data)[i]);

		int16_t key_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)key)[i % key_size]);


		if (data_char_pos >= 0 && key_char_pos >= 0)
		{
			new_data_char_pos = data_char_pos + key_char_pos;

			if (new_data_char_pos >= alphabet_size)
			{
				new_data_char_pos -= alphabet_size;
			}

			((char*)data)[i] = ((char*)alphabet)[new_data_char_pos];
		}
	}

	return i;
}


uint16_t Vigenere_Standart_Decrypt(void* alphabet, uint8_t alphabet_size, void* data, uint16_t data_size, void* key, uint16_t key_size)
{
	uint16_t i = 0;

	uint8_t new_data_char_pos = 0;


	for (i = 0; i < data_size; ++i)
	{
		int16_t data_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)data)[i]);

		int16_t key_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)key)[i % key_size]);


		if (data_char_pos >= 0 && key_char_pos >= 0)
		{
			new_data_char_pos = data_char_pos - key_char_pos;

			if (new_data_char_pos >= alphabet_size)
			{
				new_data_char_pos += alphabet_size;
			}

			((char*)data)[i] = ((char*)alphabet)[new_data_char_pos];
		}
	}

	return i;
}


uint16_t Vigenere_Bytes_Encrypt(void* data, uint16_t data_size, void* key, uint16_t key_size)
{
	uint16_t i = 0;

	for (; i < data_size; ++i)
	{
		((uint8_t*)data)[i] += ((uint8_t*)key)[i % key_size];
	}

	return i;
}


uint16_t Vigenere_Bytes_Decrypt(void* data, uint16_t data_size, void* key, uint16_t key_size)
{
	uint16_t i = 0;

	for (; i < data_size; ++i)
	{
		((uint8_t*)data)[i] -= ((uint8_t*)key)[i % key_size];
	}

	return i;
}


uint16_t Vigenere_XOR_Bytes_Encrypt(void* data, uint16_t data_size, void* key, uint16_t key_size)
{
	uint16_t i = 0;

	for (; i < data_size; ++i)
	{
		((uint8_t*)data)[i] ^= ((uint8_t*)key)[i % key_size];
	}

	return i;
}


uint16_t Vigenere_XOR_Bytes_Decrypt(void* data, uint16_t data_size, void* key, uint16_t key_size)
{
	return Vigenere_XOR_Bytes_Encrypt(data, data_size, key, key_size);
}






