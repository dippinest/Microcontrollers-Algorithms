

#include "base64.h"


// массив символов дл€ стандарта кодировани€ Base64
//
// ѕри желании вы можете заменить стандартные символы на свои
//
// -------------------------------------------------------------------------------
// array of characters for the Base64 encoding standard
//
// If you wish, you can replace the standard characters with your own
//
static const char _base64_char_array[] =
{
	'A', 'B', 'C', 'D',
	'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L',
	'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b',
	'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j',
	'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r',
	's', 't', 'u', 'v',
	'w', 'x', 'y', 'z',
	'0', '1', '2', '3',
	'4', '5', '6', '7',
	'8', '9', '+', '/'
};



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


uint32_t Base64_Encode(const void *input_data, uint32_t input_data_size, char *output_base64_buffer)
{
	uint8_t base64_char_array_index;

	uint32_t i = 0;
	uint32_t j = 0;

	while (input_data_size)
	{
		base64_char_array_index = ((uint8_t*)input_data)[i] >> 2;

		output_base64_buffer[j] = _base64_char_array[base64_char_array_index]; ++i; ++j;


		if (input_data_size > 2)
		{
			base64_char_array_index = ((((uint8_t*)input_data)[i - 1] & 0b11) << 4) | (((uint8_t*)input_data)[i] >> 4);

			output_base64_buffer[j] = _base64_char_array[base64_char_array_index]; ++i; ++j;


			base64_char_array_index = ((((uint8_t*)input_data)[i - 1] & 0b1111) << 2) | (((uint8_t*)input_data)[i] >> 6);

			output_base64_buffer[j] = _base64_char_array[base64_char_array_index]; ++j;


			base64_char_array_index = (((uint8_t*)input_data)[i] & 0b111111);

			output_base64_buffer[j] = _base64_char_array[base64_char_array_index]; ++i; ++j;


			input_data_size -= 3;
		}
		else if (input_data_size == 2)
		{
			base64_char_array_index = ((((uint8_t*)input_data)[i - 1] & 0b11) << 4) | (((uint8_t*)input_data)[i] >> 4);

			output_base64_buffer[j] = _base64_char_array[base64_char_array_index]; ++j;


			base64_char_array_index = ((((uint8_t*)input_data)[i] & 0b1111) << 2);

			output_base64_buffer[j] = _base64_char_array[base64_char_array_index]; ++j;


			output_base64_buffer[j] = '='; ++j;


			input_data_size -= 2;
		}
		else if (input_data_size == 1)
		{
			base64_char_array_index = ((((uint8_t*)input_data)[i - 1] & 0b11) << 4);

			output_base64_buffer[j] = _base64_char_array[base64_char_array_index]; ++j;


			output_base64_buffer[j] = '='; ++j;
			output_base64_buffer[j] = '='; ++j;


			input_data_size -= 1;
		}
	}

	output_base64_buffer[j] = '\0';


	return j;
}


uint32_t Base64_Decode(const char *input_base64_data, uint32_t input_base64_size, void *output_buffer)
{
	int16_t char_pos;

	uint32_t i = 0;
	uint32_t j = 0;


	while (input_base64_size)
	{
		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base64_char_array, sizeof(_base64_char_array), input_base64_data[i]);

		if (input_base64_data[i] == '=' || char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] = ((uint8_t)char_pos) << 2; ++i;


		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base64_char_array, sizeof(_base64_char_array), input_base64_data[i]);

		if (input_base64_data[i] == '=' || char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] |= ((uint8_t)char_pos) >> 4; ++i; ++j;




		if (input_base64_data[i] == '=')
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] = ((uint8_t)char_pos) << 4;


		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base64_char_array, sizeof(_base64_char_array), input_base64_data[i]);

		if (char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] |= ((uint8_t)char_pos) >> 2; ++i; ++j;




		if (input_base64_data[i] == '=')
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] = ((uint8_t)char_pos) << 6;


		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base64_char_array, sizeof(_base64_char_array), input_base64_data[i]);

		if (char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] |= ((uint8_t)char_pos); ++i; ++j;


		input_base64_size -= 4;
	}


	LABEL_EXIT:

	return j;
}





