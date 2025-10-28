

// ===============================================================================
//
// Набор функций для манипуляций данными в массиве.
//
// Я специально не стал выносить их в отдельную библиотеку,
// поскольку тип данных в массиве может быть разнообразным,
// а язык Си не поддерживает шаблонные функции (не используя
// особых ухищрений с _Generic в стандарте C11).
//
// Именно поэтому для каждого конкретного применения я предлагаю
// просто копировать нужные функции в свой проект, изменяя тип данных на необходимый
//
// -------------------------------------------------------------------------------
//
// A set of functions for manipulating data in an array.
//
// I specifically did not put them in a separate library,
// because the data type in the array can be diverse,
// and the C programming language does not support
// template functions (without using special tricks
// with _Generic in the C11 standard).
//
// That is why, for each specific application,
// I suggest simply copying the necessary functions into your project,
// changing the data type to the required one
//
// ===============================================================================



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>




// переопределения типов данных
//
// -------------------------------------------------------------------------------
// redefinitions of data types
//
typedef uint8_t  DATA_TYPE;
typedef uint16_t DATA_SIZE_TYPE;




// ===============================================================================



// пузырьковая сортировка массива
//
// -------------------------------------------------------------------------------
// bubble array sorting
//
DATA_TYPE* Array_Bubble_Sort(DATA_TYPE* arr, DATA_SIZE_TYPE arr_size)
{
	DATA_TYPE temp;

	for (DATA_SIZE_TYPE i = 0; i < (arr_size - 1); ++i)
	{
		for (DATA_SIZE_TYPE j = 0; j < (arr_size - i - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	return arr;
}


// реверсивная пузырьковая сортировка массива
//
// -------------------------------------------------------------------------------
// reversible bubble sorting of an array
//
DATA_TYPE* Array_Reverse_Bubble_Sort(DATA_TYPE* arr, DATA_SIZE_TYPE arr_size)
{
	DATA_TYPE temp;

	for (DATA_SIZE_TYPE i = 0; i < (arr_size - 1); ++i)
	{
		for (DATA_SIZE_TYPE j = 0; j < (arr_size - i - 1); j++)
		{
			if (arr[j] <= arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	return arr;
}


// реверс массива
//
// -------------------------------------------------------------------------------
// array reverse
//
DATA_TYPE* Array_Reverse(DATA_TYPE* arr, DATA_SIZE_TYPE arr_size)
{
	DATA_TYPE temp;

	for (DATA_SIZE_TYPE i = 0, j = (arr_size - 1); i < (arr_size >> 1) || j >(arr_size >> 1); ++i, --j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	return arr;
}


// сдвиг массива влево на 1 элемент
//
// -------------------------------------------------------------------------------
// shifting an array to the left by 1 element
//
DATA_TYPE* Array_Shift_Left(DATA_TYPE* arr, DATA_SIZE_TYPE arr_size)
{
	DATA_TYPE tmp = arr[0];

	DATA_SIZE_TYPE i = 0, next_index;

	while (1)
	{
		next_index = i + 1;

		if (next_index >= arr_size)
		{
			break;
		}

		arr[i] = arr[next_index];

		++i;
	}

	arr[i] = tmp;

	return arr;
}


// сдвиг массива влево на n_pos элементов
//
// -------------------------------------------------------------------------------
// shifting the array to the left by n_pos elements
//
DATA_TYPE* Array_Shift_Left_Pos(DATA_TYPE* arr, DATA_SIZE_TYPE arr_size, DATA_SIZE_TYPE n_pos)
{

	for (DATA_SIZE_TYPE i = 0; i < n_pos; ++i)
	{
		Array_Shift_Left(arr, arr_size);
	}

	return arr;
}


// сдвиг массива вправо на 1 элемент
//
// -------------------------------------------------------------------------------
// shifting an array to the right by 1 element
//
DATA_TYPE* Array_Shift_Right(DATA_TYPE* arr, DATA_SIZE_TYPE arr_size)
{
	DATA_TYPE tmp = arr[arr_size - 1];

	DATA_SIZE_TYPE i = (arr_size - 1), next_index;

	while (1)
	{
		next_index = i - 1;

		if (i == 0)
		{
			break;
		}

		arr[i] = arr[next_index];

		--i;
	}

	arr[0] = tmp;

	return arr;
}


// сдвиг массива вправо на n_pos элементов
//
// -------------------------------------------------------------------------------
// shifting the array to the right by n_pos elements
//
DATA_TYPE* Array_Shift_Right_Pos(DATA_TYPE* arr, DATA_SIZE_TYPE arr_size, DATA_SIZE_TYPE n_pos)
{

	for (DATA_SIZE_TYPE i = 0; i < n_pos; ++i)
	{
		Array_Shift_Right(arr, arr_size);
	}

	return arr;
}


// случайная перестановка элементов массива
// (с использованием функции генератора псевдослучайных чисел rand()
// из библиотеки stdlib.h)
//
// -------------------------------------------------------------------------------
// random permutation of array elements (using the rand()
// pseudo-random number generator function from the stdlib.h library)
//
DATA_TYPE* Array_Shuffle(DATA_TYPE* arr, DATA_SIZE_TYPE arr_size)
{
	DATA_TYPE tmp;

	DATA_SIZE_TYPE tmp_index;

	for (DATA_SIZE_TYPE i = arr_size - 1; i > 0; --i)
	{
		tmp_index = (DATA_SIZE_TYPE)rand() % (i + 1);

		tmp = arr[i];
		arr[i] = arr[tmp_index];
		arr[tmp_index] = tmp;
	}

	return arr;
}



// ===============================================================================



// вывод элементов массива на печать (вспомогательная функция для демонстрации)
//
// -------------------------------------------------------------------------------
// printing array elements (auxiliary function for demonstration)
//
void __Print_Array(const char* msg, DATA_TYPE* arr, DATA_SIZE_TYPE arr_size)
{
	printf("%s: ", msg);

	for (DATA_SIZE_TYPE i = 0; i < arr_size; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\r\n\r\n");
}



// определение и инициализация массива из 20 элементов
//
// -------------------------------------------------------------------------------
// defining and initializing an array of 20 elements
//
DATA_TYPE arr[] = { 13, 14, 4, 6, 17, 5, 16, 1, 3, 2, 7, 0, 11, 9, 12, 8, 10, 19, 20, 15, 18 };



int main()
{
	// инициализация функции генератора псевдослучайных чисел rand()
	// из библиотеки stdlib.h, которая необходима для работы функции
	// случайной перестановки элементов массива
	//
	// -------------------------------------------------------------------------------
	// initialization of the rand() pseudorandom number generator function
	// from the stdlib library.h, which is necessary for the function of
	// random permutation of array elements to work
	//
	srand(0x1234);


	// вычисление количества элементов массива
	//
	// -------------------------------------------------------------------------------
	// calculating the number of array elements
	//
	const DATA_SIZE_TYPE arr_size = sizeof(arr) / sizeof(DATA_TYPE);




	// печать оригинального массива
	//
	// -------------------------------------------------------------------------------
	// printing the original array
	//
	__Print_Array("Original array", arr, arr_size);




	// выполнение различных манипуляций с массивом
	//
	// -------------------------------------------------------------------------------
	// performing various array manipulations
	//
	Array_Bubble_Sort(arr, arr_size);
	__Print_Array("Sorted array", arr, arr_size);


	Array_Reverse(arr, arr_size);
	__Print_Array("Reversed array", arr, arr_size);


	Array_Shift_Left(arr, arr_size);
	__Print_Array("Shifted to left array (1 pos)", arr, arr_size);


	Array_Shift_Right(arr, arr_size);
	__Print_Array("Shifted to right array (1 pos)", arr, arr_size);


	Array_Shuffle(arr, arr_size);
	__Print_Array("Random shuffled array", arr, arr_size);


	Array_Reverse_Bubble_Sort(arr, arr_size);
	__Print_Array("Reverse sorted array", arr, arr_size);


	Array_Shift_Right_Pos(arr, arr_size, 3);
	__Print_Array("Shifted to right array (3 pos)", arr, arr_size);


	Array_Shift_Left_Pos(arr, arr_size, 3);
	__Print_Array("Shifted to left array (3 pos)", arr, arr_size);
}




