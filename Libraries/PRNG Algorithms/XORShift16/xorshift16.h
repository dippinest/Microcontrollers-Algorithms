

// ===============================================================================
//
// Библиотека генератора псевдослучайных чисел.
// В ней реализуется ГПСЧ семейства Xorshift с длиной регистра 16 бит.
// Описание алгоритма взято из Википедии: https://ru.wikipedia.org/wiki/Xorshift
//
// -------------------------------------------------------------------------------
//
// The library of the pseudorandom number generator.
// It implements the Xorshift family RNG with a register length of 16 bits.
// The description of the algorithm is taken
// from Wikipedia: https://en.wikipedia.org/wiki/Xorshift
//
// ===============================================================================


#ifndef XORSHIFT16_H_
#define XORSHIFT16_H_


#include <stdint.h>
#include <stdbool.h>



typedef struct
{
	uint16_t state;
	
} XORShift16_t;


XORShift16_t XORShift16_Create_Object(uint16_t seed);


// ===============================================================================


uint16_t XORShift16_Get_Value(XORShift16_t *generator);


// ===============================================================================


bool XORShift16_Get_Bool_Value(XORShift16_t *generator);

uint16_t XORShift16_Get_UInt16_Value(XORShift16_t *generator, uint16_t min, uint16_t max);

int16_t XORShift16_Get_Int16_Value(XORShift16_t *generator, int16_t min, int16_t max);


#endif



