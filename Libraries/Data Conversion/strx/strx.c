

#include "strx.h"



uint8_t STRX_Convert_Digit_Char_To_Digit(const char ch)
{
	if (isdigit(ch))
	{
		return (ch & 0xF);
	}

	return 0;
}


char STRX_Convert_Digit_To_Digit_Char(const uint8_t digit)
{
	return (char)((digit % 10) + 0x30);
}


int8_t STRX_Get_Char_Pos_In_Latin_Alphabet(const char ch)
{
	char c = toupper(ch);

	if ((c < 0x41) || (c > 0x5A))
	{
		return -1;
	}

	return (int8_t)(c - 0x41);
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



uint16_t STRX_Get_String_Size(const char* str)
{
	uint16_t str_size = 0;

	while (str[str_size] != '\0')
	{
		++str_size;
	}

	return str_size;
}


uint16_t STRX_Get_String_Size_Safe(const char *str, const uint16_t str_max_size)
{
	uint16_t str_size = 0;

	while ((str[str_size] != '\0') && (str_size < str_max_size))
	{
		++str_size;
	}

	return str_size;
}


char *STRX_String_Copy(char *dest_str, const char *source_str)
{
	uint16_t i = 0;

	while (source_str[i] != '\0')
	{
		dest_str[i] = source_str[i]; ++i;
	}

	dest_str[i] = '\0';

	return dest_str;
}


char *STRX_String_Copy_Safe(char *dest_str, const char *source_str, const uint16_t dest_str_max_size)
{
	uint16_t i = 0;

	while ((source_str[i] != '\0') && (i < dest_str_max_size))
	{
		dest_str[i] = source_str[i]; ++i;
	}

	dest_str[i] = '\0';


	return dest_str;
}


char *STRX_Get_String_Reverse(char *str)
{
	char tmp;

	uint16_t str_size = strlen(str);

	if (str_size == 0)
	{
		return str;
	}


	for (uint16_t i = 0, j = (str_size - 1); i < (str_size >> 1) || j > (str_size >> 1); ++i, --j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}

	return str;
}


char *STRX_Get_String_Reverse_Safe(char *str, const uint16_t str_size)
{
	char tmp;

	if (str_size == 0)
	{
		return str;
	}

	for (uint16_t i = 0, j = (str_size - 1); (i < (str_size >> 1)) || (j > (str_size >> 1)); ++i, --j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}

	return str;
}


char *STRX_Convert_String_To_Upper_Case(char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		str[i] = toupper(str[i]);
	}

	return str;
}


char *STRX_Convert_String_To_Upper_Case_Safe(char *str, const uint16_t str_size)
{
	for (uint16_t i = 0; (str[i] != '\0') && (i < str_size); ++i)
	{
		str[i] = toupper(str[i]);
	}

	return str;
}


char *STRX_Convert_String_To_Lower_Case(char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		str[i] = tolower(str[i]);
	}

	return str;
}


char *STRX_Convert_String_To_Lower_Case_Safe(char *str, const uint16_t str_size)
{
	for (uint16_t i = 0; (str[i] != '\0') && (i < str_size); ++i)
	{
		str[i] = tolower(str[i]);
	}

	return str;
}


char *STRX_Invert_String_Case(char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
		else
		{
			str[i] = toupper(str[i]);
		}
	}

	return str;
}


char *STRX_Invert_String_Case_Safe(char *str, const uint16_t str_size)
{
	for (uint16_t i = 0; (str[i] != '\0') && (i < str_size); ++i)
	{
		if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
		else
		{
			str[i] = toupper(str[i]);
		}
	}

	return str;
}



// ===============================================================================



char *STRX_Delete_All_Extra_Symbols(char *str, const char extra_symbol)
{
	if (strlen(str) == 0)
	{
		return str;
	}

	uint16_t i = 0;
	uint16_t j = 0;

	while (str[i] != '\0')
	{
		if (str[i] != extra_symbol)
		{
			str[j] = str[i]; ++j;
		}

		++i;
	}

	str[j] = '\0';


	return str;
}


