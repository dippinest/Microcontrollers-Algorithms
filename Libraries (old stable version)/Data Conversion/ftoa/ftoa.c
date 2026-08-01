
#include "ftoa.h"

static char  *_string_buffer = NULL; // buffer for output string


// array of multipliers (up to 7 digits in the fractional part)
static const uint32_t _pow10_u32_array[] = { 10, 100, 1000, 10000, 100000, 1000000, 10000000 };


// ===============================================================================


void FTOA_Set_String_Buffer(char *string_buffer_ptr)
{
	_string_buffer = string_buffer_ptr;
}

char *FTOA_Set_String_Buffer_To_Dynamic_Memory(const uint8_t string_buffer_size)
{
	_string_buffer = (char*)calloc(string_buffer_size, sizeof(char));
	
	return _string_buffer;
}

void FTOA_Delete_String_Buffer_From_Dynamic_Memory()
{
	free(_string_buffer);
	_string_buffer = NULL;
}


// ===============================================================================


char *FTOA_Get_String_Buffer_Ptr()
{
	return _string_buffer;
}


// ===============================================================================


char* FTOA_Float32_To_String(float val, int8_t num_int_digits, int8_t num_fract_digits)
{
	--num_fract_digits;

	typedef union
	{
		float fv;
		uint32_t dv;

	} _Val;

	_Val _v = { val };

	if (_v.dv == 0x80000000)
	{
		_v.dv = 0x00000000;
	}

	if (_v.dv == 0x7f800000 || _v.dv == 0xff800000)
	{
		if (_v.dv == 0xff800000)
		{
			_string_buffer[0] = '-';
		}
		else
		{
			_string_buffer[0] = '+';
		}

		_string_buffer[1] = 'i';
		_string_buffer[2] = 'n';
		_string_buffer[3] = 'f';
		_string_buffer[4] = '\0';

		return _string_buffer;
	}

	if (isnan(val))
	{
		_string_buffer[0] = 'n';
		_string_buffer[1] = 'a';
		_string_buffer[2] = 'n';
		_string_buffer[3] = '\0';

		return _string_buffer;
	}

	_string_buffer[num_int_digits + num_fract_digits + 1] = '\0';
	
	int8_t fv_is_negative = 0;

	if (_v.dv & 0x80000000)
	{
		_v.dv &= ~(1UL << 31);
		fv_is_negative = 1;
	}

	int32_t int_part   = (int32_t)_v.fv;
	int32_t fract_part = (_v.fv - int_part) * _pow10_u32_array[num_fract_digits % (sizeof(_pow10_u32_array) / sizeof(int32_t))];
	
	
	int8_t i = (num_int_digits + num_fract_digits + 1);
	
	uint8_t rem;

	for (; i >= (num_int_digits + 1); --i)
	{
		rem = fract_part % 10;
		fract_part /= 10;
		_string_buffer[i] = rem + '0';
	}
	
	_string_buffer[i] = '.';
	--i;
	
	for (uint8_t j = 0; j < num_int_digits; ++j)
	{
		if (int_part != 0)
		{
			rem = int_part % 10;
			int_part /= 10;
			_string_buffer[i] = rem + '0';
		}
		else
		{
			if (fv_is_negative)
			{
				if (j == 0)
				{
					_string_buffer[i] = '0';
				}
				else
				{
					_string_buffer[i] = '-';
					fv_is_negative = 0;
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


