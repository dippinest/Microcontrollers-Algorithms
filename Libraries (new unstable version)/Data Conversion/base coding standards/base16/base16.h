

// ===============================================================================
//
// Библиотека для кодирования и декодирования данных
// (бинарных и текстовых) с помощью стандарта Base16
//
// -------------------------------------------------------------------------------
//
// A library for encoding and decoding data
// (binary and text) using the Base16 standard
//
// ===============================================================================


#ifndef BASE16_H_
#define BASE16_H_


#include <stdint.h>


uint32_t Base16_Encode(const void *input_data, uint32_t input_data_size, char *output_base16_buffer);

uint32_t Base16_Decode(const char *input_base16_buffer, uint32_t input_base16_buffer_size, void *output_data);


#endif


