

// ===============================================================================
//
// Библиотека генератора псевдослучайных чисел на основе изменяемого массива
// (MAPRNG - Mutable Array Pseudo-Random Number Generator).
//
// Функции библиотеки позволяют получать псевдослучайные числа в диапазоне
// 8, 16 и 32 бита (а также числа в установленном диапазоне), используя
// изменяемый массив с адресами от 0x00 до max_addr.
// В качестве изменяемого массива можно использовать участок памяти любого типа
// (внутренняя или внешняя RAM, EEPROM и т.д.). Работа с памятью описывается
// с помощью коллбэк функций.
//
// -------------------------------------------------------------------------------
//
// Library for a pseudo-random number generator based on a mutable array
// (MAPRNG - Mutable Array Pseudo-Random Number Generator).
//
// The library functions allow you to get pseudorandom numbers in the range
// of 8, 16, and 32 bits (as well as numbers in the specified range) using
// a mutable array with addresses from 0x00 to max_addr.
// The main memory location is also set in the
// function parameters.
//
// ===============================================================================


#ifndef MAPRNG_H_
#define MAPRNG_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct
{
	uint16_t init_addr;
	uint16_t max_addr;
	uint8_t  last_value;

	uint8_t (*read_byte)(uint16_t addr);
	void    (*write_byte)(uint16_t addr, uint8_t b);

} MAPRNG_t;

// ===============================================================================

MAPRNG_t MAPRNG_Create_Object(uint8_t init_value, uint16_t init_addr, uint16_t max_addr, uint8_t(*read_byte)(uint16_t addr), void (*write_byte)(uint16_t addr, uint8_t b));

// ===============================================================================

uint8_t MAPRNG_Get_8Bit_Value(MAPRNG_t* maprng);

uint16_t MAPRNG_Get_16Bit_Value(MAPRNG_t* maprng);

uint32_t MAPRNG_Get_32Bit_Value(MAPRNG_t* maprng);

// ===============================================================================

bool MAPRNG_Get_Bool_Value(MAPRNG_t* maprng);

uint8_t MAPRNG_Get_UInt8_Value(MAPRNG_t* maprng, uint8_t min, uint8_t max);

int8_t MAPRNG_Get_Int8_Value(MAPRNG_t* maprng, int8_t min, int8_t max);

uint16_t MAPRNG_Get_UInt16_Value(MAPRNG_t* maprng, uint16_t min, uint16_t max);

int16_t MAPRNG_Get_Int16_Value(MAPRNG_t* maprng, int16_t min, int16_t max);

uint32_t MAPRNG_Get_UInt32_Value(MAPRNG_t* maprng, uint32_t min, uint32_t max);

int32_t MAPRNG_Get_Int32_Value(MAPRNG_t* maprng, int32_t min, int32_t max);


#endif





