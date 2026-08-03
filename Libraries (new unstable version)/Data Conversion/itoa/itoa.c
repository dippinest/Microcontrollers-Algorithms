
#include "itoa.h"



// ===============================================================================



char *ITOA_UInt8_To_String_Without_Alignment(char *string_buffer, uint8_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';
	

	while (num_of_chars)
	{
		--num_of_chars;
		
		string_buffer[num_of_chars] = (val % 10) + '0';
		
		val /= 10;
	}
	

	return string_buffer;
}


char *ITOA_UInt16_To_String_Without_Alignment(char *string_buffer, uint16_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';


	while (num_of_chars)
	{
		--num_of_chars;
		
		string_buffer[num_of_chars] = (val % 10) + '0';
		
		val /= 10;
	}
	

	return string_buffer;
}


char *ITOA_UInt32_To_String_Without_Alignment(char *string_buffer, uint32_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';


	while (num_of_chars)
	{
		--num_of_chars;
		
		string_buffer[num_of_chars] = (val % 10) + '0';
		
		val /= 10;
	}


	return string_buffer;
}



#ifdef NUM_64BIT_SUPPORT

char *ITOA_UInt64_To_String_Without_Alignment(char *string_buffer, uint64_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';
	

	while (num_of_chars)
	{
		--num_of_chars;
		
		string_buffer[num_of_chars] = (val % 10) + '0';
		
		val /= 10;
	}
	

	return string_buffer;
}

#endif



// ===============================================================================



char *ITOA_Int8_To_String(char *string_buffer, int8_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';
	

	if (val == -128)
	{
		string_buffer[num_of_chars - 1] = '8';
		string_buffer[num_of_chars - 2] = '2';
		string_buffer[num_of_chars - 3] = '1';
		string_buffer[num_of_chars - 4] = '-';


		for (int8_t i = num_of_chars - 5; i >= 0; --i)
		{
			string_buffer[i] = ' ';
		}


		return string_buffer;
	}


	uint8_t sign = (val < 0) ? 1 : 0;


	if (sign)
	{
		--val;
		
		val = ~val;
	}


	int8_t i = num_of_chars - 1;


	while(i >= 0)
	{
		string_buffer[i] = (val % 10) + '0';
		
		--i;
		
		val /= 10;
		

		if (val == 0)
		{
			break;
		}
	}


	if (sign)
	{
		string_buffer[i] = '-';
		
		--i;
	}
	

	while (i >= 0)
	{
		string_buffer[i] = ' ';
		
		--i;
	}
	

	return string_buffer;
}


char *ITOA_UInt8_To_String(char *string_buffer, uint8_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';

	int8_t i = num_of_chars - 1;
	

	while(i >= 0)
	{
		string_buffer[i] = (val % 10) + '0';
		
		--i;
		
		val /= 10;
		

		if (val == 0)
		{
			break;
		}
	}
	

	while (i >= 0)
	{
		string_buffer[i] = ' ';
		
		--i;
	}


	return string_buffer;
}


char *ITOA_Int16_To_String(char *string_buffer, int16_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';
	

	if (val == -32768)
	{
		string_buffer[num_of_chars - 1] = '8';
		string_buffer[num_of_chars - 2] = '6';
		string_buffer[num_of_chars - 3] = '7';
		string_buffer[num_of_chars - 4] = '2';
		string_buffer[num_of_chars - 5] = '3';
		string_buffer[num_of_chars - 6] = '-';


		for (int8_t i = num_of_chars - 7; i >= 0; --i)
		{
			string_buffer[i] = ' ';
		}
		

		return string_buffer;
	}


	uint8_t sign = (val < 0) ? 1 : 0;


	if (sign)
	{
		--val;
		
		val = ~val;
	}
	

	int8_t i = num_of_chars - 1;


	while(i >= 0)
	{
		string_buffer[i] = (val % 10) + '0';
		
		--i;
		
		val /= 10;
		

		if (val == 0)
		{
			break;
		}
	}
	

	if (sign)
	{
		string_buffer[i] = '-';
		
		--i;
	}


	while (i >= 0)
	{
		string_buffer[i] = ' ';
		
		--i;
	}
	

	return string_buffer;
}


char *ITOA_UInt16_To_String(char *string_buffer, uint16_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';

	int8_t i = num_of_chars - 1;
	

	while(i >= 0)
	{
		string_buffer[i] = (val % 10) + '0';
		
		--i;
		
		val /= 10;
		

		if (val == 0)
		{
			break;
		}
	}


	while (i >= 0)
	{
		string_buffer[i] = ' ';
		
		--i;
	}
	

	return string_buffer;
}


