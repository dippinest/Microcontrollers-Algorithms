
#include "fixpoint.h"

static char* _string_buffer = NULL; // buffer for string

static uint8_t  _number_of_decimal_places_PFIXPoint = 2; // default

static char     _empty_char = ' ';             // default
static char     _decimal_char_separator = '.'; // default

// ===============================================================================

void FIXPoint_Set_String_Buffer(char* string_buffer_ptr)
{
	_string_buffer = string_buffer_ptr;
}

char *FIXPoint_Set_String_Buffer_To_Dynamic_Memory(const uint8_t string_buffer_size)
{
	_string_buffer = (char*)calloc(string_buffer_size, sizeof(char));

	return _string_buffer;
}

void FIXPoint_Delete_String_Buffer_From_Dynamic_Memory()
{
	free(_string_buffer);
	_string_buffer = NULL;
}

// ===============================================================================

void FIXPoint_Set_Number_Of_Decimal_Places(const uint8_t number_of_decimal_places)
{
	_number_of_decimal_places_PFIXPoint = number_of_decimal_places;
}

void FIXPoint_Set_Empty_Char_Symbol(const char empty_char)
{
	_empty_char = empty_char;
}

void FIXPoint_Set_Decimal_Char_Separator(const char char_separator)
{
	_decimal_char_separator = char_separator;
}

char* FIXPoint_Get_String_Buffer_Ptr()
{
	return _string_buffer;
}

char FIXPoint_Get_Number_Of_Decimal_Places()
{
	return _number_of_decimal_places_PFIXPoint;
}

char FIXPoint_Get_Empty_Char_Symbol()
{
	return _empty_char;
}

char FIXPoint_Get_Decimal_Char_Separator()
{
	return _decimal_char_separator;
}

// ===============================================================================

char* FIXPoint_Int16FP_To_String(int16_t val, int8_t num_int_digits, int8_t num_fract_digits)
{
	bool num_is_negative = false;

	if (val & 0x8000)
	{
		num_is_negative = true;
		val = ~val;
		++val;
	}

	int8_t i = 1 + num_int_digits + num_fract_digits;

	_string_buffer[i] = '\0';
	--i;

	if (num_fract_digits > _number_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (num_fract_digits - _number_of_decimal_places_PFIXPoint); ++j)
		{
			_string_buffer[i] = '0';
			--i;
		}
	}

	if (num_fract_digits < _number_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (_number_of_decimal_places_PFIXPoint - num_fract_digits); ++j)
		{
			val /= 10;
		}
	}

	for (uint8_t j = 0; j < _number_of_decimal_places_PFIXPoint; ++j)
	{
		_string_buffer[i] = (val % 10) + 48;
		val /= 10;
		--i;
	}

	_string_buffer[i] = _decimal_char_separator;
	--i;

	for (uint8_t j = 0; j < num_int_digits; ++j)
	{
		if (val != 0)
		{
			_string_buffer[i] = (val % 10) + 48;
			val /= 10;
		}
		else
		{
			if (num_is_negative)
			{
				if (j == 0)
				{
					_string_buffer[i] = '0';
				}
				else
				{
					_string_buffer[i] = '-';
					num_is_negative = false;
				}
			}
			else
			{
				if (j == 0)
				{
					_string_buffer[i] = '0';
				}
				else
				{
					_string_buffer[i] = ' ';
				}
			}
		}

		--i;
	}

	return _string_buffer;
}

char* FIXPoint_Int32FP_To_String(int32_t val, int8_t num_int_digits, int8_t num_fract_digits)
{
	bool num_is_negative = false;

	if (val & 0x80000000)
	{
		num_is_negative = true;
		val = ~val;
		++val;
	}

	int8_t i = 1 + num_int_digits + num_fract_digits;

	_string_buffer[i] = '\0';
	--i;

	if (num_fract_digits > _number_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (num_fract_digits - _number_of_decimal_places_PFIXPoint); ++j)
		{
			_string_buffer[i] = '0';
			--i;
		}
	}

	if (num_fract_digits < _number_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (_number_of_decimal_places_PFIXPoint - num_fract_digits); ++j)
		{
			val /= 10;
		}
	}

	for (uint8_t j = 0; j < _number_of_decimal_places_PFIXPoint; ++j)
	{
		_string_buffer[i] = (val % 10) + 48;
		val /= 10;
		--i;
	}

	_string_buffer[i] = _decimal_char_separator;
	--i;

	for (uint8_t j = 0; j < num_int_digits; ++j)
	{
		if (val != 0)
		{
			_string_buffer[i] = (val % 10) + 48;
			val /= 10;
		}
		else
		{
			if (num_is_negative)
			{
				if (j == 0)
				{
					_string_buffer[i] = '0';
				}
				else
				{
					_string_buffer[i] = '-';
					num_is_negative = false;
				}
			}
			else
			{
				if (j == 0)
				{
					_string_buffer[i] = '0';
				}
				else
				{
					_string_buffer[i] = ' ';
				}
			}
		}

		--i;
	}

	return _string_buffer;
}


#ifdef NUM_64BIT_SUPPORT

char* FIXPoint_Int64FP_To_String(int64_t val, int8_t num_int_digits, int8_t num_fract_digits)
{
	bool num_is_negative = false;

	if (val & 0x8000000000000000)
	{
		num_is_negative = true;
		val = ~val;
		++val;
	}

	int8_t i = 1 + num_int_digits + num_fract_digits;

	_string_buffer[i] = '\0';
	--i;

	if (num_fract_digits > _number_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (num_fract_digits - _number_of_decimal_places_PFIXPoint); ++j)
		{
			_string_buffer[i] = '0';
			--i;
		}
	}

	if (num_fract_digits < _number_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (_number_of_decimal_places_PFIXPoint - num_fract_digits); ++j)
		{
			val /= 10;
		}
	}


	for (uint8_t j = 0; j < _number_of_decimal_places_PFIXPoint; ++j)
	{
		_string_buffer[i] = (val % 10) + 48;
		val /= 10;
		--i;
	}

	_string_buffer[i] = _decimal_char_separator;
	--i;

	for (uint8_t j = 0; j < num_int_digits; ++j)
	{
		if (val != 0)
		{
			_string_buffer[i] = (val % 10) + 48;
			val /= 10;
		}
		else
		{
			if (num_is_negative)
			{
				if (j == 0)
				{
					_string_buffer[i] = '0';
				}
				else
				{
					_string_buffer[i] = '-';
					num_is_negative = false;
				}
			}
			else
			{
				if (j == 0)
				{
					_string_buffer[i] = '0';
				}
				else
				{
					_string_buffer[i] = ' ';
				}
			}
		}

		--i;
	}

	return _string_buffer;
}

#endif




