

// ===============================================================================
//
// Библиотека для кодирования и декодирования данных
// (бинарных и текстовых) с помощью стандарта Base32
//
// -------------------------------------------------------------------------------
//
// A library for encoding and decoding data
// (binary and text) using the Base32 standard
//
// ===============================================================================


#ifndef BASE32_H_
#define BASE32_H_


#include <stdint.h>


uint32_t Base32_Encode(const void *input_data, uint32_t input_data_size, char *output_base32_buffer);

uint32_t Base32_Decode(const char *input_base32_data, uint32_t input_base32_size, void *output_buffer);


#endif


