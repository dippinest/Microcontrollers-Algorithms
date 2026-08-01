
#include "grayscode.h"


uint8_t GRAYSCODE_UInt8_To_UInt8Grayscode(uint8_t num)
{
	return num ^ (num >> 1);
}

uint8_t GRAYSCODE_UInt8Grayscode_To_UInt8(uint8_t gray_code)
{
	uint8_t n = 0;

	for (; gray_code; gray_code >>= 1)
	{
		n ^= gray_code;
	}

	return n;
}

uint16_t GRAYSCODE_UInt16_To_UInt16Grayscode(uint16_t num)
{
	return num ^ (num >> 1);
}

uint16_t GRAYSCODE_UInt16Grayscode_To_UInt16(uint16_t gray_code)
{
	uint16_t n = 0;

	for (; gray_code; gray_code >>= 1)
	{
		n ^= gray_code;
	}

	return n;
}

uint32_t GRAYSCODE_UInt32_To_UInt32Grayscode(uint32_t num)
{
	return num ^ (num >> 1);
}

uint32_t GRAYSCODE_UInt32Grayscode_To_UInt32(uint32_t gray_code)
{
	uint32_t n = 0;

	for (; gray_code; gray_code >>= 1)
	{
		n ^= gray_code;
	}

	return n;
}


#ifdef NUM_64BIT_SUPPORT

uint64_t GRAYSCODE_UInt64_To_UInt64Grayscode(uint64_t num)
{
	return num ^ (num >> 1);
}

uint64_t GRAYSCODE_UInt64Grayscode_To_UInt64(uint64_t gray_code)
{
	uint64_t n = 0;

	for (; gray_code; gray_code >>= 1)
	{
		n ^= gray_code;
	}

	return n;
}


#endif



void *GRAYSCODE_Raw_Data_To_Grayscode_Data(void *raw_data, const uint16_t raw_data_size)
{
	for (uint16_t i = 0; i < raw_data_size; ++i)
	{
		((uint8_t*)raw_data)[i] = GRAYSCODE_UInt8_To_UInt8Grayscode(((uint8_t*)raw_data)[i]);
	}

	return raw_data;
}

void *GRAYSCODE_Grayscode_Data_To_Raw_Data(void *grayscode_data, const uint16_t grayscode_data_size)
{
	for (uint16_t i = 0; i < grayscode_data_size; ++i)
	{
		((uint8_t*)grayscode_data)[i] = GRAYSCODE_UInt8Grayscode_To_UInt8(((uint8_t*)grayscode_data)[i]);
	}

	return grayscode_data;
}




