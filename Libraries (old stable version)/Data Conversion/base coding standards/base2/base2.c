

#include "base2.h"


// массив символов для стандарта кодирования Base2
//
// При желании вы можете заменить стандартные символы на свои
//
// -------------------------------------------------------------------------------
// array of characters for the Base2 encoding standard
//
// If you wish, you can replace the standard characters with your own
//
static const char _base2_char_array[] = { '0', '1' };



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


uint32_t Base2_Encode(const void *input_data, uint32_t input_data_size, char *output_base2_buffer)
{
	uint8_t b;

	uint32_t i = 0;
	uint32_t j = 0;

	while (i < input_data_size)
	{
		b = ((uint8_t*)input_data)[i];

		for (int8_t k = 7; k >= 0; --k)
		{
			output_base2_buffer[j] = _base2_char_array[(b >> k) & 0b1]; ++j;
		}

		++i;
	}

	output_base2_buffer[j] = '\0';

	return j;
}


uint32_t Base2_Decode(const char *input_base2_buffer, uint32_t input_base2_buffer_size, void *output_data)
{
	uint8_t b;
	int16_t char_pos;

	uint32_t i = 0;
	uint32_t j = 0;

	while (j < input_base2_buffer_size)
	{
		b = 0;

		for (int8_t k = 7; k >= 0; --k)
		{
			char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base2_char_array, sizeof(_base2_char_array), input_base2_buffer[j]);

			if (char_pos == -1)
			{
				goto LABEL_EXIT;
			}

			b |= (char_pos << k); ++j;
		}

		((uint8_t*)output_data)[i] = b; ++i;
	}


	LABEL_EXIT:

	return i;
}





