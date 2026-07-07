

#include "strx.h"



bool STRX_Is_String_Contains_Only_Letter(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_Letter(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_Letter_Safe(const char *str, const uint16_t str_max_size)
{
	for (uint16_t i = 0; (str[i] != '\0') && (i < str_max_size); ++i)
	{
		if (!STRX_Char_Is_Letter(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_Digit(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_Digit(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_HEXDigit(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_HEXDigit(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_Letter_Or_Digit(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_Letter_Or_Digit(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_Whitespace_Or_HTab(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_Whitespace_Or_HTab(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_Control_Char_CNTRL(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_Control_Char_CNTRL(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_Printable(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_Printable(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_Printable_And_Not_Whitespace(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_Printable_And_Not_Whitespace(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_Space(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_Space(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_Punctuation_Mark(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_Punctuation_Mark(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_Upper_Case(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_Upper_Case(str[i]))
		{
			return false;
		}
	}

	return true;
}


bool STRX_Is_String_Contains_Only_Lower_Case(const char *str)
{
	for (uint16_t i = 0; str[i] != '\0'; ++i)
	{
		if (!STRX_Char_Is_Lower_Case(str[i]))
		{
			return false;
		}
	}

	return true;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



uint16_t STRX_Get_String_Size(const char *str)
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



bool STRX_Strings_Is_Equivalent(char *str1, char *str2)
{
	uint16_t i = 0;


	if ((str1 == NULL) || (str2 == NULL))
	{
		goto IS_NOT_EQUIVALENT;
	}


	while ((str1[i] != '\0') && (str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
		{
			goto IS_NOT_EQUIVALENT;
		}

		++i;
	}

	if ((str1[i] == '\0') && (str2[i] == '\0'))
	{
		return true;
	}

	IS_NOT_EQUIVALENT: return false;
}


bool STRX_Strings_Is_Equivalent_Safe(char *str1, const uint16_t str1_max_size, char *str2, const uint16_t str2_max_size)
{
	uint16_t i = 0;


	if ((str1 == NULL) || (str2 == NULL))
	{
		goto IS_NOT_EQUIVALENT;
	}


	while ((str1[i] != '\0') && (i < str1_max_size) && (str2[i] != '\0') && (i < str2_max_size))
	{
		if (str1[i] != str2[i])
		{
			goto IS_NOT_EQUIVALENT;
		}

		++i;
	}

	if ((str1[i] == '\0') && (str2[i] == '\0'))
	{
		return true;
	}

	IS_NOT_EQUIVALENT: return false;
}


bool STRX_Strings_Is_Equivalent_Ignore_Case(char *str1, char *str2)
{
	uint16_t i = 0;


	if ((str1 == NULL) || (str2 == NULL))
	{
		goto IS_NOT_EQUIVALENT;
	}


	while ((str1[i] != '\0') && (str2[i] != '\0'))
	{
		if (toupper(str1[i]) != toupper(str2[i]))
		{
			goto IS_NOT_EQUIVALENT;
		}

		++i;
	}

	if ((str1[i] == '\0') && (str2[i] == '\0'))
	{
		return true;
	}

	IS_NOT_EQUIVALENT: return false;
}


bool STRX_Strings_Is_Equivalent_Ignore_Case_Safe(char *str1, const uint16_t str1_max_size, char *str2, const uint16_t str2_max_size)
{
	uint16_t i = 0;


	if ((str1 == NULL) || (str2 == NULL))
	{
		goto IS_NOT_EQUIVALENT;
	}


	while ((str1[i] != '\0') && (i < str1_max_size) && (str2[i] != '\0') && (i < str2_max_size))
	{
		if (toupper(str1[i]) != toupper(str2[i]))
		{
			goto IS_NOT_EQUIVALENT;
		}

		++i;
	}

	if ((str1[i] == '\0') && (str2[i] == '\0'))
	{
		return true;
	}

	IS_NOT_EQUIVALENT: return false;
}



// ===============================================================================



char *STRX_Generate_Random_Strings
(
	char *str_buf,
	const uint16_t str_buf_size,
	char min_char_index,
	char max_char_index,
	uint16_t (*_16bit_random_generator)(void)
)
{
	if ((str_buf_size < 1) || (_16bit_random_generator == NULL))
	{
		return NULL;
	}

	if (max_char_index < min_char_index)
	{
		max_char_index ^= min_char_index;
		min_char_index ^= max_char_index;
		max_char_index ^= min_char_index;
	}


	char random_char;

	for (uint16_t i = 0; i < (str_buf_size - 1); ++i)
	{
		random_char = (char)(min_char_index + (_16bit_random_generator() % (max_char_index - min_char_index + 1)));

		str_buf[i] = random_char;
	}

	str_buf[(str_buf_size - 1)] = '\0';


	return str_buf;
}


char *STRX_Generate_Random_Strings_With_Alphabet
(
	char *str_buf,
	const uint16_t str_buf_size,
	const char *alphabet,
	const uint16_t alphabet_size,
	uint16_t(*_16bit_random_generator)(void)
)
{
	if ((str_buf_size < 1) || (alphabet == NULL) || (alphabet_size == 0) || (_16bit_random_generator == NULL))
	{
		return NULL;
	}

	char random_char;


	for (uint16_t i = 0; i < (str_buf_size - 1); ++i)
	{
		random_char = alphabet[_16bit_random_generator() % alphabet_size];

		str_buf[i] = random_char;
	}

	str_buf[(str_buf_size - 1)] = '\0';


	return str_buf;
}



// ===============================================================================



char *STRX_Delete_All_Extra_Symbols(char *str, const char extra_symbol)
{
	if ((str == NULL) || (strlen(str) == 0))
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
	const uint16_t str_size = strlen(str);

	if ((str_size == 0) || (begin_pos >= end_pos) || (begin_pos > str_size))
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

	const uint16_t str_size = strlen(str);


	while ((str[i] == symbol) && (i <= str_size))
	{
		++i;
	}

	if ((i > 0) && (i <= str_size))
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

	const uint16_t str_size = strlen(str);


	while ((str[i] == symbol) && (i <= str_size))
	{
		++i;
	}

	if ((i > 0) && (i <= str_size))
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
	const uint16_t str_size = strlen(str);


	if (str_size == 0)
	{
		return str;
	}

	uint16_t i = str_size - 1;

	while ((str[i] == symbol) && (i > 0))
	{
		--i;
	}

	if ((i < (str_size - 1)) && (i > 0))
	{
		str[i + 1] = '\0';
	}

	return str;
}


char *STRX_Trim_All_Extra_Symbols_To_Target_Symbol(char *str, const char target_symbol)
{
	int16_t i = 0;
	int16_t j = 0;

	const uint16_t str_size = strlen(str);


	while ((str[i] != target_symbol) && (i <= str_size))
	{
		++i;
	}

	if ((i > 0) && (i <= str_size))
	{
		for (j = 0; j < strlen(str); j++)
		{
			str[j] = str[j + i];
		}

		str[j] = '\0';
	}

	return str;
}


char *STRX_Trim_All_Extra_Symbols_After_Target_Symbol(char *str, const char target_symbol)
{
	const uint16_t str_size = strlen(str);


	if (str_size == 0)
	{
		return str;
	}

	uint16_t i = str_size - 1;

	while ((str[i] != target_symbol) && (i > 0))
	{
		--i;
	}

	if ((i < (str_size - 1)) && (i > 0))
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


char *STRX_Replace_All_Symbols_To_Target_Symbol(char *str, const char old_symbol, const char new_symbol, const char target_symbol)
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


char *STRX_Replace_All_Symbols_After_Target_Symbol(char *str, const char old_symbol, const char new_symbol, const char target_symbol)
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


char *STRX_Delete_All_Substrings(char *str, const char* substr)
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
	uint16_t num_of_occurrences = 0;

	uint16_t substr_size = strlen(substr);


	if (substr_size == 0)
	{
		return 0;
	}

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


	char* dest = result_str;
	const char* src = str;


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
	char* str,
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



// ===============================================================================



bool STRX_Strings_Is_Sort(char** strings, const uint16_t num_of_strings)
{
	if (num_of_strings < 2)
	{
		return true;
	}


	for (uint16_t i = 0; i < num_of_strings; ++i)
	{
		if (STRX_BuildIn_Custom_STRCMP(strings[i - 1], strings[i]) > 0)
		{
			return false;
		}
	}

	return true;
}


bool STRX_Strings_Is_Reverce_Sort(char** strings, const uint16_t num_of_strings)
{
	if (num_of_strings < 2)
	{
		return true;
	}


	for (uint16_t i = 0; i < num_of_strings; ++i)
	{
		if (STRX_BuildIn_Custom_STRCMP(strings[i - 1], strings[i]) < 0)
		{
			return false;
		}
	}

	return true;
}



// ===============================================================================



int8_t STRX_BuildIn_Custom_STRCMP(const char* str1, const char* str2)
{
	while (*str1 && *str2 && (*str1 == *str2))
	{
		++(str1);
		++(str2);
	}

	return (int8_t)(*str1 - *str2);
}


int8_t STRX_BuildIn_Custom_STRCMP_Ignore_Case(const char* str1, const char* str2)
{
	char ch1, ch2;


	while (*str1 && *str2)
	{
		ch1 = toupper(*str1);
		ch2 = toupper(*str2);

		if (ch1 != ch2)
		{
			return (int8_t)(ch1 - ch2);
		}

		++(str1);
		++(str2);
	}

	return (int8_t)(*str1 - *str2);
}


int8_t STRX_BuildIn_Custom_STRCMP_Reverse(const char* str1, const char* str2)
{
	while (*str1 && *str2 && (*str1 == *str2))
	{
		++(str1);
		++(str2);
	}

	return (int8_t)(*str2 - *str1);
}


int8_t STRX_BuildIn_Custom_STRCMP_Ignore_Case_Reverse(const char* str1, const char* str2)
{
	char ch1, ch2;


	while (*str1 && *str2)
	{
		ch1 = toupper(*str1);
		ch2 = toupper(*str2);

		if (ch1 != ch2)
		{
			return (int8_t)(ch2 - ch1);
		}

		++(str1);
		++(str2);
	}

	return (int8_t)(*str2 - *str1);
}



// ===============================================================================



void STRX_Strings_Lexicographic_Bubble_Sort(char** strings, const uint16_t num_of_strings, int8_t(*comparator)(const char* str1, const char* str2))
{
	if (num_of_strings < 2)
	{
		return;
	}


	char* tmp_string_ptr;

	bool is_swapped = false;


	for (uint16_t i = 0; i < (num_of_strings - 1); ++i)
	{
		is_swapped = false;


		for (uint16_t j = 0; j < (num_of_strings - 1 - i); ++j)
		{
			if (comparator(strings[j], strings[j + 1]) > 0)
			{
				tmp_string_ptr = strings[j];
				strings[j]     = strings[j + 1];
				strings[j + 1] = tmp_string_ptr;

				is_swapped = true;
			}
		}

		if (is_swapped == false)
		{
			break;
		}
	}
}


void STRX_Strings_Lexicographic_Insertion_Sort(char** strings, const uint16_t num_of_strings, int8_t(*comparator)(const char* str1, const char* str2))
{
	if (num_of_strings < 2)
	{
		return;
	}

	char* key;

	int16_t j;



	for (uint16_t i = 1; i < num_of_strings; ++i)
	{
		key = strings[i];

		j = i - 1;


		while ((j >= 0) && (comparator(strings[j], key) > 0))
		{
			strings[j + 1] = strings[j];

			j--;
		}

		strings[j + 1] = key;
	}
}


void STRX_Strings_Lexicographic_Selection_Sort(char** strings, const uint16_t num_of_strings, int8_t(*comparator)(const char* str1, const char* str2))
{
	if (num_of_strings < 2)
	{
		return;
	}

	char* tmp_string_ptr;

	uint16_t min_index;



	for (uint16_t i = 0; i < (num_of_strings - 1); ++i)
	{
		min_index = i;

		for (uint16_t j = (i + 1); j < num_of_strings; ++j)
		{
			if (comparator(strings[j], strings[min_index]) < 0)
			{
				min_index = j;
			}
		}

		if (min_index != i)
		{
			tmp_string_ptr   = strings[i];
			strings[i]       = strings[min_index];
			strings[min_index] = tmp_string_ptr;
		}
	}
}






