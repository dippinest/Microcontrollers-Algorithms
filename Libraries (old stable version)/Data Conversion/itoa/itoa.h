

// ===============================================================================
//
// Библиотека для преобразования чисел целого типа в строку C-типа
//
// -------------------------------------------------------------------------------
//
// Library for converting integers to C-type string
//
// ===============================================================================


#ifndef ITOA_H_
#define ITOA_H_

#include <stdint.h>
#include <stdlib.h>


// ===============================================================================


void ITOA_Set_String_Buffer(char *string_buffer_ptr);

char *ITOA_Set_String_Buffer_To_Dynamic_Memory(const uint8_t string_buffer_size);

void ITOA_Delete_String_Buffer_From_Dynamic_Memory();


// ===============================================================================


char *ITOA_Get_String_Buffer_Ptr();


// ===============================================================================


// only for positive numbers!
char *ITOA_UInt8_To_String_Without_Alignment(uint8_t val, int8_t num_of_chars);

// only for positive numbers!
char *ITOA_UInt16_To_String_Without_Alignment(uint16_t val, int8_t num_of_chars);

// only for positive numbers!
char *ITOA_UInt32_To_String_Without_Alignment(uint32_t val, int8_t num_of_chars);


#ifdef NUM_64BIT_SUPPORT

// only for positive numbers!
char *ITOA_UInt64_To_String_Without_Alignment(uint64_t val, int8_t num_of_chars);

#endif


// ===============================================================================


char *ITOA_Int8_To_String(int8_t val, int8_t num_of_chars);

char *ITOA_UInt8_To_String(uint8_t val, int8_t num_of_chars);

char *ITOA_Int16_To_String(int16_t val, int8_t num_of_chars);

char *ITOA_UInt16_To_String(uint16_t val, int8_t num_of_chars);

char *ITOA_Int32_To_String(int32_t val, int8_t num_of_chars);

char *ITOA_UInt32_To_String(uint32_t val, int8_t num_of_chars);


#ifdef NUM_64BIT_SUPPORT

char *ITOA_Int64_To_String(int64_t val, int8_t num_of_chars);

char *ITOA_UInt64_To_String(uint64_t val, int8_t num_of_chars);

#endif


#endif


