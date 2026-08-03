

#include "fixpoint.h"



// ===============================================================================



char* FIXPoint_Int16FP_To_String
(
	char *string_buffer,
	const uint8_t num_of_decimal_places_PFIXPoint,
	int16_t val, int8_t num_int_digits,
	int8_t num_fract_digits,
	const char empty_char,
	const char decimal_char_separator
)
{
	bool num_is_negative = false;
	

	if (val & 0x8000)
	{
		num_is_negative = true;
		
		val = ~val;
		
		++val;
	}


	int8_t i = 1 + num_int_digits + num_fract_digits;



	string_buffer[i] = '\0';
	
	--i;


	if (num_fract_digits > num_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (num_fract_digits - num_of_decimal_places_PFIXPoint); ++j)
		{
			string_buffer[i] = '0';
			
			--i;
		}
	}
	

	if (num_fract_digits < num_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (num_of_decimal_places_PFIXPoint - num_fract_digits); ++j)
		{
			val /= 10;
		}
	}


	for (uint8_t j = 0; j < num_of_decimal_places_PFIXPoint; ++j)
	{
		string_buffer[i] = (val % 10) + 48;
		val /= 10;
		--i;
	}


	string_buffer[i] = decimal_char_separator;
	
	--i;
	
	

	for (uint8_t j = 0; j < num_int_digits; ++j)
	{
		if (val != 0)
		{
			string_buffer[i] = (val % 10) + 48;
			
			val /= 10;
		}
		else
		{
			if (num_is_negative)
			{
				if (j == 0)
				{
					string_buffer[i] = '0';
				}
				else
				{
					string_buffer[i] = '-';
					
					num_is_negative = false;
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


char* FIXPoint_Int32FP_To_String
(
	char *string_buffer,
	const uint8_t num_of_decimal_places_PFIXPoint,
	int32_t val, int8_t num_int_digits,
	int8_t num_fract_digits,
	const char empty_char,
	const char decimal_char_separator
)
{
	bool num_is_negative = false;
	

	if (val & 0x80000000)
	{
		num_is_negative = true;
		
		val = ~val;
		
		++val;
	}
	

	int8_t i = 1 + num_int_digits + num_fract_digits;



	string_buffer[i] = '\0';
	
	--i;


	if (num_fract_digits > num_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (num_fract_digits - num_of_decimal_places_PFIXPoint); ++j)
		{
			string_buffer[i] = '0';
			
			--i;
		}
	}


	if (num_fract_digits < num_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (num_of_decimal_places_PFIXPoint - num_fract_digits); ++j)
		{
			val /= 10;
		}
	}


	for (uint8_t j = 0; j < num_of_decimal_places_PFIXPoint; ++j)
	{
		string_buffer[i] = (val % 10) + 48;
		
		val /= 10;
		
		--i;
	}
	
	

	string_buffer[i] = decimal_char_separator;
	
	--i;
	

	for (uint8_t j = 0; j < num_int_digits; ++j)
	{
		if (val != 0)
		{
			string_buffer[i] = (val % 10) + 48;
			
			val /= 10;
		}
		else
		{
			if (num_is_negative)
			{
				if (j == 0)
				{
					string_buffer[i] = '0';
				}
				else
				{
					string_buffer[i] = '-';
					
					num_is_negative = false;
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




#ifdef NUM_64BIT_SUPPORT

char* FIXPoint_Int64FP_To_String
(
	char *string_buffer,
	const uint8_t num_of_decimal_places_PFIXPoint,
	int64_t val,
	int8_t num_int_digits,
	int8_t num_fract_digits,
	const char empty_char,
	const char decimal_char_separator
)
{
	bool num_is_negative = false;


	if (val & 0x8000000000000000)
	{
		num_is_negative = true;
		
		val = ~val;
		
		++val;
	}


	int8_t i = 1 + num_int_digits + num_fract_digits;


	string_buffer[i] = '\0';
	
	--i;


	if (num_fract_digits > num_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (num_fract_digits - num_of_decimal_places_PFIXPoint); ++j)
		{
			string_buffer[i] = '0';
			
			--i;
		}
	}


	if (num_fract_digits < num_of_decimal_places_PFIXPoint)
	{
		for (uint8_t j = 0; j < (num_of_decimal_places_PFIXPoint - num_fract_digits); ++j)
		{
			val /= 10;
		}
	}


	for (uint8_t j = 0; j < num_of_decimal_places_PFIXPoint; ++j)
	{
		string_buffer[i] = (val % 10) + 48;
		
		val /= 10;
		
		--i;
	}



	string_buffer[i] = decimal_char_separator;
	
	--i;
	
	

	for (uint8_t j = 0; j < num_int_digits; ++j)
	{
		if (val != 0)
		{
			string_buffer[i] = (val % 10) + 48;
			
			val /= 10;
		}
		else
		{
			if (num_is_negative)
			{
				if (j == 0)
				{
					string_buffer[i] = '0';
				}
				else
				{
					string_buffer[i] = '-';
					
					num_is_negative = false;
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


#endif








