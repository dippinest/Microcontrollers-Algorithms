

// ===============================================================================
//
// Эта библиотека, реализует криптографический алгоритм XTEA3.
// Функции библиотеки позволяют использовать различные режимы
// шифрования данных: ECB, CBC, PCBC, CFB и OFB
//
// -------------------------------------------------------------------------------
//
// This library implements the XTEA3 cryptographic algorithm.
// The library functions allow you to use various data
// encryption modes: ECB, CBC, PCBC, CFB and OFB
//
// ===============================================================================


#ifndef XTEA3_H_
#define XTEA3_H_


#include <stdint.h>


uint32_t XTEA3_Encrypt_ECB(void *data, const uint32_t data_size, const void *key_256bit, uint8_t num_of_rounds);

uint32_t XTEA3_Decrypt_ECB(void *data, const uint32_t data_size, const void *key_256bit, uint8_t num_of_rounds);

uint32_t XTEA3_Encrypt_CBC(const void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_256bit, uint8_t num_of_rounds);

uint32_t XTEA3_Decrypt_CBC(const void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_256bit, uint8_t num_of_rounds);

uint32_t XTEA3_Encrypt_PCBC(const void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_256bit, uint8_t num_of_rounds);

uint32_t XTEA3_Decrypt_PCBC(const void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_256bit, uint8_t num_of_rounds);

uint32_t XTEA3_Encrypt_CFB(const void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_256bit, uint8_t num_of_rounds);

uint32_t XTEA3_Decrypt_CFB(const void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_256bit, uint8_t num_of_rounds);

uint32_t XTEA3_Encrypt_OFB(const void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_256bit, uint8_t num_of_rounds);

uint32_t XTEA3_Decrypt_OFB(const void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_256bit, uint8_t num_of_rounds);

#endif




