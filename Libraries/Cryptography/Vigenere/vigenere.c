
#include "vigenere.h"


Vigenere_Stream_Data_t Vigenere_Stream_Data_Get_Object(void *key, uint16_t key_size)
{
	Vigenere_Stream_Data_t v_stream;
	
	v_stream.key_char_counter = 0;
	
	v_stream.key = key;
	v_stream.key_size = key_size;
	
	return v_stream;
}


// ===============================================================================


static int16_t _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(void* alphabet, uint8_t alphabet_size, char b)
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


// ===============================================================================


uint16_t Vigenere_Standart_Encrypt(void* alphabet, uint8_t alphabet_size, void* data, uint16_t data_size, void* key, uint16_t key_size)
{
	uint16_t i = 0;

	uint8_t new_data_char_pos = 0;
	
	
	int16_t data_char_pos, key_char_pos;


	for (i = 0; i < data_size; ++i)
	{
		data_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)data)[i]);

		key_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)key)[i % key_size]);


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
	
	
	int16_t data_char_pos, key_char_pos;


	for (i = 0; i < data_size; ++i)
	{
		data_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)data)[i]);

		key_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)key)[i % key_size]);


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



uint16_t Vigenere_Standart_Stream_Encrypt(void* alphabet, uint8_t alphabet_size, void* data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream)
{
	uint16_t i = 0;
	
	uint16_t key_char_counter = v_stream->key_char_counter;
	
	
	uint8_t new_data_char_pos = 0;
	
	int16_t data_char_pos, key_char_pos;
	

	for (i = 0; i < data_size; ++i)
	{
		data_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)data)[i]);


		key_char_counter = (i + (v_stream->key_char_counter) + 1) % (v_stream->key_size);

		key_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)(v_stream->key))[key_char_counter]);
		

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
	
	v_stream->key_char_counter = key_char_counter;

	return i;
}


uint16_t Vigenere_Standart_Stream_Decrypt(void* alphabet, uint8_t alphabet_size, void* data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream)
{
	uint16_t i = 0;
	
	uint16_t key_char_counter = v_stream->key_char_counter;
	
	
	uint8_t new_data_char_pos = 0;
	
	int16_t data_char_pos, key_char_pos;
	

	for (i = 0; i < data_size; ++i)
	{
		data_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)data)[i]);
		
		
		key_char_counter = (i + (v_stream->key_char_counter) + 1) % (v_stream->key_size);

		key_char_pos = _Vigenere_Find_Index_Of_First_Occurrence_Of_A_Byte(alphabet, alphabet_size, ((char*)(v_stream->key))[key_char_counter]);
		

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
	
	
	v_stream->key_char_counter = key_char_counter;

	return i;
}


// ===============================================================================


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



uint16_t Vigenere_Bytes_Stream_Encrypt(void* data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream)
{
	uint16_t i = 0;
	
	uint8_t new_data_char_pos = 0;
	

	for (; i < data_size; ++i)
	{
		new_data_char_pos = (i + (v_stream->key_char_counter)) % (v_stream->key_size);
		
		((uint8_t*)data)[i] += ((uint8_t*)(v_stream->key))[new_data_char_pos];
	}
	
	
	v_stream->key_char_counter = new_data_char_pos;

	return i;
}


uint16_t Vigenere_Bytes_Stream_Decrypt(void* data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream)
{
	uint16_t i = 0;
	
	uint8_t new_data_char_pos = 0;
	

	for (; i < data_size; ++i)
	{
		new_data_char_pos = (i + (v_stream->key_char_counter)) % (v_stream->key_size);
		
		((uint8_t*)data)[i] -= ((uint8_t*)(v_stream->key))[new_data_char_pos];
	}
	
	
	v_stream->key_char_counter = new_data_char_pos;

	return i;
}


// ===============================================================================


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



uint16_t Vigenere_XOR_Bytes_Stream_Encrypt(void* data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream)
{
	uint16_t i = 0;
	
	uint8_t new_data_char_pos = 0;
	

	for (; i < data_size; ++i)
	{
		new_data_char_pos = i + (v_stream->key_char_counter) % (v_stream->key_size);
		
		((uint8_t*)data)[i] ^= ((uint8_t*)(v_stream->key))[new_data_char_pos];
	}
	
	
	v_stream->key_char_counter = new_data_char_pos;

	return i;
}


uint16_t Vigenere_XOR_Bytes_Stream_Decrypt(void* data, uint16_t data_size, Vigenere_Stream_Data_t *v_stream)
{
	return Vigenere_XOR_Bytes_Stream_Encrypt(data, data_size, v_stream);
}




