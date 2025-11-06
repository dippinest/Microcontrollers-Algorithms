

// ===============================================================================
//
// Ѕиблиотека дл€ кодировани€ и декодировани€ данных
// (бинарных и текстовых) с помощью стандарта Base64
//
// -------------------------------------------------------------------------------
//
// A library for encoding and decoding data
// (binary and text) using the Base64 standard
//
// ===============================================================================


#ifndef BASE64_H_
#define BASE64_H_


#include <stdint.h>


uint32_t Base64_Encode(const void *input_data, uint32_t input_data_size, char *output_base64_buffer);

uint32_t Base64_Decode(const char *input_base64_data, uint32_t input_base64_size, void *output_buffer);


#endif


