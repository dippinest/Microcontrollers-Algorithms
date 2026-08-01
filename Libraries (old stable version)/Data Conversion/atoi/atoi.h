

// ===============================================================================
//
// Библиотека для преобразования строки C-типа в числа целых типов
//
// -------------------------------------------------------------------------------
//
// Library for converting C-type strings to integers
//
// ===============================================================================


#ifndef ATOI_H_
#define ATOI_H_

#include <stdint.h>
#include <stddef.h>


// ===============================================================================


int8_t ATOI_String_To_Int8(char* string, uint8_t max_string_len);

uint8_t ATOI_String_To_UInt8(char* string, uint8_t max_string_len);

int16_t ATOI_String_To_Int16(char* string, uint8_t max_string_len);

uint16_t ATOI_String_To_UInt16(char* string, uint8_t max_string_len);

int32_t ATOI_String_To_Int32(char* string, uint8_t max_string_len);

uint32_t ATOI_String_To_UInt32(char* string, uint8_t max_string_len);


#ifdef NUM_64BIT_SUPPORT

int64_t ATOI_String_To_Int64(char* string, uint8_t max_string_len);

uint64_t ATOI_String_To_UInt64(char* string, uint8_t max_string_len);

#endif



#endif



