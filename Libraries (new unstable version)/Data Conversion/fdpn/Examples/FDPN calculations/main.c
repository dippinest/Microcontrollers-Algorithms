

#include <stdio.h>
#include <stdint.h>

#include "fdpn.h"



#define MAX_STRBUF_LEN 16

char string_buffer[MAX_STRBUF_LEN];



// вспомогательные функции для вывода FDPN
//
// -------------------------------------------------------------------------------
// auxiliary functions for FDPN output
//
void print_FDPN_Int16Base_Number(const char* msg, int16_t fdpn, const int8_t num_int_digits, const int8_t num_fract_digits)
{
    printf("%s = \"%s\"\n\n", msg, FDPN_Int16Base_Convert_Number_To_String(string_buffer, fdpn, num_int_digits, num_fract_digits, '.'));
}

void print_FDPN_Int32Base_Number(const char* msg, int32_t fdpn, const int8_t num_int_digits, const int8_t num_fract_digits)
{
    printf("%s = \"%s\"\n\n", msg, FDPN_Int32Base_Convert_Number_To_String(string_buffer, fdpn, num_int_digits, num_fract_digits, '.'));
}



void main()
{
    // ASCII строки с представлением FDPN числами
    //
    // -------------------------------------------------------------------------------
    // ASCII strings with FDPN representation by numbers
    //
    const char d1[] = "-230.5";
    const char d2[] = "20.6";



    // преобразование ASCII строк в FDPN числа
    //
    // -------------------------------------------------------------------------------
    // converting ASCII strings to FDPN numbers
    //
    int16_t fdpn_1 = FDPN_Int16Base_Convert_String_To_Number(d1, MAX_STRBUF_LEN);
    int16_t fdpn_2 = FDPN_Int16Base_Convert_String_To_Number(d2, MAX_STRBUF_LEN);





    // сложение двух FDPN чисел (операцию можно также осуществлять с константой)
    //
    // -------------------------------------------------------------------------------
    // adding two FDPN numbers
    // (the operation can also be performed with a constant)
    //
    int16_t fdpn_sum = fdpn_1 + fdpn_2;

    print_FDPN_Int16Base_Number("FDPN_Int16Base Sum", fdpn_sum, 6, 2);





    // вычитание двух FDPN чисел (операцию можно также осуществлять с константой)
    //
    // -------------------------------------------------------------------------------
    // subtracting two FDPN numbers
    // (the operation can also be performed with a constant)
    //
    int16_t fdpn_diff = fdpn_1 - fdpn_2;

    print_FDPN_Int16Base_Number("FDPN_Int16Base Diff", fdpn_diff, 6, 2);





    // примеры операций умножения и деления.
    // 
    // Внимательно следите за смещением десятичного разделителя и помните
    // о возможной потери точности в этих операциях!
    // 
    // С целью предотвращения переполнения используется FDPN с диапазоном 32 бит
    //
    // -------------------------------------------------------------------------------
    // examples of multiplication and division operations.
    // 
    // Pay close attention to the shift of the decimal point
    // and remember that these operations may result in a loss of precision!
    //
    // To prevent overflow, an FDPN with a 32‑bit range is used.
    //


    // умножение двух FDPN чисел
    // (операцию можно также осуществлять с константой)
    //
    // -------------------------------------------------------------------------------
    // multiplying two FDPN numbers
    // (the operation can also be performed with a constant)
    //
    int32_t fdpn_mul = (int32_t)fdpn_1 * (int32_t)fdpn_2;

    print_FDPN_Int32Base_Number("FDP_Int32Base Mul", fdpn_mul, 6, 2);






    // деление двух FDPN чисел
    // (операцию можно также осуществлять с константой)
    //
    // -------------------------------------------------------------------------------
    // division of two FDPN numbers
    // (the operation can also be performed with a constant)
    //
    int32_t fdpn_div = (int32_t)fdpn_1 / (int32_t)fdpn_2;


    // корректируем смещение десятичного разделителя
    //
    // -------------------------------------------------------------------------------
    // adjusting the offset of the decimal separator
    //
    fdpn_div *= 100;


    print_FDPN_Int32Base_Number("FDP_Int32Base Div", fdpn_div, 6, 2);
}




