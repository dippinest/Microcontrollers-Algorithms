

// ===============================================================================
//
// Эта библиотека, реализует криптографический алгоритм RTEA
// с размером ключа 256 бит. Функции библиотеки позволяют использовать
// различные режимы шифрования данных: ECB, CBC, PCBC, CFB, OFB и CTR
//
// -------------------------------------------------------------------------------
//
// This library implements the RTEA cryptographic algorithm
// with a key size of 256 bits. The library functions allow you to use
// various data encryption modes: ECB, CBC, PCBC, CFB, OFB and CTR
// ===============================================================================


#ifndef RTEA256BITKEY_H_
#define RTEA256BITKEY_H_

#include <stdint.h>


uint32_t RTEA256BitKey_Encrypt_ECB(void* data, const uint32_t data_size, const void* key_256bit);

uint32_t RTEA256BitKey_Decrypt_ECB(void* data, const uint32_t data_size, const void* key_256bit);

uint32_t RTEA256BitKey_Encrypt_CBC(void* init_vector_64bit, void* data, const uint32_t data_size, const void* key_256bit);

uint32_t RTEA256BitKey_Decrypt_CBC(void* init_vector_64bit, void* data, const uint32_t data_size, const void* key_256bit);

uint32_t RTEA256BitKey_Encrypt_PCBC(void* init_vector_64bit, void* data, const uint32_t data_size, const void* key_256bit);

uint32_t RTEA256BitKey_Decrypt_PCBC(void* init_vector_64bit, void* data, const uint32_t data_size, const void* key_256bit);

uint32_t RTEA256BitKey_Encrypt_CFB(void* init_vector_64bit, void* data, const uint32_t data_size, const void* key_256bit);

uint32_t RTEA256BitKey_Decrypt_CFB(void* init_vector_64bit, void* data, const uint32_t data_size, const void* key_256bit);

uint32_t RTEA256BitKey_Encrypt_OFB(void* init_vector_64bit, void* data, const uint32_t data_size, const void* key_256bit);

uint32_t RTEA256BitKey_Decrypt_OFB(void* init_vector_64bit, void* data, const uint32_t data_size, const void* key_256bit);


// ===============================================================================


void *RTEA256BitKey_Encrypt_CTR(void *init_vector_64bit, void *_64bit_block, const void *key_256bit);

void *RTEA256BitKey_Decrypt_CTR(void *init_vector_64bit, void *_64bit_block, const void *key_256bit);


#endif



