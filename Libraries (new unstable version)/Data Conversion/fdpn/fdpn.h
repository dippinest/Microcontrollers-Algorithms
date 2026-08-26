

// ===============================================================================
//
// Библиотека для работы с числами с фиксированной десятичной точкой
// (FDPN - Fixed Decimal Point Number).
//
//
// Любое целое число можно интерпретировать как число с десятичной точкой:
//
// например, число 1000 типа int16_t можно воспринимать
// как десятичную дробь 100.0, 10.00, 1.000 и т.д.
//
// Это свойство можно использовать для замены тяжёлых операций с плавающей точкой
// на платформах, в которых нет аппаратного блока FPU.
//
// Внимание! При работе с FDPN важно помнить о возможностях переполнения!
// Если переполнения отслеживать сложно,
// используйте типы с бОльшим диапазоном (int32_t или int64_t).
//
// Библиотека содержит функции для преобразования
// чисел с фиксированной десятичной точкой в ASCII строки и обратно
//
// -------------------------------------------------------------------------------
//
// Library for working with numbers with a fixed decimal point
// (FDPN - Fixed Decimal Point Number).
//
//
// Any integer can be interpreted as a number with a decimal point:
//
// for example, the number 1000 of type int16_t can be perceived
// as the decimal fraction 100.0, 10.00, 1.000, etc.
//
// This property can be used to replace heavy floating?point operations
// on platforms that do not have an FPU hardware block.
//
// Attention! When working with FDPN, it is important to remember
// the possibilities of overflow!
// If it is difficult to track overflows,
// use types with a larger range (int32_t or int64_t).
//
// The library contains functions for converting numbers
// with a fixed decimal point to ASCII strings and vice versa.
//
// ===============================================================================


#ifndef FDPN_H_
#define FDPN_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>



// ===============================================================================



char *FDPN_Int16Base_Convert_Number_To_String
(
	char *string_buffer,
	
	int16_t number,
	
	const int8_t num_int_digits,
	const int8_t num_fract_digits,
	const char decimal_separator
);

int16_t FDPN_Int16Base_Convert_String_To_Number
(
	const char *string,
	
	const uint8_t max_string_len
);



// ===============================================================================



char *FDPN_Int32Base_Convert_Number_To_String
(
	char *string_buffer,
	
	int32_t number,
	
	const int8_t num_int_digits,
	const int8_t num_fract_digits,
	const char decimal_separator
);

int32_t FDPN_Int32Base_Convert_String_To_Number
(
	const char *string,
	
	const uint8_t max_string_len
);



// ===============================================================================





#ifdef NUM_64BIT_SUPPORT


#include <limits.h>




char *FDPN_Int64Base_Convert_Number_To_String
(
	char *string_buffer,
	
	int64_t number,
	
	const int8_t num_int_digits,
	const int8_t num_fract_digits,
	const char decimal_separator
);

int64_t FDPN_Int64Base_Convert_String_To_Number
(
	const char *string,
	
	const uint8_t max_string_len
);


#endif






#endif






