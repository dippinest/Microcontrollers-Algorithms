

// ===============================================================================
//
// Библиотека для преобразования чисел целых типов в строки C-типа
//
// -------------------------------------------------------------------------------
//
// Library for converting integers to C-type strings
//
// ===============================================================================


#ifndef ITOA_H_
#define ITOA_H_

#include <stdint.h>
#include <stdbool.h>



// ===============================================================================



// only for positive numbers!
char *ITOA_UInt8_To_String_Without_Alignment(char *string_buffer, uint8_t number, int8_t num_of_chars);

// only for positive numbers!
char *ITOA_UInt16_To_String_Without_Alignment(char *string_buffer, uint16_t number, int8_t num_of_chars);

// only for positive numbers!
char *ITOA_UInt32_To_String_Without_Alignment(char *string_buffer, uint32_t number, int8_t num_of_chars);




#ifdef NUM_64BIT_SUPPORT


// only for positive numbers!
char *ITOA_UInt64_To_String_Without_Alignment(char *string_buffer, uint64_t number, int8_t num_of_chars);

#endif




// ===============================================================================



char *ITOA_Int8_To_String(char *string_buffer, int8_t number, int8_t num_of_chars);

char *ITOA_UInt8_To_String(char *string_buffer, uint8_t number, int8_t num_of_chars);

char *ITOA_Int16_To_String(char *string_buffer, int16_t number, int8_t num_of_chars);

char *ITOA_UInt16_To_String(char *string_buffer, uint16_t number, int8_t num_of_chars);

char *ITOA_Int32_To_String(char *string_buffer, int32_t number, int8_t num_of_chars);

char *ITOA_UInt32_To_String(char *string_buffer, uint32_t number, int8_t num_of_chars);




#ifdef NUM_64BIT_SUPPORT

char *ITOA_Int64_To_String(char *string_buffer, int64_t number, int8_t num_of_chars);

char *ITOA_UInt64_To_String(char *string_buffer, uint64_t number, int8_t num_of_chars);

#endif



#endif




