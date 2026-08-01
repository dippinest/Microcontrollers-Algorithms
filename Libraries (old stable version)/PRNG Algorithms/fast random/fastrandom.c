
#include "fastrandom.h"

static uint16_t _seed = 0x0000;

// ===============================================================================

void FASTRandom_Set_Seed(uint16_t seed)
{
	_seed = seed;
}

uint16_t _FASTRandom_Get_Value()
{
	_seed += _FASTRANDOM_MAGIC_VALUE;

	_seed = _FASTRANDOM_ROTR(_seed, 5, uint16_t);

	return _seed;
}

// ===============================================================================

bool FASTRandom_Get_Bool_Value()
{
	return (bool)(_FASTRandom_Get_Value() & 0x0001);
}

uint16_t FASTRandom_Get_UInt16_Value(uint16_t min, uint16_t max)
{
	return (uint16_t)(min + (_FASTRandom_Get_Value() % (max - min)));
}

int16_t FASTRandom_Get_Int16_Value(int16_t min, int16_t max)
{
	uint16_t r = FASTRandom_Get_UInt16_Value((uint16_t)min, (uint16_t)max);

	return (int16_t)r;
}

uint32_t FASTRandom_Get_UInt32_Value(uint32_t min, uint32_t max)
{
	uint32_t r = (uint32_t)FASTRandom_Get_UInt16_Value(0, 65535);

	r <<= 16;
	
	r |= FASTRandom_Get_UInt16_Value(0, 65535);

	return min + (r % (max - min));
}

int32_t FASTRandom_Get_Int32_Value(int32_t min, int32_t max)
{
	uint32_t r = FASTRandom_Get_UInt32_Value((uint32_t)min, (uint32_t)max);

	return (int32_t)r;
}