char *ITOA_Int32_To_String(char *string_buffer, int32_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';
	

	if (val == -2147483648L)
	{
		string_buffer[num_of_chars - 1]  = '8';
		string_buffer[num_of_chars - 2]  = '4';
		string_buffer[num_of_chars - 3]  = '6';
		string_buffer[num_of_chars - 4]  = '3';
		string_buffer[num_of_chars - 5]  = '8';
		string_buffer[num_of_chars - 6]  = '4';
		string_buffer[num_of_chars - 7]  = '7';
		string_buffer[num_of_chars - 8]  = '4';
		string_buffer[num_of_chars - 9]  = '1';
		string_buffer[num_of_chars - 10] = '2';
		string_buffer[num_of_chars - 11] = '-';


		for (int8_t i = num_of_chars - 12; i >= 0; --i)
		{
			string_buffer[i] = ' ';
		}
		

		return string_buffer;
	}
	

	uint8_t sign = (val < 0) ? 1 : 0;


	if (sign)
	{
		--val;
		
		val = ~val;
	}


	int8_t i = num_of_chars - 1;


	while(i >= 0)
	{
		string_buffer[i] = (val % 10) + '0';
		
		--i;
		
		val /= 10;
		

		if (val == 0)
		{
			break;
		}
	}


	if (sign)
	{
		string_buffer[i] = '-';
		
		--i;
	}


	while (i >= 0)
	{
		string_buffer[i] = ' ';
		
		--i;
	}
	

	return string_buffer;
}


char *ITOA_UInt32_To_String(char *string_buffer, uint32_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';

	int8_t i = num_of_chars - 1;


	while(i >= 0)
	{
		string_buffer[i] = (val % 10) + '0';
		
		--i;
		
		val /= 10;
		

		if (val == 0)
		{
			break;
		}
	}


	while (i >= 0)
	{
		string_buffer[i] = ' ';
		
		--i;
	}
	

	return string_buffer;
}




#ifdef NUM_64BIT_SUPPORT

#include <limits.h>


char *ITOA_Int64_To_String(char *string_buffer, int64_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';
	

	if (val == LLONG_MIN)
	{
		string_buffer[num_of_chars - 1]  = '8';
		string_buffer[num_of_chars - 2]  = '0';
		string_buffer[num_of_chars - 3]  = '8';
		string_buffer[num_of_chars - 4]  = '5';
		string_buffer[num_of_chars - 5]  = '7';
		string_buffer[num_of_chars - 6]  = '7';
		string_buffer[num_of_chars - 7]  = '4';
		string_buffer[num_of_chars - 8]  = '5';
		string_buffer[num_of_chars - 9]  = '8';
		string_buffer[num_of_chars - 10] = '6';
		string_buffer[num_of_chars - 11] = '3';
		string_buffer[num_of_chars - 12] = '0';
		string_buffer[num_of_chars - 13] = '2';
		string_buffer[num_of_chars - 14] = '7';
		string_buffer[num_of_chars - 15] = '3';
		string_buffer[num_of_chars - 16] = '3';
		string_buffer[num_of_chars - 17] = '2';
		string_buffer[num_of_chars - 18] = '2';
		string_buffer[num_of_chars - 19] = '9';
		string_buffer[num_of_chars - 20] = '-';


		for (int8_t i = num_of_chars - 21; i >= 0; --i)
		{
			string_buffer[i] = ' ';
		}
		

		return string_buffer;
	}
	

	uint8_t sign = (val < 0) ? 1 : 0;


	if (sign)
	{
		--val;
		
		val = ~val;
	}


	int8_t i = num_of_chars - 1;


	while(i >= 0)
	{
		string_buffer[i] = (val % 10) + '0';
		
		--i;
		
		val /= 10;


		if (val == 0)
		{
			break;
		}
	}


	if (sign)
	{
		string_buffer[i] = '-';
		
		--i;
	}
	

	while (i >= 0)
	{
		string_buffer[i] = ' ';
		
		--i;
	}
	

	return string_buffer;
}


char *ITOA_UInt64_To_String(char *string_buffer, uint64_t val, int8_t num_of_chars)
{
	string_buffer[num_of_chars] = '\0';

	int8_t i = num_of_chars - 1;


	while(i >= 0)
	{
		string_buffer[i] = (val % 10) + '0';
		
		--i;
		
		val /= 10;


		if (val == 0)
		{
			break;
		}
	}
	

	while (i >= 0)
	{
		string_buffer[i] = ' ';
		
		--i;
	}


	return string_buffer;
}


#endif





