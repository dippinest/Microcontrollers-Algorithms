
#include "itobina.h"



// ===============================================================================



char *ITOBINA_8bitNum_To_BinString(char *string_buffer, uint8_t val)
{
	uint8_t i = 0;
	
	
	for (; i < sizeof(uint8_t) * 8; ++i)
	{
		if ((val << i) & 0x80)
		{
			string_buffer[i] = '1';
		}
		else
		{
			string_buffer[i] = '0';
		}
	}
	
	string_buffer[i] = '\0';
	
	
	return string_buffer;
}


char *ITOBINA_16bitNum_To_BinString(char *string_buffer, uint16_t val)
{
	uint8_t i = 0;
	
	
	for (; i < sizeof(uint16_t) * 8; ++i)
	{
		if ((val << i) & 0x8000)
		{
			string_buffer[i] = '1';
		}
		else
		{
			string_buffer[i] = '0';
		}
	}
	
	string_buffer[i] = '\0';
	
	
	return string_buffer;
}


char *ITOBINA_32bitNum_To_BinString(char *string_buffer, uint32_t val)
{
	uint8_t i = 0;
	
	
	for (; i < sizeof(uint32_t) * 8; ++i)
	{
		if ((val << i) & 0x80000000)
		{
			string_buffer[i] = '1';
		}
		else
		{
			string_buffer[i] = '0';
		}
	}
	
	string_buffer[i] = '\0';
	
	
	return string_buffer;
}





#ifdef NUM_64BIT_SUPPORT


char *ITOBINA_64bitNum_To_BinString(char *string_buffer, uint64_t val)
{
	uint8_t i = 0;
	
	
	for (; i < sizeof(uint64_t) * 8; ++i)
	{
		if ((val << i) & 0x8000000000000000)
		{
			string_buffer[i] = '1';
		}
		else
		{
			string_buffer[i] = '0';
		}
	}
	
	string_buffer[i] = '\0';
	
	
	return string_buffer;
}


#endif





