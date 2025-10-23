

// ===============================================================================
//
// Эта библиотека содержит реализации простых алгоритмов хештрования.
// На данный момент есть реализации следующих алгоритмов:
//
// 1. FNV (статья в Википедии: https://ru.wikipedia.org/wiki/FNV)
//
// 2. Jenkins (статья в Википедии: https://ru.wikipedia.org/wiki/Хеш-функция_Дженкинса)
//
// -------------------------------------------------------------------------------
//
// This library contains implementations of simple hashing algorithms.
// Currently, there are implementations of the following algorithms:
//
// 1. FNV (Wikipedia article: https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function)
//
// 2. Jenkins (Wikipedia article: https://en.wikipedia.org/wiki/Jenkins_hash_function)
//
// ===============================================================================


#ifndef SIMPLEHASH_H_
#define SIMPLEHASH_H_


#include <stdint.h>


uint32_t SimpleHash_FNV(const void* data, uint32_t data_size);

uint32_t SimpleHash_Jenkins(const void* data, uint32_t data_size);




#endif



