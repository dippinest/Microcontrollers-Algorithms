

// ===============================================================================
//
// Библиотека генератора псевдослучайных чисел.
// В ней реализуется ГПСЧ семейства Xorshift с длиной регистра 128 бит.
// Описание алгоритма взято из Википедии: https://ru.wikipedia.org/wiki/Xorshift
//
// -------------------------------------------------------------------------------
//
// The library of the pseudorandom number generator.
// It implements the Xorshift family RNG with a register length of 128 bits.
// The description of the algorithm is taken
// from Wikipedia: https://en.wikipedia.org/wiki/Xorshift
//
// ===============================================================================


#ifndef XORSHIFT128_H_
#define XORSHIFT128_H_


#include <stdint.h>
#include <stdbool.h>



typedef struct
{
	uint32_t value_32bit_0;
	uint32_t value_32bit_1;
	uint32_t value_32bit_2;
	uint32_t value_32bit_3;
	
} XORShift128_t;


XORShift128_t XORShift128_Create_Object(uint32_t value_32bit_0, uint32_t value_32bit_1, uint32_t value_32bit_2, uint32_t value_32bit_3);


// ===============================================================================


uint32_t XORShift128_Get_Value(XORShift128_t *generator);


// ===============================================================================


bool XORShift128_Get_Bool_Value(XORShift128_t *generator);

uint32_t XORShift128_Get_UInt32_Value(XORShift128_t *generator, uint32_t min, uint32_t max);

int32_t XORShift128_Get_Int32_Value(XORShift128_t *generator, int32_t min, int32_t max);


#endif





