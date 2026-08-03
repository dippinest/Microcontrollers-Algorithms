
#include "itohexa.h"



// ===============================================================================


static const char _hex_digits_chars[] =
{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };


// ===============================================================================



char *ITOHEXA_8bitNum_To_HexString(char *string_buffer, uint8_t val, bool is_lower_case)
{
	for (int8_t i = 1; i >= 0; --i)
	{
		if (is_lower_case)
		{
			string_buffer[i] = (char)tolower(_hex_digits_chars[val & 0x0F]);
		}
		else
		{
			string_buffer[i] = _hex_digits_chars[val & 0x0F];
		}

		val >>= 4;
	}

	string_buffer[2] = '\0';
	
	return string_buffer;
}


char *ITOHEXA_16bitNum_To_HexString(char *string_buffer, uint16_t val, bool is_lower_case)
{
	for (int8_t i = 3; i >= 0; --i)
	{
		if (is_lower_case)
		{
			string_buffer[i] = (char)tolower(_hex_digits_chars[val & 0x0F]);
		}
		else
		{
			string_buffer[i] = _hex_digits_chars[val & 0x0F];
		}

		val >>= 4;
	}

	string_buffer[4] = '\0';
	
	return string_buffer;
}


char *ITOHEXA_32bitNum_To_HexString(char *string_buffer, uint32_t val, bool is_lower_case)
{
	for (int8_t i = 7; i >= 0; --i)
	{
		if (is_lower_case)
		{
			string_buffer[i] = (char)tolower(_hex_digits_chars[val & 0x0F]);
		}
		else
		{
			string_buffer[i] = _hex_digits_chars[val & 0x0F];
		}

		val >>= 4;
	}

	string_buffer[8] = '\0';
	
	return string_buffer;
}



#ifdef NUM_64BIT_SUPPORT

char *ITOHEXA_64bitNum_To_HexString(char *string_buffer, uint64_t val, bool is_lower_case)
{
	for (int8_t i = 15; i >= 0; --i)
	{
		if (is_lower_case)
		{
			string_buffer[i] = (char)tolower(_hex_digits_chars[val & 0x0F]);
		}
		else
		{
			string_buffer[i] = _hex_digits_chars[val & 0x0F];
		}

		val >>= 4;
	}

	string_buffer[16] = '\0';
	
	return string_buffer;
}


#endif




