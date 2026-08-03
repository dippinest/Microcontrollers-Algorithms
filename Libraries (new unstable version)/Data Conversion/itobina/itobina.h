

// ===============================================================================
//
// Библиотека для преобразования различных числовых типов данных в строки
// C-типа (в двоичном виде)
//
// -------------------------------------------------------------------------------
//
// Library for converting various numeric data types into C-type strings
// (in binary form)
//
// ===============================================================================


#ifndef ITOBINA_H_
#define ITOBINA_H_

#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>


// ===============================================================================



char *ITOBINA_8bitNum_To_BinString(char *string_buffer, uint8_t val);

char *ITOBINA_16bitNum_To_BinString(char *string_buffer, uint16_t val);

char *ITOBINA_32bitNum_To_BinString(char *string_buffer, uint32_t val);



#ifdef NUM_64BIT_SUPPORT

char *ITOBINA_64bitNum_To_BinString(char *string_buffer, uint64_t val);

#endif



#endif




