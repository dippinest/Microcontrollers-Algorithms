
#include <stdio.h>
#include <stdint.h>

#include "strx.h"



// пример строки с логом данных
// 
// -------------------------------------------------------------------------------
// example of a row with a data log
//
char log_string[] = "2026/07/10 10:23:00 -> Temp: 23.1 *C; Humidity: 73%; Pressue: 741 mmHg; WS: 3 m/s (S-W)";


int main()
{
    printf("Original log test     : \"%s\"\n\n", log_string);


    // пример использования функции ROT13 для обсфукации
    // (кодируются только символы латинских букв)
    // 
    // -------------------------------------------------------------------------------
    // example of using the ROT13 function for obfuscation
    // (only Latin letter characters are encoded)
    //
    STRX_Obfuscate_String_ROT13(log_string);


    printf("Obfuscate log (ROT13) : \"%s\"\n\n", log_string);


    // деобфускация строки
    // 
    // -------------------------------------------------------------------------------
    // string deobfuscation
    //
    STRX_Obfuscate_String_ROT13(log_string);

    printf("Restored log (orig)   : \"%s\"\n\n", log_string);



    printf("\n\n\n");



    printf("Original log test     : \"%s\"\n\n", log_string);


    // пример использования функции ROT47 для обсфукации
    // (кодируются все печатные символы)
    // 
    // -------------------------------------------------------------------------------
    // example of using the ROT47 function for obfuscation
    // (all printed characters are encoded)
    //
    STRX_Obfuscate_String_ROT47(log_string);


    printf("Obfuscate log (ROT47) : \"%s\"\n\n", log_string);


    // деобфускация строки
    // 
    // -------------------------------------------------------------------------------
    // string deobfuscation
    //
    STRX_Obfuscate_String_ROT47(log_string);

    printf("Restored log (orig)   : \"%s\"\n\n", log_string);
}


