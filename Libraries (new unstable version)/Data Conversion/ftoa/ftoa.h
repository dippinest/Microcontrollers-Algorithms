

// ===============================================================================
//
// Библиотека для преобразования чисел типа float32 (IEEE 754) в строки C-типа
//
// -------------------------------------------------------------------------------
//
// Library for converting float32 (IEEE 754) numbers to C-type strings
//
// ===============================================================================


#ifndef FTOA_H_
#define FTOA_H_

#include <stdint.h>
#include <stdlib.h>
#include <math.h>



// ===============================================================================



char *FTOA_Float32_To_String(char *string_buffer, float val, int8_t num_int_digits, int8_t num_fract_digits, const char separator);



#endif


