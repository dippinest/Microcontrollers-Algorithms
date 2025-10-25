

// ===============================================================================
//
// Эта библиотека, реализует криптографический алгоритм XTEA.
// Функции библиотеки позволяют использовать различные режимы
// шифрования данных: ECB, CBC, PCBC, CFB и OFB
//
// -------------------------------------------------------------------------------
//
// This library implements the XTEA cryptographic algorithm.
// The library functions allow you to use various data
// encryption modes: ECB, CBC, PCBC, CFB and OFB
//
// ===============================================================================


#ifndef XTEA_H_
#define XTEA_H_


#include <stdint.h>


uint32_t XTEA_Encrypt_ECB(void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA_Decrypt_ECB(void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA_Encrypt_CBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA_Decrypt_CBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA_Encrypt_PCBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA_Decrypt_PCBC(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA_Encrypt_CFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA_Decrypt_CFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA_Encrypt_OFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA_Decrypt_OFB(void *init_vector_64bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

#endif


