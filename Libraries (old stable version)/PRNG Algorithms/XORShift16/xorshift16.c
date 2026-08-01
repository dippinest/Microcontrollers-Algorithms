

#include "xorshift16.h"



XORShift16_t XORShift16_Create_Object(uint16_t seed)
{
	XORShift16_t generator;
	
	generator.state = seed;
	
	return generator;
}


// ===============================================================================


uint16_t XORShift16_Get_Value(XORShift16_t *generator)
{
	uint16_t t = generator->state;
	
	t ^= (t << 7);
	t ^= (t >> 9);
	t ^= (t << 8);
	
	generator->state = t;
	
	return generator->state;
}


// ===============================================================================


bool XORShift16_Get_Bool_Value(XORShift16_t *generator)
{
	return (bool)(XORShift16_Get_Value(generator) & 0b1);
}

uint16_t XORShift16_Get_UInt16_Value(XORShift16_t *generator, uint16_t min, uint16_t max)
{
	uint16_t r = XORShift16_Get_Value(generator);

	return min + (r % (max - min));
}

int16_t XORShift16_Get_Int16_Value(XORShift16_t *generator, int16_t min, int16_t max)
{
	uint16_t r = XORShift16_Get_UInt16_Value(generator, (uint16_t)min, (uint16_t)max);

	return (int16_t)r;
}



