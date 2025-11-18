
#include <stdio.h>
#include <stdint.h>

#include "strx.h"



// пример строки
// 
// -------------------------------------------------------------------------------
// string example
//
char str[] = "  Hello, world!     ";


// буфер для модифицированной строки
// // (размер буфера должен соответствовать или быть больше размера изменённой строки!)
// 
// -------------------------------------------------------------------------------
// buffer for the modified string
// (the buffer size must match or be greater than the size of the modified string!)
//
char str_buffer[256];


int main()
{
	printf("String: \"%s\"\n\n", str);


	// удаление всех символов пробела слева и справа
	// 
	// -------------------------------------------------------------------------------
	// removing all space characters on the left and right
	//
	STRX_Trim_All_Extra_Symbols(str, ' ');

	printf("Trim string: \"%s\"\n\n", str);


	// замена одной подстроки на другую
	// 
	// -------------------------------------------------------------------------------
	// replacing one substring with another
	//
	STRX_Replace_Substring(str, str_buffer, "Hello", "Hi");

	printf("String modificated (1): \"%s\"\n\n", str_buffer);


	// удаление всех включений подстроки
	// 
	// -------------------------------------------------------------------------------
	// removing all substring inclusions
	//
	STRX_Delete_All_Substrings(str_buffer, "world");

	printf("String modificated (2): \"%s\"\n\n", str_buffer);


	// вставка подстроки на позицию 4
	// 
	// -------------------------------------------------------------------------------
	// inserting a substring at position 4
	//
	STRX_Insert_Substring_By_Pos(str_buffer, "all world", 4);

	printf("String modificated (3): \"%s\"\n\n", str_buffer);
}



