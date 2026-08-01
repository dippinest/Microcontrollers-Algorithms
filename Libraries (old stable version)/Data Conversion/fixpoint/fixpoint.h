

// ===============================================================================
//
// Это библиотека для работы с числами с фиксированной точкой. Числа с
// фиксированной точкой называются так потому, что дробные разряды
// задаются младшими разрядами целого десятичного числа, а не двоичными,
// как в случае классических решений
//
// -------------------------------------------------------------------------------
//
// This is a library for working with numbers with a fixed point.
// Numbers with a fixed point are so called because fractional digits
// are given by the lower digits of an integer decimal number, and not
// binary, as in the case of classical solutions
//
// ===============================================================================


#ifndef FIXPOINT_H_
#define FIXPOINT_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


// ===============================================================================


void FIXPoint_Set_String_Buffer(char* string_buffer_ptr);

char *FIXPoint_Set_String_Buffer_To_Dynamic_Memory(const uint8_t string_buffer_size);

void FIXPoint_Delete_String_Buffer_From_Dynamic_Memory();


// ===============================================================================


void FIXPoint_Set_Number_Of_Decimal_Places(const uint8_t number_of_decimal_places);

void FIXPoint_Set_Empty_Char_Symbol(const char empty_char);

void FIXPoint_Set_Decimal_Char_Separator(const char char_separator);

char* FIXPoint_Get_String_Buffer_Ptr();

char FIXPoint_Get_Number_Of_Decimal_Places();

char FIXPoint_Get_Empty_Char_Symbol();

char FIXPoint_Get_Decimal_Char_Separator();


// ===============================================================================


char* FIXPoint_Int16FP_To_String(int16_t val, int8_t num_int_digits, int8_t num_fract_digits);


char* FIXPoint_Int32FP_To_String(int32_t val, int8_t num_int_digits, int8_t num_fract_digits);


#ifdef NUM_64BIT_SUPPORT

// use a 64-bit representation of numbers to get a large
// dynamic representation of a number with a pseudo-fixed point
char* FIXPoint_Int64FP_To_String(int64_t val, int8_t num_int_digits, int8_t num_fract_digits);

#endif

#endif



