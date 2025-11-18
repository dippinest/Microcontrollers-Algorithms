

// ===============================================================================
//
// Эта библиотека расширяет возможности стандартной библиотеки string.h
// и позволяет работать со строками на более высоком уровне.
// Строки по-прежнему представляют собой обычные массивы символов
// фиксированной длины, однако благодаря этой библиотеке их обработка
// становится существенно проще.
//
// Библиотека включает в себя как более удобные аналоги функций
// стандартной библиотеки string.h, так и новые функции для различных
// манипуляций со строками.
//
// Функции библиотеки не используют динамическую память для своей работы,
// поэтому может без ограничений использоваться в различных embedded системах
// (при этом пользователь всё же должен внимательно следить за размерами
// передаваемых в функции буферов для корректной работы!)
//
// -------------------------------------------------------------------------------
//
// This library extends the capabilities of the standard
// string.h library and allows you to work with strings at a higher level.
// Strings are still regular arrays of fixed-length characters, but thanks
// to this library, their processing becomes much easier.
//
// The library includes both more convenient analogues of the functions
// of the standard string.h library, as well as new functions and new functions
// for various string manipulations.
//
// The library functions do not use dynamic memory for their work,
// so they can be used without restrictions in various embedded systems
// (while the user still needs to carefully monitor the size of the buffers
// passed to the function for correct operation!)
//
// ===============================================================================


#ifndef STRX_H_
#define STRX_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


// ===============================================================================



inline bool STRX_Char_Is_Letter(const char ch)
{
	return (bool)isalpha(ch);
}

inline bool STRX_Char_Is_Digit(const char ch)
{
	return (bool)isdigit(ch);
}

inline bool STRX_Char_Is_HEXDigit(const char ch)
{
	return (bool)isxdigit(ch);
}

inline bool STRX_Char_Is_Letter_Or_Digit(const char ch)
{
	return (bool)isalnum(ch);
}

inline bool STRX_Char_Is_Whitespace_Or_HTab(const char ch)
{
	return (bool)isblank(ch);
}

inline bool STRX_Char_Is_Control_Char_CNTRL(const char ch)
{
	return (bool)iscntrl(ch);
}

inline bool STRX_Char_Is_Printable(const char ch)
{
	return (bool)isprint(ch);
}

inline bool STRX_Char_Is_Printable_And_Not_Whitespace(const char ch)
{
	return (bool)isgraph(ch);
}

inline bool STRX_Char_Is_Space(const char ch)
{
	return (bool)isspace(ch);
}

inline bool STRX_Char_Is_Punctuation_Mark(const char ch)
{
	return (bool)ispunct(ch);
}

inline bool STRX_Char_Is_Upper_Case(const char ch)
{
	return (bool)isupper(ch);
}

inline bool STRX_Char_Is_Lower_Case(const char ch)
{
	return (bool)isupper(ch);
}

inline char STRX_Convert_Char_To_Upper_Case(const char ch)
{
	return (char)toupper(ch);
}

inline char STRX_Convert_Char_To_Lower_Case(const char ch)
{
	return (char)tolower(ch);
}



// ===============================================================================



uint8_t STRX_Convert_Digit_Char_To_Digit(const char ch);

char STRX_Convert_Digit_To_Digit_Char(const uint8_t digit);


// если символ отсутствует в наборе, функция вернёт значение -1
//
// -------------------------------------------------------------------------------
// if the character is missing from the set, the function returns the value -1
//
int8_t STRX_Get_Char_Pos_In_Latin_Alphabet(const char ch);



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



uint16_t STRX_Get_String_Size(const char *str);

uint16_t STRX_Get_String_Size_Safe(const char *str, const uint16_t str_max_size);

char *STRX_String_Copy(char *dest_str, const char *source_str);

char *STRX_String_Copy_Safe(char *dest_str, const char *source_str, const uint16_t dest_str_max_size);

char *STRX_Get_String_Reverse(char *str);

char *STRX_Get_String_Reverse_Safe(char *str, const uint16_t str_size);

char *STRX_Convert_String_To_Upper_Case(char *str);

char *STRX_Convert_String_To_Upper_Case_Safe(char *str, const uint16_t str_size);

char *STRX_Convert_String_To_Lower_Case(char *str);

