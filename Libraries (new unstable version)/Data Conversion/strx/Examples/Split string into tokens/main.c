
#include <stdio.h>
#include <stdint.h>

#include "strx.h"



// пример строки
//
// -------------------------------------------------------------------------------
// string example
//
char str[] = "  3, 4, -1.76,   5.76, String";


int main()
{
	printf("String: \"%s\"\n\n", str);


	// удаление всех символов пробела в строке
	//
	// -------------------------------------------------------------------------------
	// deleting all space characters in a string
	//
	STRX_Delete_All_Extra_Symbols(str, ' ');

	printf("Trimmed string: \"%s\"\n\n", str);


	// массив индексов (указателей) на токены
	//
	// -------------------------------------------------------------------------------
	// an array of indexes (pointers) to tokens
	//
	uint16_t tokens_indexes[20];


	// разбиение строки на токены с разделителем ','.
	// Максимальное число токенов - 20.
	//
	// Строка модифицируется, разделив токены символом нуль-терминатора '\0'
	//
	// -------------------------------------------------------------------------------
	// splitting a string into tokens separated by ','.
	// The maximum number of tokens is 20.
	//
	// The string is modified by separating the tokens
	// with the null terminator character '\0'
	//
	uint16_t n = STRX_Split_Into_Tokens(str, ',', tokens_indexes, 20, true);


	// вывод всех токенов на печать
	//
	// -------------------------------------------------------------------------------
	// printing of all tokens
	//
	printf("Num of tokens: %d\n\n", n);

	for (uint16_t i = 0; i < n; ++i)
	{
		printf(">>> Token %d: \"%s\"\n", i, (str + tokens_indexes[i]));
	}
}




