
#include "atoi.h"


// ===============================================================================


int8_t ATOI_String_To_Int8(char* string, uint8_t max_string_len)
{
	if (string == NULL || max_string_len == 0)
	{
		return 0;
	}
	
	int8_t  n = 0;
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


	return sign * n;
}


uint8_t ATOI_String_To_UInt8(char* string, uint8_t max_string_len)
{
	if (string == NULL || max_string_len == 0)
	{
		return 0;
	}
	
	uint8_t n = 0;
	uint8_t i = 0;

	while (1)
	{
		if (string[i] != ' ' || i >= max_string_len)
		{
			break;
		}

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


	return n;
}


int16_t ATOI_String_To_Int16(char* string, uint8_t max_string_len)
{
	if (string == NULL || max_string_len == 0)
	{
		return 0;
	}
	
	int16_t n = 0;
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


	return sign * n;
}


uint16_t ATOI_String_To_UInt16(char* string, uint8_t max_string_len)
{
	if (string == NULL || max_string_len == 0)
	{
		return 0;
	}
	
	uint16_t n = 0;
	uint8_t  i = 0;

	while (1)
	{
		if (string[i] != ' ' || i >= max_string_len)
		{
			break;
		}

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


	return n;
}


int32_t ATOI_String_To_Int32(char* string, uint8_t max_string_len)
{
	if (string == NULL || max_string_len == 0)
	{
		return 0;
	}
	
	int32_t n = 0;
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


	return sign * n;
}


uint32_t ATOI_String_To_UInt32(char* string, uint8_t max_string_len)
{
	if (string == NULL || max_string_len == 0)
	{
		return 0;
	}

	uint32_t n = 0;
	uint8_t  i = 0;

	while (1)
	{
		if (string[i] != ' ' || i >= max_string_len)
		{
			break;
		}

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


	return n;
}



#ifdef NUM_64BIT_SUPPORT


int64_t ATOI_String_To_Int64(char* string, uint8_t max_string_len)
{
	if (string == NULL || max_string_len == 0)
	{
		return 0;
	}
	
	int64_t n = 0;
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


	return sign * n;
}


uint64_t ATOI_String_To_UInt64(char* string, uint8_t max_string_len)
{
	if (string == NULL || max_string_len == 0)
	{
		return 0;
	}
	
	uint64_t n = 0;
	uint8_t  i = 0;

	while (1)
	{
		if (string[i] != ' ' || i >= max_string_len)
		{
			break;
		}

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


	return n;
}


#endif