char *STRX_Convert_String_To_Lower_Case_Safe(char *str, const uint16_t str_size);

char *STRX_Invert_String_Case(char *str);

char *STRX_Invert_String_Case_Safe(char *str, const uint16_t str_size);



// ===============================================================================



char *STRX_Delete_All_Extra_Symbols(char *str, const char extra_symbol);

char *STRX_Delete_All_Extra_Symbols_From_Set(char *str, const char *extra_symbols_set);

char *STRX_Delete_All_Extra_Symbols_Within_Specified_Boundaries
(
	char *str,
	const char extra_symbol,
	const uint16_t begin_pos,
	uint16_t end_pos
);

char *STRX_Delete_All_Extra_Symbols_From_Set_Within_Specified_Boundaries
(
	char *str,
	const char *extra_symbols_set,
	const uint16_t begin_pos,
	uint16_t end_pos
);



// ===============================================================================



uint16_t STRX_Get_Num_Of_Symbol_Occurrences(const char *str, const char symbol);

uint16_t STRX_Get_Num_Of_Symbols_Occurrences_From_Set(const char *str, const char *symbols_set);


// если символ отсутствует в строке, функция вернёт значение -1
//
// -------------------------------------------------------------------------------
// if the character is missing from the string, the function returns the value -1
//
int16_t STRX_Find_Index_Of_First_Symbol_Occurrences(const char *str, const char symbol);


// если символы отсутствует из набора отсутствуют в строке,
// функция вернёт значение -1
//
// -------------------------------------------------------------------------------
// if the characters missing from the set are missing from the string,
// the function returns the value -1
//
int16_t STRX_Find_Index_Of_First_Any_Symbol_Occurrences_From_Set(const char *str, const char *symbols_set);



// ===============================================================================



char *STRX_Trim_All_Extra_Symbols(char *str, const char symbol);

char *STRX_Trim_All_Left_Extra_Symbols(char *str, const char symbol);

char *STRX_Trim_All_Right_Extra_Symbols(char *str, const char symbol);

char *STRX_Trim_All_Extra_Symbols_To_Tagret_Symbol(char *str, const char target_symbol);

char *STRX_Trim_All_Extra_Symbols_After_Tagret_Symbol(char *str, const char target_symbol);

char *STRX_Replace_All_Symbols(char *str, const char old_symbol, const char new_symbol);

char *STRX_Replace_All_Symbols_To_Tagret_Symbol
(
	char *str,
	const char old_symbol,
	const char new_symbol,
	const char target_symbo
);

char *STRX_Replace_All_Symbols_After_Tagret_Symbol
(
	char *str,
	const char old_symbol,
	const char new_symbol,
	const char target_symbol
);



// ===============================================================================



char *STRX_Delete_All_Dublicate_Symbols_In_Row(char *str, const char symbol);

char *STRX_Delete_All_Substrings(char *str, const char *substr);

char *STRX_Delete_Substring_Within_Specified_Boundaries(char *str, const uint16_t begin_pos, const uint16_t end_pos);

char *STRX_Insert_Substring_By_Pos(char *str, const char *substr, uint16_t insert_pos);

char *STRX_Fill_Char_Within_Specified_Boundaries(char *str, const char placeholder_ch, const uint16_t begin_pos, uint16_t end_pos);


// если указанной подстроки в строке нет, функция вернёт значение -1
//
// -------------------------------------------------------------------------------
// if there is no specified substring in the string,
// the function returns the value -1
//
int16_t STRX_Get_First_Substring_Occurrence_Index(char *str, const char *substr);

uint16_t STRX_Get_Num_Of_Substring_Occurrences(char *str, const char *substr);

char *STRX_Replace_Substring(char *str, char *result_str, const char *old_substr, const char *new_substr);



// ===============================================================================



uint16_t STRX_Split_Into_Tokens
(
	char *str,
	const char delim_symbol,
	uint16_t *tokens_indexes,
	const uint16_t max_num_of_tokens,
	const bool split_with_null_terminated_symbol
);

uint16_t STRX_Split_Into_Tokens_Using_Delimiters_Set
(
	char *str,
	const char *delim_set,
	uint16_t *tokens_indexes,
	const uint16_t max_num_of_tokens,
	const bool split_with_null_terminated_symbol
);


#endif






