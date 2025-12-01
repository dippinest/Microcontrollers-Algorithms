

// ===============================================================================
//
// Библиотека генератора псевдослучайных чисел.
// В ней реализуется ГПСЧ семейства Xorshift с длиной регистра 32 бит.
// Описание алгоритма взято из Википедии: https://ru.wikipedia.org/wiki/Xorshift
//
// -------------------------------------------------------------------------------
//
// The library of the pseudorandom number generator.
// It implements the Xorshift family RNG with a register length of 32 bits.
// The description of the algorithm is taken
// from Wikipedia: https://en.wikipedia.org/wiki/Xorshift
//
// ===============================================================================


#ifndef XORSHIFT32_H_
#define XORSHIFT32_H_


#include <stdint.h>
#include <stdbool.h>



typedef struct
{
	uint32_t state;
	
} XORShift32_t;


XORShift32_t XORShift32_Create_Object(uint32_t seed);


// ===============================================================================


uint32_t XORShift32_Get_Value(XORShift32_t *generator);


// ===============================================================================


bool XORShift32_Get_Bool_Value(XORShift32_t *generator);

uint32_t XORShift32_Get_UInt32_Value(XORShift32_t *generator, uint32_t min, uint32_t max);

int32_t XORShift32_Get_Int32_Value(XORShift32_t *generator, int32_t min, int32_t max);


#endif