char *STRX_Delete_All_Extra_Symbols_From_Set(char *str, const char *extra_symbols_set)
{
	if ((strlen(str) == 0) || (strlen(extra_symbols_set) == 0))
	{
		return str;
	}

	uint16_t i, j;

	for (uint16_t k = 0; extra_symbols_set[k] != '\0'; ++k)
	{
		i = 0;
		j = 0;

		while (str[i] != '\0')
		{
			if (str[i] != extra_symbols_set[k])
			{
				str[j] = str[i]; ++j;
			}

			++i;
		}

		str[j] = '\0';
	}


	return str;
}


char *STRX_Delete_All_Extra_Symbols_Within_Specified_Boundaries
(
	char *str,
	const char extra_symbol,
	const uint16_t begin_pos,
	uint16_t end_pos
)
{
	uint16_t str_size = strlen(str);

	if ((str_size == 0) || (begin_pos >= end_pos) || (begin_pos > str_size))
	{
		return str;
	}

	uint16_t i = begin_pos;
	uint16_t j = begin_pos;

	while (str[i] != '\0')
	{
		if (i < end_pos)
		{
			if (str[i] != extra_symbol)
			{
				str[j] = str[i]; ++j;
			}
		}
		else
		{
			str[j] = str[i]; ++j;
		}

		++i;
	}

	str[j] = '\0';


	return str;
}


char *STRX_Delete_All_Extra_Symbols_From_Set_Within_Specified_Boundaries
(
	char *str,
	const char *extra_symbols_set,
	const uint16_t begin_pos,
	uint16_t end_pos
)
{
	uint16_t str_size = strlen(str);

	if ((str_size == 0) || (strlen(str) == 0) || (begin_pos >= end_pos) || (begin_pos > str_size))
	{
		return str;
	}

	uint16_t i, j;

	for (uint16_t k = 0; extra_symbols_set[k] != '\0'; ++k)
	{
		i = begin_pos;
		j = begin_pos;

		while (str[i] != '\0')
		{
			if (i < end_pos)
			{
				if (str[i] != extra_symbols_set[k])
				{
					str[j] = str[i]; ++j;
				}
			}
			else
			{
				str[j] = str[i]; ++j;
			}

			++i;
		}

		str[j] = '\0';
	}


	return str;
}



// ===============================================================================



uint16_t STRX_Get_Num_Of_Symbol_Occurrences(const char *str, const char symbol)
{
	uint16_t num_of_occurrences = 0;

	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == symbol)
		{
			++num_of_occurrences;
		}
	}

	return num_of_occurrences;
}


uint16_t STRX_Get_Num_Of_Symbols_Occurrences_From_Set(const char *str, const char *symbols_set)
{
	uint16_t num_of_occurrences = 0;

	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		for (uint16_t j = 0; symbols_set[j] != '\0'; ++j)
		{
			if (str[i] == symbols_set[j])
			{
				++num_of_occurrences;
			}
		}
	}

	return num_of_occurrences;
}


int16_t STRX_Find_Index_Of_First_Symbol_Occurrences(const char *str, const char symbol)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == symbol)
		{
			return i;
		}
	}

	return -1;
}


int16_t STRX_Find_Index_Of_First_Any_Symbol_Occurrences_From_Set(const char *str, const char *symbols_set)
{
	for (int16_t i = 0; str[i] != '\0'; ++i)
	{
		for (int16_t j = 0; symbols_set[j] != '\0'; ++j)
		{
			if (str[i] == symbols_set[j])
			{
				return i;
			}
		}
	}

	return -1;
}



// ===============================================================================



char *STRX_Trim_All_Extra_Symbols(char *str, const char symbol)
{
	int16_t i = 0;
	int16_t j = 0;

	while ((str[i] == symbol) && (i <= strlen(str)))
	{
		++i;
	}

	if ((i > 0) && (i <= strlen(str)))
	{
		for (j = 0; j < strlen(str); j++)
		{
			str[j] = str[j + i];
		}

		str[j] = '\0';
	}


	i = strlen(str) - 1;

	while ((str[i] == symbol))
	{
		--i;
	}

	if ((i < (strlen(str) - 1)) && (i > 0))
	{
		str[i + 1] = '\0';
	}

	return str;
}


