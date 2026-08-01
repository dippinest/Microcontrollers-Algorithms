

#include "xorshift32.h"



XORShift32_t XORShift32_Create_Object(uint32_t seed)
{
	XORShift32_t generator;
	
	generator.state = seed;
	
	return generator;
}


// ===============================================================================


uint32_t XORShift32_Get_Value(XORShift32_t *generator)
{
	uint32_t t = generator->state;
	
	t ^= (t << 13);
	t ^= (t >> 17);
	t ^= (t << 5);
	
	generator->state = t;
	
	return generator->state;
}


// ===============================================================================


bool XORShift32_Get_Bool_Value(XORShift32_t *generator)
{
	return (bool)(XORShift32_Get_Value(generator) & 0b1);
}

uint32_t XORShift32_Get_UInt32_Value(XORShift32_t *generator, uint32_t min, uint32_t max)
{
	uint32_t r = XORShift32_Get_Value(generator);

	return min + (r % (max - min));
}

int32_t XORShift32_Get_Int32_Value(XORShift32_t *generator, int32_t min, int32_t max)
{
	uint32_t r = XORShift32_Get_UInt32_Value(generator, (uint32_t)min, (uint32_t)max);

	return (int32_t)r;
}



