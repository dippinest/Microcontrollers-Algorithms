

#include <stdio.h>
#include <stdint.h>

#include <time.h>

#include "strx.h"




// параметры двумерного статического массива
// 
// -------------------------------------------------------------------------------
// parameters of a two-dimensional static array
//
#define MAX_STRING_SIZE 30
#define NUM_OF_STRINGS  20


// двумерный статический массив для хранения строк
// 
// -------------------------------------------------------------------------------
// two-dimensional static array for storing strings
//
char strings[NUM_OF_STRINGS][MAX_STRING_SIZE];


// массив указателей на строки
// 
// -------------------------------------------------------------------------------
// array of pointers to strings
//
char* strings_pointers[NUM_OF_STRINGS];





// колбэк функция генератора
// случайных чисел для функции STRX_Generate_Random_Strings
// 
// -------------------------------------------------------------------------------
// callback function of
// the random number generator for the STRX_Generate_Random_Strings function
//
uint16_t random_generator()
{
	return (uint16_t)rand();
}



int main(void)
{
	// инициализация ГПСЧ rand()
	// 
	// -------------------------------------------------------------------------------
	// initialization of the rand RNG()
	//
	srand(time(NULL));



	// заполнение строк случайной длины (от 8 до (MAX_STRING_SIZE - 1) символов)
	// случайными значениями (строки с символами от 'A' до 'Z')
	// 
	// -------------------------------------------------------------------------------
	// filling strings of random length (from 8 to (MAX_STRING_SIZE - 1) characters)
	// with random values (strings with characters from 'A' to 'Z')
	//
	for (uint16_t i = 0; i < NUM_OF_STRINGS; ++i)
	{
		uint16_t string_random_size = 8 + random_generator() % (MAX_STRING_SIZE - 8);

		STRX_Generate_Random_Strings(strings[i], string_random_size, 'A', 'Z', random_generator);

		strings_pointers[i] = strings[i];
	}



	// вывод неотсортированного массива строк
	// 
	// -------------------------------------------------------------------------------
	// output of an unsorted array of strings
	//
	for (uint16_t i = 0; i < NUM_OF_STRINGS; ++i)
	{
		printf("Unsort String %2.d: %s\n", (i + 1), strings_pointers[i]);
	}

	printf("\n===============================================\n\n");



	// сортировка строк в лексикографическом порядке
	// 
	// -------------------------------------------------------------------------------
	// sorting strings in lexicographic order
	//
	STRX_Strings_Lexicographic_Bubble_Sort(strings_pointers, NUM_OF_STRINGS, STRX_BuildIn_Custom_STRCMP);



	// вывод отсортированного массива строк
	// 
	// -------------------------------------------------------------------------------
	// output of a sorted array of strings
	//
	for (uint16_t i = 0; i < NUM_OF_STRINGS; ++i)
	{
		printf("Sort String  %2.d:  %s\n", (i + 1), strings_pointers[i]);
	}
}



