

// ===============================================================================
//
// Библиотека генератора псевдослучайных чисел.
// В ней реализуется ГПСЧ семейства LFSR с длиной регистра 128 бит.
// Описание алгоритма взято из Википедии: https://ru.wikipedia.org/wiki/Xorshift
//
// -------------------------------------------------------------------------------
//
// The library of the pseudorandom number generator.
// It implements the LFSR family RNG with a register length of 128 bits.
// The description of the algorithm is taken
// from Wikipedia: https://en.wikipedia.org/wiki/Xorshift
//
// ===============================================================================


#ifndef XOR128LFSR_H_
#define XOR128LFSR_H_


#include <stdint.h>
#include <stdbool.h>


typedef struct
{
	uint32_t byte1;
	uint32_t byte2;
	uint32_t byte3;
	uint32_t byte4;
	
} XOR128LFSR_t;


XOR128LFSR_t XOR128LFSR_Create_Object(uint32_t byte1, uint32_t byte2, uint32_t byte3, uint32_t byte4);

// ===============================================================================

uint32_t XOR128LFSR_Get_Value(XOR128LFSR_t *generator);

// ===============================================================================


bool XOR128LFSR_Get_Bool_Value(XOR128LFSR_t *generator);

uint32_t XOR128LFSR_Get_UInt32_Value(XOR128LFSR_t *generator, uint32_t min, uint32_t max);

int32_t XOR128LFSR_Get_Int32_Value(XOR128LFSR_t *generator, int32_t min, int32_t max);

float XOR128LFSR_Get_Float_Value(XOR128LFSR_t *generator);


#endif



