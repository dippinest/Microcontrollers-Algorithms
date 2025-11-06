

// ===============================================================================
//
// Ѕиблиотека дл€ кодировани€ и декодировани€ данных
// (бинарных и текстовых) с помощью стандарта Base4
//
// -------------------------------------------------------------------------------
//
// A library for encoding and decoding data
// (binary and text) using the Base4 standard
//
// ===============================================================================


#ifndef BASE4_H_
#define BASE4_H_


#include <stdint.h>


uint32_t Base4_Encode(const void *input_data, uint32_t input_data_size, char *output_base4_buffer);

uint32_t Base4_Decode(const char *input_base4_buffer, uint32_t input_base4_buffer_size, void *output_data);


#endif


