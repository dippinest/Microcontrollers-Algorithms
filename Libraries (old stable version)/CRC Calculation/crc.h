

// ===============================================================================
//
// Библиотека для расчёта различных видов CRC
//
// -------------------------------------------------------------------------------
//
// Library for calculating various types of CRC
//
// ===============================================================================


#ifndef CRC_H_
#define CRC_H_

#include <stdint.h>
#include <stdbool.h>

#define CRC_REFIN_LSB_FIRST       true
#define CRC_REFiN_MSB_FIRST       false

#define CRC_REFOUT_INVERT_CRC     true
#define CRC_REFOUT_NOT_INVERT_CRC false



// "polynomial" is a constant value for calculating CRC
// "initial"    is a CRC value at the beginning
// "refin"      indicates the beginning and direction of the calculations
// "refout"     determines whether the order of the register bits is inverted when entering the XOR element
// "xor_out"    the value with which the resulting result is added modulo 2 (XOR op)

uint8_t CRC8_Get_Value(void *data, uint16_t data_size, uint8_t polynomial, uint8_t initial, bool refin, bool refout, uint8_t xor_out);

uint16_t CRC16_Get_Value(void *data, uint16_t data_size, uint16_t polynomial, uint16_t initial, bool refin, bool refout, uint16_t xor_out);

uint32_t CRC32_Get_Value(void *data, uint16_t data_size, uint32_t polynomial, uint32_t initial, bool refin, bool refout, uint32_t xor_out);


#ifdef NUM_64BIT_SUPPORT

uint64_t CRC64_Get_Value(void* data, uint16_t data_size, uint64_t polynomial, uint64_t initial, bool refin, bool refout, uint64_t xor_out);

#endif

#endif


