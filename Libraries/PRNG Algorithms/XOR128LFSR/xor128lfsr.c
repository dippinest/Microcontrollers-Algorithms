

#include "xor128lfsr.h"



XOR128LFSR_t XOR128LFSR_Create_Object(uint32_t byte1, uint32_t byte2, uint32_t byte3, uint32_t byte4)
{
	XOR128LFSR_t generator;
	
	generator.byte1 = byte1;
	generator.byte2 = byte2;
	generator.byte3 = byte3;
	generator.byte4 = byte4;
	
	return generator;
}


// ===============================================================================


uint32_t XOR128LFSR_Get_Value(XOR128LFSR_t *generator)
{
	uint32_t t = generator->byte4;
	
	uint32_t s = generator->byte1;
	
	generator->byte4 = generator->byte3;
	generator->byte3 = generator->byte2;
	generator->byte2 = s;
	
	t ^= (t << 11);
	t ^= (t >> 8);
	
	generator->byte1 = t ^ s ^ (s >> 19);
	
	return generator->byte1;
}


// ===============================================================================


bool XOR128LFSR_Get_Bool_Value(XOR128LFSR_t *generator)
{
	return (bool)(XOR128LFSR_Get_Value(generator) & 0b1);
}

uint32_t XOR128LFSR_Get_UInt32_Value(XOR128LFSR_t *generator, uint32_t min, uint32_t max)
{
	uint32_t r = XOR128LFSR_Get_Value(generator);

	return min + (r % (max - min));
}

int32_t XOR128LFSR_Get_Int32_Value(XOR128LFSR_t *generator, int32_t min, int32_t max)
{
	uint32_t r = XOR128LFSR_Get_UInt32_Value(generator, (uint32_t)min, (uint32_t)max);

	return (int32_t)r;
}

float XOR128LFSR_Get_Float_Value(XOR128LFSR_t *generator)
{
	return (float)(XOR128LFSR_Get_Value(generator) / 4294967295ULL);
}



