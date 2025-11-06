

// ===============================================================================
//
// Ѕиблиотека дл€ кодировани€ и декодировани€ данных
// (бинарных и текстовых) с помощью стандарта Base2
//
// -------------------------------------------------------------------------------
//
// A library for encoding and decoding data
// (binary and text) using the Base2 standard
//
// ===============================================================================


#ifndef BASE2_H_
#define BASE2_H_


#include <stdint.h>


uint32_t Base2_Encode(const void *input_data, uint32_t input_data_size, char *output_base2_buffer);

uint32_t Base2_Decode(const char *input_base2_buffer, uint32_t input_base2_buffer_size, void *output_data);


#endif


