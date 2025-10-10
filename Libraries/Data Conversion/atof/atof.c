
#include "atof.h"


// ===============================================================================


float ATOF_String_To_Float32(char* string, uint8_t max_string_len)
{
	if (string == NULL || max_string_len == 0)
	{
		return 0.0;
	}
	
	float n = 0.0, pow = 1.0;

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
		if (string[i] < '0' || string[i] > '9' || i >= max_string_len)
		{
			break;
		}

		n *= 10;
		n += string[i] - '0';

		++i;
	}

	if (string[i] == '.')
	{
		++i;
	}

	while (1)
	{
		if (string[i] < '0' || string[i] > '9' || i >= max_string_len)
		{
			break;
		}

		n *= 10;
		n += string[i] - '0';

		pow *= 10;

		++i;
	}


	return (sign * n) / pow;
}




