

#include <stdio.h>
#include <stdint.h>

#include "fdp.h"



#define MAX_STRBUF_LEN 16

char string_buffer[MAX_STRBUF_LEN];



// вспомогательные функции для вывода FDP
//
// -------------------------------------------------------------------------------
// auxiliary functions for FDP output
//
void print_FDP_Int16Base_Number(const char *msg, int16_t fdp, const int8_t num_int_digits, const int8_t num_fract_digits)
{
    printf("%s = \"%s\"\n\n", msg, FDP_Int16Base_Convert_Number_To_String(string_buffer, fdp, num_int_digits, num_fract_digits, '.'));
}

void print_FDP_Int32Base_Number(const char* msg, int32_t fdp, const int8_t num_int_digits, const int8_t num_fract_digits)
{
    printf("%s = \"%s\"\n\n", msg, FDP_Int32Base_Convert_Number_To_String(string_buffer, fdp, num_int_digits, num_fract_digits, '.'));
}



void main()
{
    // ASCII строки с представлением FDP числами
    //
    // -------------------------------------------------------------------------------
    // ASCII strings with FDP representation by numbers
    //
    const char d1[] = "-230.5";
    const char d2[] =   "20.6";



    // преобразование ASCII строк в FDP числа
    //
    // -------------------------------------------------------------------------------
    // converting ASCII strings to FDP numbers
    //
    int16_t fdp_1 = FDP_Int16Base_Convert_String_To_Number(d1, MAX_STRBUF_LEN);
    int16_t fdp_2 = FDP_Int16Base_Convert_String_To_Number(d2, MAX_STRBUF_LEN);





    // сложение двух FDP чисел (операцию можно также осуществлять с константой)
    //
    // -------------------------------------------------------------------------------
    // adding two FDP numbers
    // (the operation can also be performed with a constant)
    //
    int16_t fdp_sum = fdp_1 + fdp_2;

    print_FDP_Int16Base_Number("FDP_Int16Base Sum", fdp_sum, 6, 2);





    // вычитание двух FDP чисел (операцию можно также осуществлять с константой)
    //
    // -------------------------------------------------------------------------------
    // subtracting two FDP numbers
    // (the operation can also be performed with a constant)
    //
    int16_t fdp_diff = fdp_1 - fdp_2;

    print_FDP_Int16Base_Number("FDP_Int16Base Diff", fdp_diff, 6, 2);





    // примеры операций умножения и деления.
    // 
    // Внимательно следите за смещением десятичного разделителя и помните
    // о возможной потери точности в этих операциях!
    // 
    // С целью предотвращения переполнения используется FDP с диапазоном 32 бит
    //
    // -------------------------------------------------------------------------------
    // examples of multiplication and division operations.
    // 
    // Pay close attention to the shift of the decimal point
    // and remember that these operations may result in a loss of precision!
    //
    // To prevent overflow, an FDP with a 32‑bit range is used.
    //


    // умножение двух FDP чисел
    // (операцию можно также осуществлять с константой)
    //
    // -------------------------------------------------------------------------------
    // multiplying two FDP numbers
    // (the operation can also be performed with a constant)
    //
    int32_t fdp_mul = (int32_t)fdp_1 * (int32_t)fdp_2;

    print_FDP_Int32Base_Number("FDP_Int32Base Mul", fdp_mul, 6, 2);






    // деление двух FDP чисел
    // (операцию можно также осуществлять с константой)
    //
    // -------------------------------------------------------------------------------
    // division of two FDP numbers
    // (the operation can also be performed with a constant)
    //
    int32_t fdp_div = (int32_t)fdp_1 / (int32_t)fdp_2;


    // корректируем смещение десятичного разделителя
    //
    // -------------------------------------------------------------------------------
    // adjusting the offset of the decimal separator
    //
    fdp_div *= 100;


    print_FDP_Int32Base_Number("FDP_Int32Base Div", fdp_div, 6, 2);
}




