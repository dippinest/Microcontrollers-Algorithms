

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



char* FIXPoint_Int16FP_To_String
(
	char *string_budder,
	const uint8_t num_of_decimal_places_PFIXPoint,
	int16_t val, int8_t num_int_digits,
	int8_t num_fract_digits,
	const char empty_char,
	const char decimal_char_separator
);


char* FIXPoint_Int32FP_To_String
(
	char *string_buffer,
	const uint8_t num_of_decimal_places_PFIXPoint,
	int32_t val, int8_t num_int_digits,
	int8_t num_fract_digits,
	const char empty_char,
	const char decimal_char_separator
);



#ifdef NUM_64BIT_SUPPORT

// use a 64-bit representation of numbers to get a large
// dynamic representation of a number with a pseudo-fixed point
char* FIXPoint_Int64FP_To_String
(
	char *string_buffer,
	const uint8_t num_of_decimal_places_PFIXPoint,
	int64_t val,
	int8_t num_int_digits,
	int8_t num_fract_digits,
	const char empty_char,
	const char decimal_char_separator
);

#endif



#endif






