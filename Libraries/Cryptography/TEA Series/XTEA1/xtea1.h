

// ===============================================================================
//
// Эта библиотека, реализует криптографический алгоритм XTEA1.
// Функции библиотеки позволяют использовать различные режимы
// шифрования данных: ECB, CBC, PCBC, CFB и OFB
//
// -------------------------------------------------------------------------------
//
// This library implements the XTEA1 cryptographic algorithm.
// The library functions allow you to use various data
// encryption modes: ECB, CBC, PCBC, CFB and OFB
//
// ===============================================================================


#ifndef XTEA1_H_
#define XTEA1_H_

#include <stdint.h>

uint32_t XTEA1_Encrypt_ECB(void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA1_Decrypt_ECB(void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA1_Encrypt_CBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA1_Decrypt_CBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA1_Encrypt_PCBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA1_Decrypt_PCBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA1_Encrypt_CFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA1_Decrypt_CFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA1_Encrypt_OFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA1_Decrypt_OFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

#endif


