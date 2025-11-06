

#include "base32.h"


// массив символов дл€ стандарта кодировани€ Base32
//
// ѕри желании вы можете заменить стандартные символы на свои
//
// -------------------------------------------------------------------------------
// array of characters for the Base32 encoding standard
//
// If you wish, you can replace the standard characters with your own
//
static const char _base32_char_array[] =
{
	'A', 'B', 'C', 'D',
	'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L',
	'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X',
	'Y', 'Z', '2', '3',
	'4', '5', '6', '7'
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


uint32_t Base32_Encode(const void *input_data, uint32_t input_data_size, char *output_base32_buffer)
{
	uint8_t base32_char_array_index;

	uint32_t i = 0;
	uint32_t j = 0;


	while (input_data_size)
	{
		base32_char_array_index = ((uint8_t*)input_data)[i] >> 3;

		output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++i; ++j;


		base32_char_array_index = ((((uint8_t*)input_data)[i - 1] & 0b111) << 2) | (((uint8_t*)input_data)[i] >> 6);

		output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++j;


		if (input_data_size > 4)
		{
			base32_char_array_index = ((((uint8_t*)input_data)[i] & 0b111111) >> 1);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++i; ++j;


			base32_char_array_index = ((((uint8_t*)input_data)[i - 1] & 0b1) << 4) | (((uint8_t*)input_data)[i] >> 4);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++i; ++j;


			base32_char_array_index = ((((uint8_t*)input_data)[i - 1] & 0b1111) << 1) | (((uint8_t*)input_data)[i] >> 7);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++j;


			base32_char_array_index = ((((uint8_t*)input_data)[i] & 0b1111111) >> 2);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++i; ++j;


			base32_char_array_index = ((((uint8_t*)input_data)[i - 1] & 0b11) << 3) | (((uint8_t*)input_data)[i] >> 5);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++j;


			base32_char_array_index = (((uint8_t*)input_data)[i] & 0b11111);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++i; ++j;


			input_data_size -= 5;
		}
		else if (input_data_size == 4)
		{
			base32_char_array_index = ((((uint8_t*)input_data)[i] & 0b111111) >> 1);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++i; ++j;


			base32_char_array_index = ((((uint8_t*)input_data)[i - 1] & 0b1) << 4) | (((uint8_t*)input_data)[i] >> 4);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++i; ++j;


			base32_char_array_index = ((((uint8_t*)input_data)[i - 1] & 0b1111) << 1) | (((uint8_t*)input_data)[i] >> 7);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++j;


			base32_char_array_index = ((((uint8_t*)input_data)[i] & 0b1111111) >> 2);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++j;


			base32_char_array_index = ((((uint8_t*)input_data)[i] & 0b11) << 3);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++j;


			output_base32_buffer[j] = '='; ++j;



			input_data_size -= 4;
		}
		else if (input_data_size == 3)
		{
			base32_char_array_index = ((((uint8_t*)input_data)[i] & 0b111111) >> 1);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++i; ++j;


			base32_char_array_index = ((((uint8_t*)input_data)[i - 1] & 0b1) << 4) | (((uint8_t*)input_data)[i] >> 4);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++j;


			base32_char_array_index = ((((uint8_t*)input_data)[i] & 0b1111) << 1);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++j;


			output_base32_buffer[j] = '='; ++j;
			output_base32_buffer[j] = '='; ++j;
			output_base32_buffer[j] = '='; ++j;



			input_data_size -= 3;
		}
		else if (input_data_size == 2)
		{
			base32_char_array_index = ((((uint8_t*)input_data)[i] & 0b111111) >> 1);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++j;


			base32_char_array_index = ((((uint8_t*)input_data)[i] & 0b1) << 4);

			output_base32_buffer[j] = _base32_char_array[base32_char_array_index]; ++j;


			output_base32_buffer[j] = '='; ++j;
			output_base32_buffer[j] = '='; ++j;
			output_base32_buffer[j] = '='; ++j;
			output_base32_buffer[j] = '='; ++j;



			input_data_size -= 2;
		}
		else if (input_data_size == 1)
		{
			output_base32_buffer[j] = '='; ++j;
			output_base32_buffer[j] = '='; ++j;
			output_base32_buffer[j] = '='; ++j;
			output_base32_buffer[j] = '='; ++j;
			output_base32_buffer[j] = '='; ++j;
			output_base32_buffer[j] = '='; ++j;



			input_data_size -= 1;
		}
	}

	output_base32_buffer[j] = '\0';


	return j;
}


uint32_t Base32_Decode(const char *input_base32_data, uint32_t input_base32_size, void *output_buffer)
{
	int16_t char_pos;

	uint32_t i = 0;
	uint32_t j = 0;


	while (input_base32_size)
	{
		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base32_char_array, sizeof(_base32_char_array), input_base32_data[i]);

		if (input_base32_data[i] == '=' || char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] = ((uint8_t)char_pos) << 3; ++i;


		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base32_char_array, sizeof(_base32_char_array), input_base32_data[i]);

		if (input_base32_data[i] == '=' || char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] |= ((uint8_t)char_pos) >> 2; ++i; ++j;



		if (input_base32_data[i] == '=')
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] = ((uint8_t)char_pos) << 6;


		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base32_char_array, sizeof(_base32_char_array), input_base32_data[i]);

		if (char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] |= ((uint8_t)char_pos) << 1; ++i;



		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base32_char_array, sizeof(_base32_char_array), input_base32_data[i]);

		if (input_base32_data[i] == '=' || char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] |= ((uint8_t)char_pos) >> 4; ++i; ++j;



		if (input_base32_data[i] == '=')
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] = ((uint8_t)char_pos) << 4;

		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base32_char_array, sizeof(_base32_char_array), input_base32_data[i]);

		if (char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] |= ((uint8_t)char_pos) >> 1; ++i; ++j;



		if (input_base32_data[i] == '=')
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] = ((uint8_t)char_pos) << 7;


		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base32_char_array, sizeof(_base32_char_array), input_base32_data[i]);

		if (char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] |= ((uint8_t)char_pos) << 2; ++i;


		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base32_char_array, sizeof(_base32_char_array), input_base32_data[i]);

		if (input_base32_data[i] == '=' || char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] |= ((uint8_t)char_pos) >> 3; ++i; ++j;



		if (input_base32_data[i] == '=')
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] = ((uint8_t)char_pos) << 5;


		char_pos = _Find_Index_Of_First_Occurrence_Of_A_Byte(_base32_char_array, sizeof(_base32_char_array), input_base32_data[i]);

		if (input_base32_data[i] == '=' || char_pos == -1)
		{
			goto LABEL_EXIT;
		}

		((uint8_t*)output_buffer)[j] |= ((uint8_t)char_pos); ++i; ++j;


		input_base32_size -= 5;
	}


	LABEL_EXIT:

	return j;
}