char *STRX_Trim_All_Left_Extra_Symbols(char *str, const char symbol)
{
	int16_t i = 0;
	int16_t j = 0;

	while ((str[i] == symbol) && (i <= strlen(str)))
	{
		++i;
	}

	if ((i > 0) && (i <= strlen(str)))
	{
		for (j = 0; j < strlen(str); j++)
		{
			str[j] = str[j + i];
		}

		str[j] = '\0';
	}

	return str;
}


char *STRX_Trim_All_Right_Extra_Symbols(char *str, const char symbol)
{
	if (strlen(str) == 0)
	{
		return str;
	}

	uint16_t i = strlen(str) - 1;

	while ((str[i] == symbol) && (i > 0))
	{
		--i;
	}

	if ((i < (strlen(str) - 1)) && (i > 0))
	{
		str[i + 1] = '\0';
	}

	return str;
}


char *STRX_Trim_All_Extra_Symbols_To_Tagret_Symbol(char *str, const char target_symbol)
{
	int16_t i = 0;
	int16_t j = 0;

	while ((str[i] != target_symbol) && (i <= strlen(str)))
	{
		++i;
	}

	if ((i > 0) && (i <= strlen(str)))
	{
		for (j = 0; j < strlen(str); j++)
		{
			str[j] = str[j + i];
		}

		str[j] = '\0';
	}

	return str;
}


char *STRX_Trim_All_Extra_Symbols_After_Tagret_Symbol(char *str, const char target_symbol)
{
	if (strlen(str) == 0)
	{
		return str;
	}

	uint16_t i = strlen(str) - 1;

	while ((str[i] != target_symbol) && (i > 0))
	{
		--i;
	}

	if ((i < (strlen(str) - 1)) && (i > 0))
	{
		str[i + 1] = '\0';
	}

	return str;
}


char *STRX_Replace_All_Symbols(char *str, const char old_symbol, const char new_symbol)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == old_symbol)
		{
			str[i] = new_symbol;
		}
	}

	return str;
}


char *STRX_Replace_All_Symbols_To_Tagret_Symbol(char *str, const char old_symbol, const char new_symbol, const char target_symbol)
{
	for (uint16_t i = 0; (str[i] != target_symbol) && (str[i] != '\0'); ++i)
	{
		if (str[i] == old_symbol)
		{
			str[i] = new_symbol;
		}
	}

	return str;
}


char *STRX_Replace_All_Symbols_After_Tagret_Symbol(char *str, const char old_symbol, const char new_symbol, const char target_symbol)
{
	for (uint16_t i = (strlen(str) - 1); (str[i] != target_symbol) && (i > 0); --i)
	{
		if (str[i] == old_symbol)
		{
			str[i] = new_symbol;
		}
	}

	return str;
}



// ===============================================================================



char *STRX_Delete_All_Dublicate_Symbols_In_Row(char *str, const char symbol)
{
	char *str_ptr = str;

	if (str)
	{
		while ((*str_ptr) != '\0')
		{
			if ((str_ptr[1] != symbol) || (str_ptr[0] != symbol))
			{
				*(str++) = *str_ptr;
			}

			++str_ptr;
		}

		*str = *str_ptr;
	}

	return str;
}


char *STRX_Delete_All_Substrings(char *str, const char *substr)
{
	if (strlen(substr) == 0)
	{
		return str;
	}


	str = strstr(str, substr);
	
	while (str)
	{
		memmove(str, (str + strlen(substr)), (strlen(str + strlen(substr)) + 1));
		
		str = strstr(str, substr);
	}


	return str;
}


char *STRX_Delete_Substring_Within_Specified_Boundaries(char *str, const uint16_t begin_pos, uint16_t end_pos)
{
	uint16_t str_size = strlen(str);

	if ((str_size == 0) || (begin_pos >= end_pos) || (begin_pos > str_size))
	{
		return str;
	}

	if (end_pos > str_size)
	{
		end_pos = str_size - 1;
	}

	memmove((str + begin_pos), (str + end_pos), ((str_size - end_pos) + 1));

	return str;
}


