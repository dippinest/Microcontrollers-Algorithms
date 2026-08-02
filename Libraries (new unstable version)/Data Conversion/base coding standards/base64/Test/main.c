

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "base64.h"



// количество тестов
//
// -------------------------------------------------------------------------------
// num of tests
//
#define TEST_NUM_ITERATIONS 20000



// размер тестового массива данных
//
// -------------------------------------------------------------------------------
// size of the test data array
//
#define DATA_ARRAY_SIZE 1000



// размер массива для выходного текста Base64
//
// -------------------------------------------------------------------------------
// size of the array for the Base64 output text
//
#define BASEX_ARRAY_SIZE (DATA_ARRAY_SIZE * 2) // overhead = 33%





// определение массивов данных и текстового массива Base64
//
// -------------------------------------------------------------------------------
// defining Base64 data arrays and text arrays
//
uint8_t data_array1[DATA_ARRAY_SIZE], data_array2[DATA_ARRAY_SIZE];

char basex_array[BASEX_ARRAY_SIZE];




// функция для заполнения массива случайным числом случайных элементов
//
// -------------------------------------------------------------------------------
// function for filling an array with a random number of random elements
//
void _Fill_Array_Random_Numbers(void* data, const uint32_t data_size)
{
	for (uint32_t i = 0; i < data_size; ++i)
	{
		((uint8_t*)data)[i] = (uint8_t)rand();
	}
}



void Run_Test()
{
	bool is_test_succsess = true;

	uint32_t data_size;

	printf("\n\n================== THE BASE64 TEST ==================\n\n\n\n");

	printf("\tNum of tests -------- %d\n\n", TEST_NUM_ITERATIONS);
	printf("\tMax data array size - %d\n\n", DATA_ARRAY_SIZE);



	printf("\n\n\tTEST IS BEGIN!\n\n\n");


	for (uint32_t i = 0; i < TEST_NUM_ITERATIONS; ++i)
	{
		data_size = rand() % DATA_ARRAY_SIZE;

		_Fill_Array_Random_Numbers(data_array1, data_size);


		uint32_t basex_encoded_array_size = Base64_Encode(data_array1, data_size, basex_array);

		uint32_t basex_decoded_array_size = Base64_Decode(basex_array, basex_encoded_array_size, data_array2);


		if ((basex_encoded_array_size == strlen(basex_array) && (memcmp(data_array1, data_array2, data_size) == 0)))
		{
			printf("\r\tTest #%d: Succsess!", (i + 1));
		}
		else
		{
			printf("\r\tTest #%d:   FAILED!", (i + 1));

			is_test_succsess = false;

			break;
		}
	}

	if (is_test_succsess)
	{
		printf("\n\n\n========== All tests passed successfully! ==========\n\n\n");
	}
	else
	{
		printf("\n\n\n========== THE TESTS FAILED!!! ==========\n\n\n");
	}
}


int main(int argc, char** argv)
{
	// инициализация ГПСЧ из стандартной библиотеки
	//
	// -------------------------------------------------------------------------------
	// initializing the PRNG from the standard library
	//
	srand(time(NULL));

	Run_Test();


	return 0;
}




