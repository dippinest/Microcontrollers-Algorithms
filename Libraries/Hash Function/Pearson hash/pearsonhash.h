

// ===============================================================================
//
// Эта библиотека, реализует функцию хеширования по методу Пирсона
// (статья в Википедии: https://ru.wikipedia.org/wiki/Хеширование_Пирсона).
// В библиотеке реализованы функция получения хеша длиной 8 бит
// (оптимизированная под 8-ми битные процессоры и микроконтроллеры)
// и функция получения хеша произвольной длины
//
// -------------------------------------------------------------------------------
//
// This library implements the Pearson hashing function
// (Wikipedia article: https://en.wikipedia.org/wiki/Pearson_hashing).
// The library implements an 8-bit hash function (optimized for
// 8-bit processors and microcontrollers) and an arbitrary-length hash function.
//
// ===============================================================================


#ifndef PEARSONHASH_H_
#define PEARSONHASH_H_

#include <stdint.h>


uint8_t PearsonHash_Get_8Bit_Hash_Value(const void* data, const uint16_t data_size);

void *PearsonHash_Get_Arbitrary_Size_Hash(const void* data, const uint32_t data_size, uint8_t* hash, const uint32_t hash_size);



#endif



