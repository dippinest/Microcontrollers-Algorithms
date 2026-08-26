

#include "fdpn.h"



// ===============================================================================



char *FDPN_Int16Base_Convert_Number_To_String
(
	char *string_buffer,
	
	int16_t number,
	
	const int8_t num_int_digits,
	const int8_t num_fract_digits,
	const char decimal_separator
)
{
	int8_t i = num_int_digits + num_fract_digits;

	if ((i == 0) || (num_int_digits < 0) || (num_fract_digits < 0))
	{
		string_buffer[i] = '\0';

		return string_buffer;
	}


	bool is_negative  = false;

	bool is_int16_min = false;



	string_buffer[i + 1] = '\0';


	
	if (number == -32768)
	{
		is_int16_min = true;

		number = 32767;
	}
	

	if (number < 0)
	{
		is_negative = true;

		--number;

		number = ~number;
	}


	while (i > num_int_digits)
	{
		string_buffer[i] = (number % 10) + '0';

		--i;

		number /= 10;


		if (is_int16_min && (i == (num_int_digits + num_fract_digits - 1)))
		{
			string_buffer[i + 1] = '8';
		}
	}



	if (num_fract_digits == 0)
	{
		string_buffer[i] = '\0';
	}
	else
	{
		string_buffer[i] = decimal_separator;
	}

	--i;



	while (i >= 0)
	{
		string_buffer[i] = (number % 10) + '0';

		--i;

		number /= 10;
	}



	i = 0;

	while ((string_buffer[i] == '0') && (string_buffer[i + 1] != decimal_separator))
	{
		string_buffer[i] = ' ';

		++i;
	}

	if ((i > 0) && (is_negative || is_int16_min))
	{
		string_buffer[i - 1] = '-';
	}


	return string_buffer;
}



int16_t FDPN_Int16Base_Convert_String_To_Number
(
	const char *string,
	
	const uint8_t max_string_len
)
{
	if (string == NULL || max_string_len == 0)
	{
		return 0;
	}
	

	int16_t number = 0;
	
	uint8_t i = 0;
	
	

	while (1)
	{
		if (string[i] != ' ' || i >= max_string_len)
		{
			break;
		}

		++i;
	}

	int8_t sign = 1;

	if (string[i] == '+')
	{
		++i;
	}

	if (string[i] == '-')
	{
		sign = -1;

		++i;
	}

	while (1)
	{
		if (((string[i] == '\0')) || (i >= max_string_len))
		{
			break;
		}

		if ((string[i] < '0') || (string[i] > '9'))
		{
			++i;

			continue;
		}

		number *= 10;
		number += string[i] - '0';

		++i;
	}


	return sign * number;
}



// ===============================================================================



char *FDPN_Int32Base_Convert_Number_To_String
(
	char *string_buffer,
	
	int32_t number,
	
	const int8_t num_int_digits,
	const int8_t num_fract_digits,
	const char decimal_separator
)
{
	int8_t i = num_int_digits + num_fract_digits;

	if ((i == 0) || (num_int_digits < 0) || (num_fract_digits < 0))
	{
		string_buffer[i] = '\0';

		return string_buffer;
	}


	bool is_negative = false;

	bool is_int16_min = false;



	string_buffer[i + 1] = '\0';



	if (number == -2147483648L)
	{
		is_int16_min = true;

		number = 2147483647L;
	}


	if (number < 0)
	{
		is_negative = true;

		--number;

		number = ~number;
	}


	while (i > num_int_digits)
	{
		string_buffer[i] = (number % 10) + '0';

		--i;

		number /= 10;


		if (is_int16_min && (i == (num_int_digits + num_fract_digits - 1)))
		{
			string_buffer[i + 1] = '8';
		}
	}



	if (num_fract_digits == 0)
	{
		string_buffer[i] = '\0';
	}
	else
	{
		string_buffer[i] = decimal_separator;
	}

	--i;



	while (i >= 0)
	{
		string_buffer[i] = (number % 10) + '0';

		--i;

		number /= 10;
	}



	i = 0;

	while ((string_buffer[i] == '0') && (string_buffer[i + 1] != decimal_separator))
	{
		string_buffer[i] = ' ';

		++i;
	}

	if ((i > 0) && (is_negative || is_int16_min))
	{
		string_buffer[i - 1] = '-';
	}


	return string_buffer;
}


