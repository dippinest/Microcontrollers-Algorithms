

// ===============================================================================
//
// Библиотека для преобразования различных числовых типов данных в строки
// C-типа (в шестнадцетиричном виде)
//
// -------------------------------------------------------------------------------
//
// Library for converting various numeric data types into C-type strings
// (in hexadecimal form)
//
// ===============================================================================


#ifndef ITOHEXA_H_
#define ITOHEXA_H_

#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


// ===============================================================================


void ITOHEXA_Set_String_Buffer(char *string_buffer_ptr);

char *ITOHEXA_Set_String_Buffer_To_Dynamic_Memory(const uint8_t string_buffer_size);

void ITOHEXA_Delete_String_Buffer_From_Dynamic_Memory();


// ===============================================================================


char *ITOHEXA_8bitNum_To_HexString(uint8_t val, bool is_lower_case);

char *ITOHEXA_16bitNum_To_HexString(uint16_t val, bool is_lower_case);

char *ITOHEXA_32bitNum_To_HexString(uint32_t val, bool is_lower_case);


#ifdef NUM_64BIT_SUPPORT

char *ITOHEXA_64bitNum_To_HexString(uint64_t val, bool is_lower_case);

#endif


#endif


