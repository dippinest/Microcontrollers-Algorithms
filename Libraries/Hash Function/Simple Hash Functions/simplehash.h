

// ===============================================================================
//
// ��� ���������� �������� ���������� ������� ���������� �����������.
// �� ������ ������ ���� ���������� ��������� ����������:
//
// 1. FNV (������ � ���������: https://ru.wikipedia.org/wiki/FNV)
//
// 2. Jenkins (������ � ���������: https://ru.wikipedia.org/wiki/���-�������_���������)
//
// -------------------------------------------------------------------------------
//
// This library contains implementations of simple hashing algorithms.
// Currently, there are implementations of the following algorithms:
//
// 1. FNV (Wikipedia article: https://en.wikipedia.org/wiki/Fowler�Noll�Vo_hash_function)
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



