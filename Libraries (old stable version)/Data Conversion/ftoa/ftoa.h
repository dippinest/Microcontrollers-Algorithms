

// ===============================================================================
//
// Библиотека для преобразования числа типа float32 (IEEE 754) в строку C-типа
//
// -------------------------------------------------------------------------------
//
// Library for converting float32 (IEEE 754) number to C-type string
//
// ===============================================================================


#ifndef FTOA_H_
#define FTOA_H_

#include <stdint.h>
#include <stdlib.h>
#include <math.h>


// ===============================================================================


void FTOA_Set_String_Buffer(char *string_buffer_ptr);

char *FTOA_Set_String_Buffer_To_Dynamic_Memory(const uint8_t string_buffer_size);

void FTOA_Delete_String_Buffer_From_Dynamic_Memory();


// ===============================================================================


char *FTOA_Get_String_Buffer_Ptr();


// ===============================================================================


char* FTOA_Float32_To_String(float val, int8_t num_int_digits, int8_t num_fract_digits);



#endif


