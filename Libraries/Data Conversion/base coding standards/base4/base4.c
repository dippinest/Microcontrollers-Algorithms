

#include "base32.h"


// массив символов дл€ стандарта кодировани€ Base4
//
// ѕри желании вы можете заменить стандартные символы на свои
//
// -------------------------------------------------------------------------------
// array of characters for the Base4 encoding standard
//
// If you wish, you can replace the standard characters with your own
//
static const char _base4_char_array[] = { '0', '1', '2', '3' };



static int16_t _Find_Index_Of_First_Occurrence_Of_A_Byte(const void *arr, const uint8_t arr_size, char b)
{
	for (int16_t i = 0; i < arr_size; ++i)
	{
		if (((char*)arr)[i] == b)
		{
			return i;
		}
	}

	return -1;
}


// ===============================================================================


uint32_t Base4_Encode(const void *input_data, uint32_t input_data_size, char *output_base4_buffer)
{
	uint32_t i = 0;
	uint32_t j = 0;

	while (i < input_data_size)
	{
		output_base4_buffer[j] = _base4_char_array[((uint8_t*)input_data)[i]  >> 6];         ++j;
		output_base4_buffer[j] = _base4_char_array[(((uint8_t*)input_data)[i] >> 4) & 0b11]; ++j;
		output_base4_buffer[j] = _base4_char_array[(((uint8_t*)input_data)[i] >> 2) & 0b11]; ++j;
		output_base4_buffer[j] = _base4_char_array[(((uint8_t*)input_data)[i])      & 0b11]; ++j;

		++i;
	}

	output_base4_buffer[j] = '\0';

	return j;
}


uint32_t Base4_Decode(const char *input_base4_buffer, uint32_t input_base4_buffer_size, void *output_data)
{
	int16_t char_pos;

	uint32_t i = 0;
	uint32_t j = 0;

	while (j < input_base4_buffer_size)
	{
		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base4_char_array, sizeof(_base4_char_array), input_base4_buffer[j]);

		if (char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_data)[i] = char_pos << 6; ++j;

		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base4_char_array, sizeof(_base4_char_array), input_base4_buffer[j]);

		if (char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_data)[i] |= char_pos << 4; ++j;

		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base4_char_array, sizeof(_base4_char_array), input_base4_buffer[j]);

		if (char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_data)[i] |= char_pos << 2; ++j;

		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base4_char_array, sizeof(_base4_char_array), input_base4_buffer[j]);

		if (char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_data)[i] |= char_pos; ++j; ++i;
	}


	LABEL_EXIT:

	return i;
}





