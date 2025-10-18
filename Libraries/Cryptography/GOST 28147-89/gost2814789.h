

// ===============================================================================
//
// Библиотека с реализацией криптографического блочного алгоритма стандарта
// ГОСТ 28147-89, разработанного в СССР 8-м управлением КГБ
// (ссылка в Википедии: https://ru.wikipedia.org/wiki/ГОСТ_28147-89 ).
//
// Данный алгоритм использует сеть Фейстеля и предназначен для работы
// с 64-х битным блоком и 256-ти битным ключём шифрования.
//
// В данной библиотеке реализованы режимы шифрования ECB, CBC, PCBC, CFB и OFB.
//
// Следует отметить, что S-блок замены 4-х битных элементов в алгоритме
// нестандартизирован, поэтому вы можете заменить его на свой.
// Я взял значения S-блока из статьи в Википедии.
//
// -------------------------------------------------------------------------------
//
// Library with the implementation of the cryptographic block algorithm
// of the GOST 28147-89 standard, developed in the USSR by the 8th directorate
// of the KGB - Committee for State Security USSR
// (Wikipedia link: https://en.wikipedia.org/wiki/GOST_(block_cipher) ).
//
// This algorithm uses a Feistel network and is designed to work with
// a 64-bit block and a 256-bit encryption key.
//
// It should be noted that the S-block for replacing 4-bit elements in
// the algorithm is not standardized, so you can replace it with your own.
// I took the values of the S-block from the Wikipedia article.
//
// This library implements the ECB, CBC, PCBC, CFB and OFB encryption modes.
//
// ===============================================================================


#ifndef GOST2814789_H_
#define GOST2814789_H_

#include <stdint.h>


#ifndef ROTL
#define ROTL(val, pos, val_type) (val << pos) | (val >> (sizeof(val_type) * 8 - pos))
#endif


uint32_t GOST2814789_Encrypt_ECB(void *data, const uint32_t data_size, const void *key_256bit);

uint32_t GOST2814789_Decrypt_ECB(void *data, const uint32_t data_size, const void *key_256bit);

uint32_t GOST2814789_Encrypt_CBC(const void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit);

uint32_t GOST2814789_Decrypt_CBC(const void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit);

uint32_t GOST2814789_Encrypt_PCBC(const void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit);

uint32_t GOST2814789_Decrypt_PCBC(const void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit);

uint32_t GOST2814789_Encrypt_CFB(const void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit);

uint32_t GOST2814789_Decrypt_CFB(const void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit);

uint32_t GOST2814789_Encrypt_OFB(const void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit);

uint32_t GOST2814789_Decrypt_OFB(const void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_256bit);


#endif








