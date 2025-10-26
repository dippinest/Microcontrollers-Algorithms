

// ===============================================================================
//
// Эта библиотека, реализует криптографический алгоритм XTEA2.
// Функции библиотеки позволяют использовать различные режимы
// шифрования данных: ECB, CBC, PCBC, CFB, OFB и CTR
//
// -------------------------------------------------------------------------------
//
// This library implements the XTEA2 cryptographic algorithm.
// The library functions allow you to use various data
// encryption modes: ECB, CBC, PCBC, CFB, OFB and CTR
//
// ===============================================================================


#ifndef XTEA2_H_
#define XTEA2_H_

#include <stdint.h>

uint32_t XTEA2_Encrypt_ECB(void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA2_Decrypt_ECB(void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA2_Encrypt_CBC(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA2_Decrypt_CBC(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA2_Encrypt_PCBC(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA2_Decrypt_PCBC(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA2_Encrypt_CFB(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA2_Decrypt_CFB(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA2_Encrypt_OFB(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);

uint32_t XTEA2_Decrypt_OFB(void *init_vector_128bit, void *data, const uint32_t data_size, const void *key_128bit, uint8_t num_of_rounds);


// ===============================================================================


void *XTEA2_Encrypt_CTR(void *init_vector_128bit, void *_128bit_block, const void *key_128bit, uint8_t num_of_rounds);

void *XTEA2_Decrypt_CTR(void *init_vector_128bit, void *_128bit_block, const void *key_128bit, uint8_t num_of_rounds);


#endif



