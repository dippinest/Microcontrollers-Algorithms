

#include "xorshift128.h"



XORShift128_t XORShift128_Create_Object(uint32_t value_32bit_0, uint32_t value_32bit_1, uint32_t value_32bit_2, uint32_t value_32bit_3)
{
	XORShift128_t generator;
	
	generator.value_32bit_0 = value_32bit_0;
	generator.value_32bit_1 = value_32bit_1;
	generator.value_32bit_2 = value_32bit_2;
	generator.value_32bit_3 = value_32bit_3;
	
	return generator;
}


// ===============================================================================


uint32_t XORShift128_Get_Value(XORShift128_t *generator)
{
	uint32_t t = generator->value_32bit_3;
	
	uint32_t s = generator->value_32bit_0;
	
	generator->value_32bit_3 = generator->value_32bit_2;
	generator->value_32bit_2 = generator->value_32bit_1;
	generator->value_32bit_1 = s;
	
	t ^= (t << 11);
	t ^= (t >> 8);
	
	generator->value_32bit_0 = t ^ s ^ (s >> 19);
	
	return generator->value_32bit_0;
}


// ===============================================================================


bool XORShift128_Get_Bool_Value(XORShift128_t *generator)
{
	return (bool)(XORShift128_Get_Value(generator) & 0b1);
}

uint32_t XORShift128_Get_UInt32_Value(XORShift128_t *generator, uint32_t min, uint32_t max)
{
	uint32_t r = XORShift128_Get_Value(generator);

	return min + (r % (max - min));
}

int32_t XORShift128_Get_Int32_Value(XORShift128_t *generator, int32_t min, int32_t max)
{
	uint32_t r = XORShift128_Get_UInt32_Value(generator, (uint32_t)min, (uint32_t)max);

	return (int32_t)r;
}