int32_t FDPN_Int32Base_Convert_String_To_Number
(
	const char *string,
	
	const uint8_t max_string_len
)
{
	if ((string == NULL) || (max_string_len == 0))
	{
		return 0;
	}


	int32_t number = 0;
	
	uint8_t i = 0;



	while (1)
	{
		if ((string[i] != ' ') || (i >= max_string_len))
		{
			break;
		}

		++i;
	}

	int8_t sign = 1;

	if (string[i] == '+')
	{
		++i;
	}

	if (string[i] == '-')
	{
		sign = -1;

		++i;
	}

	while (1)
	{
		if (((string[i] == '\0')) || (i >= max_string_len))
		{
			break;
		}

		if ((string[i] < '0') || (string[i] > '9'))
		{
			++i;

			continue;
		}

		number *= 10;
		number += string[i] - '0';

		++i;
	}


	return sign * number;
}



// ===============================================================================





#ifdef NUM_64BIT_SUPPORT



char *FDPN_Int64Base_Convert_Number_To_String
(
	char *string_buffer,
	
	int64_t number,
	
	const int8_t num_int_digits,
	const int8_t num_fract_digits,
	const char decimal_separator
)
{
	int8_t i = num_int_digits + num_fract_digits;

	if ((i == 0) || (num_int_digits < 0) || (num_fract_digits < 0))
	{
		string_buffer[i] = '\0';

		return string_buffer;
	}


	bool is_negative = false;

	bool is_int16_min = false;



	string_buffer[i + 1] = '\0';



	if (number == LLONG_MIN)
	{
		is_int16_min = true;

		number = LLONG_MAX;
	}


	if (number < 0)
	{
		is_negative = true;

		--number;

		number = ~number;
	}


	while (i > num_int_digits)
	{
		string_buffer[i] = (number % 10) + '0';

		--i;

		number /= 10;


		if (is_int16_min && (i == (num_int_digits + num_fract_digits - 1)))
		{
			string_buffer[i + 1] = '8';
		}
	}



	if (num_fract_digits == 0)
	{
		string_buffer[i] = '\0';
	}
	else
	{
		string_buffer[i] = decimal_separator;
	}

	--i;



	while (i >= 0)
	{
		string_buffer[i] = (number % 10) + '0';

		--i;

		number /= 10;
	}



	i = 0;

	while ((string_buffer[i] == '0') && (string_buffer[i + 1] != decimal_separator))
	{
		string_buffer[i] = ' ';

		++i;
	}

	if ((i > 0) && (is_negative || is_int16_min))
	{
		string_buffer[i - 1] = '-';
	}


	return string_buffer;
}


int64_t FDPN_Int64Base_Convert_String_To_Number
(
	const char *string,
	
	const uint8_t max_string_len
)
{
	if ((string == NULL) || (max_string_len == 0))
	{
		return 0;
	}


	int64_t number = 0;
	
	uint8_t i = 0;



	while (1)
	{
		if ((string[i] != ' ') || (i >= max_string_len))
		{
			break;
		}

		++i;
	}

	int8_t sign = 1;

	if (string[i] == '+')
	{
		++i;
	}

	if (string[i] == '-')
	{
		sign = -1;

		++i;
	}

	while (1)
	{
		if (((string[i] == '\0')) || (i >= max_string_len))
		{
			break;
		}

		if ((string[i] < '0') || (string[i] > '9'))
		{
			++i;

			continue;
		}

		number *= 10;
		number += string[i] - '0';

		++i;
	}


	return sign * number;
}


#endif





