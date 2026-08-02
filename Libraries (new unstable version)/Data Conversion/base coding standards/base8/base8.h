

// ===============================================================================
//
// Библиотека для кодирования и декодирования данных
// (бинарных и текстовых) с помощью стандарта Base8
//
// -------------------------------------------------------------------------------
//
// A library for encoding and decoding data
// (binary and text) using the Base8 standard
//
// ===============================================================================


#ifndef BASE8_H_
#define BASE8_H_


#include <stdint.h>


uint32_t Base8_Encode(const void *input_data, uint32_t input_data_size, char *output_base8_buffer);

uint32_t Base8_Decode(const char *input_base8_data, uint32_t input_base8_size, void *output_buffer);


#endif