char *STRX_Insert_Substring_By_Pos(char *str, const char *substr, uint16_t insert_pos)
{
	uint16_t str_size = strlen(str);

	if (str_size == 0)
	{
		return str;
	}

	if (insert_pos > str_size)
	{
		insert_pos = str_size;
	}

	uint16_t substr_size = strlen(substr);

	memmove((str + insert_pos + substr_size), (str + insert_pos), (str_size - insert_pos + 1));

	memcpy((str + insert_pos), substr, substr_size);


	return str;
}


char *STRX_Fill_Char_Within_Specified_Boundaries(char *str, const char placeholder_ch, const uint16_t begin_pos, uint16_t end_pos)
{
	uint16_t str_size = strlen(str);

	if ((str_size == 0) || (begin_pos >= end_pos) || (begin_pos > str_size))
	{
		return str;
	}

	if (end_pos >= str_size)
	{
		end_pos = str_size - 1;
	}

	memset(str + begin_pos, placeholder_ch, (end_pos - begin_pos));
	

	return str;
}


int16_t STRX_Get_First_Substring_Occurrence_Index(char *str, const char *substr)
{
	char *str_ptr = strstr(str, substr);

	if (str_ptr != NULL)
	{
		return str_ptr - str;
	}

	return -1;
}


uint16_t STRX_Get_Num_Of_Substring_Occurrences(char *str, const char *substr)
{
	if (strlen(substr) == 0)
	{
		return 0;
	}

	uint16_t num_of_occurrences = 0;

	uint16_t substr_size = strlen(substr);

	char* str_ptr = str;


	while ((str_ptr = strstr(str_ptr, substr)) != NULL)
	{
		str_ptr += substr_size;

		++num_of_occurrences;
	}


	return num_of_occurrences;
}


char *STRX_Replace_Substring(char *str, char *result_str, const char *old_substr, const char *new_substr)
{
	result_str[0] = '\0';
	
	uint16_t str_size = strlen(str);
	uint16_t old_substr_size = strlen(old_substr);
	uint16_t new_substr_size = strlen(new_substr);
	
	
	if ((str_size == 0) || (old_substr_size == 0) || (new_substr_size == 0))
	{
		return result_str;
	}


	char *dest = result_str;
	const char *src = str;


	while (*src)
	{
		if (strstr(src, old_substr) == src)
		{
			memcpy(dest, new_substr, new_substr_size);

			dest += new_substr_size;

			src += old_substr_size;
		}
		else
		{
			*dest++ = *src++;
		}
	}

	*dest = '\0';
	
	return result_str;
}



// ===============================================================================



uint16_t STRX_Split_Into_Tokens
(
	char *str,
	const char delim_symbol,
	uint16_t *tokens_indexes,
	const uint16_t max_num_of_tokens,
	const bool split_with_null_terminated_symbol
)
{
	uint16_t i = 0;

	if (strlen(str) == 0)
	{
		return 0;
	}

	tokens_indexes[0] = 0;

	uint16_t num_of_tokens = 1;


	while ((str[i] != '\0') && (num_of_tokens <= max_num_of_tokens))
	{
		if (str[i] == delim_symbol)
		{
			if (split_with_null_terminated_symbol)
			{
				str[i] = '\0';
			}

			if (i > 0)
			{
				tokens_indexes[num_of_tokens] = (i + 1);

				++num_of_tokens;
			}
		}

		++i;
	}

	return num_of_tokens;
}


uint16_t STRX_Split_Into_Tokens_Using_Delimiters_Set
(
	char *str,
	const char *delim_set,
	uint16_t *tokens_indexes,
	const uint16_t max_num_of_tokens,
	const bool split_with_null_terminated_symbol
)
{
	uint16_t i = 0;

	if (strlen(str) == 0)
	{
		return 0;
	}

	tokens_indexes[0] = 0;

	uint16_t num_of_tokens = 1;


	while ((str[i] != '\0') && (num_of_tokens <= max_num_of_tokens))
	{
		for (uint16_t j = 0; delim_set[j] != '\0'; ++j)
		{
			if (str[i] == delim_set[j])
			{
				if (split_with_null_terminated_symbol)
				{
					str[i] = '\0';
				}

				if (i > 0)
				{
					tokens_indexes[num_of_tokens] = (i + 1);

					++num_of_tokens;
				}
			}
		}

		++i;
	}

	return num_of_tokens;
}






