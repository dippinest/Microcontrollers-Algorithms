

#include "ftoa.h"



// ===============================================================================



char *FTOA_Float32_To_String(char *string_buffer, float number, const uint8_t num_int_digits, int8_t num_fract_digits, const char separator)
{
	// array of multipliers (up to 5 digits in the fractional part)
	static const uint32_t _pow10_u32_array[] = { 10, 100, 1000, 10000, 100000 };
		
		
	if (num_fract_digits <= 0)
	{
		num_fract_digits = 1;
	}
	if (num_fract_digits > (sizeof(_pow10_u32_array) / sizeof(uint32_t)))
	{
		num_fract_digits = (sizeof(_pow10_u32_array) / sizeof(uint32_t));
	}
	
	
	
	--num_fract_digits;
	

	typedef union
	{
		float fv;
		uint32_t dv;

	} _Num;
	

	_Num _num = { number };



	if (_num.dv == 0x80000000)
	{
		_num.dv = 0x00000000;
	}


	if (_num.dv == 0x7f800000 || _num.dv == 0xff800000)
	{
		if (_num.dv == 0xff800000)
		{
			string_buffer[0] = '-';
		}
		else
		{
			string_buffer[0] = '+';
		}


		string_buffer[1] = 'i';
		string_buffer[2] = 'n';
		string_buffer[3] = 'f';
		string_buffer[4] = '\0';
		

		return string_buffer;
	}


	if ((_num.dv & 0x7FFFFFFF) > 0x7F800000)
	{
		string_buffer[0] = 'n';
		string_buffer[1] = 'a';
		string_buffer[2] = 'n';
		string_buffer[3] = '\0';

		return string_buffer;
	}


	string_buffer[num_int_digits + num_fract_digits + 1] = '\0';
	
	
	int8_t fv_is_negative = 0;
	
	

	if (_num.dv & 0x80000000)
	{
		_num.dv &= ~(1UL << 31);
		
		fv_is_negative = 1;
	}


	int32_t int_part   = (int32_t)_num.fv;
	
	int32_t fract_part = (_num.fv - int_part) * _pow10_u32_array[num_fract_digits % (sizeof(_pow10_u32_array) / sizeof(int32_t))];
	
	int8_t i = (num_int_digits + num_fract_digits + 1);
	
	
	uint8_t rem;
	
	

	for (; i >= (num_int_digits + 1); --i)
	{
		rem = fract_part % 10;
		
		fract_part /= 10;
		
		string_buffer[i] = rem + '0';
	}
	
	
	string_buffer[i] = separator;
	
	--i;
	
	
	for (uint8_t j = 0; j < num_int_digits; ++j)
	{
		if (int_part != 0)
		{
			rem = int_part % 10;
			
			int_part /= 10;
			
			string_buffer[i] = rem + '0';
		}
		else
		{
			if (fv_is_negative)
			{
				if (j == 0)
				{
					string_buffer[i] = '0';
				}
				else
				{
					string_buffer[i] = '-';
					fv_is_negative = 0;
				}
			}
			else
			{
				if (j == 0)
				{
					string_buffer[i] = '0';
				}
				else
				{
					string_buffer[i] = ' ';
				}
			}
		}

		--i;
	}

	return string_buffer;
}




