

#include "maprng.h"


MAPRNG_t MAPRNG_Create_Object(uint8_t init_value, uint16_t init_addr, uint16_t max_addr, uint8_t(*read_byte)(uint16_t addr), void (*write_byte)(uint16_t addr, uint8_t b))
{
	MAPRNG_t maprng;

	maprng.last_value = init_value;
	maprng.init_addr  = init_addr;
	maprng.max_addr   = max_addr;

	maprng.read_byte  = read_byte;
	maprng.write_byte = write_byte;

	return maprng;
}

// ===============================================================================

uint8_t MAPRNG_Get_8Bit_Value(MAPRNG_t* maprng)
{
	if (maprng->read_byte == NULL || maprng->write_byte == NULL)
	{
		return 0;
	}

	maprng->init_addr = (maprng->init_addr) % (maprng->max_addr);

	uint16_t addr_ptr = maprng->init_addr;


	uint8_t a = maprng->read_byte(maprng->init_addr);

	a ^= maprng->last_value;

	addr_ptr = (a ^ (maprng->init_addr)) % (maprng->max_addr);


	uint8_t b = maprng->read_byte(addr_ptr);


	uint8_t res = maprng->read_byte(a % (maprng->max_addr)) ^ (a + b);


	uint8_t temp;

	if (a < b)
	{
		temp = maprng->read_byte((addr_ptr + b) % (maprng->max_addr));

		temp ^= a;

		addr_ptr = (a + (maprng->init_addr)) % (maprng->max_addr);


		maprng->write_byte(addr_ptr, temp);


		temp = maprng->read_byte(maprng->init_addr);

		temp ^= maprng->last_value;
	}
	else
	{
		temp = maprng->read_byte((addr_ptr + a) % (maprng->max_addr));

		temp ^= b;

		addr_ptr = (a ^ (maprng->init_addr)) % (maprng->max_addr);


		maprng->write_byte(addr_ptr, temp);


		temp = maprng->read_byte(maprng->init_addr);

		temp += res;
	}


	maprng->write_byte(maprng->init_addr, temp);

	++(maprng->init_addr);


	maprng->last_value ^= ((res ^ temp) + 1);

	return res;
}

uint16_t MAPRNG_Get_16Bit_Value(MAPRNG_t* maprng)
{
	uint16_t res = MAPRNG_Get_8Bit_Value(maprng);

	res <<= 8;

	res |= MAPRNG_Get_8Bit_Value(maprng);

	return res;
}

uint32_t MAPRNG_Get_32Bit_Value(MAPRNG_t* maprng)
{
	uint32_t res = MAPRNG_Get_16Bit_Value(maprng);

	res <<= 8;

	res |= MAPRNG_Get_16Bit_Value(maprng);

	return res;
}

// ===============================================================================

bool MAPRNG_Get_Bool_Value(MAPRNG_t* maprng)
{
	return (bool)(MAPRNG_Get_8Bit_Value(maprng) & 0x01);
}

uint8_t MAPRNG_Get_UInt8_Value(MAPRNG_t* maprng, uint8_t min, uint8_t max)
{
	return min + (MAPRNG_Get_8Bit_Value(maprng) % (max - min));
}

int8_t MAPRNG_Get_Int8_Value(MAPRNG_t* maprng, int8_t min, int8_t max)
{
	uint8_t r = min + (MAPRNG_Get_8Bit_Value(maprng) % (max - min));

	return (int8_t)r;
}

uint16_t MAPRNG_Get_UInt16_Value(MAPRNG_t* maprng, uint16_t min, uint16_t max)
{
	return min + (MAPRNG_Get_16Bit_Value(maprng) % (max - min));
}

int16_t MAPRNG_Get_Int16_Value(MAPRNG_t* maprng, int16_t min, int16_t max)
{
	uint16_t r = min + (MAPRNG_Get_16Bit_Value(maprng) % (max - min));

	return (int16_t)r;
}

uint32_t MAPRNG_Get_UInt32_Value(MAPRNG_t* maprng, uint32_t min, uint32_t max)
{
	return min + (MAPRNG_Get_32Bit_Value(maprng) % (max - min));
}

int32_t MAPRNG_Get_Int32_Value(MAPRNG_t* maprng, int32_t min, int32_t max)
{
	uint32_t r = min + (MAPRNG_Get_32Bit_Value(maprng) % (max - min));

	return (int32_t)r;
}



