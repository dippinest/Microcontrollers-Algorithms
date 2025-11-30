
#include "random.h"


void Random_Set_Seed(uint16_t seed)
{
	srand(seed);
}

// ===============================================================================


bool Random_Get_Bool_Value()
{
	return (bool)(rand() & 0x0001);
}

uint16_t Random_Get_UInt15_Value(uint16_t min, uint16_t max)
{
	return min + ((uint16_t)rand() % (max - min));
}

int16_t Random_Get_Int15_Value(int16_t min, int16_t max)
{
	int16_t r = (int16_t)rand();

	return min + (r % (max - min));
}

uint16_t Random_Get_UInt16_Value(uint16_t min, uint16_t max)
{
	return min + (((uint16_t)rand() + (uint16_t)rand()) % (max - min));
}

int16_t Random_Get_Int16_Value(int16_t min, int16_t max)
{
	uint16_t r = Random_Get_UInt16_Value((uint16_t)min, (uint16_t)max);

	return (int16_t)r;
}

uint32_t Random_Get_UInt32_Value(uint32_t min, uint32_t max)
{
	uint32_t r = (uint32_t)Random_Get_UInt16_Value(0, 65535);

	r <<= 16;
	
	r |= Random_Get_UInt16_Value(0, 65535);

	return min + (r % (max - min));
}

int32_t Random_Get_Int32_Value(int32_t min, int32_t max)
{
	uint32_t r = Random_Get_UInt32_Value((uint32_t)min, (uint32_t)max);

	return (int32_t)r;
}



