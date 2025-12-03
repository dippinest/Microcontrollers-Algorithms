

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
// because the data type in the array can be diverse, and the C language
// does not support template functions (without using special tricks
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
typedef int16_t  DATA_SIZE_TYPE;




// ===============================================================================



// пузырьковая сортировка
// 
// Данный алгоритм оптимален только для сортирвки небольших массивов
//
// -------------------------------------------------------------------------------
// bubble sorting
// 
// This algorithm is optimal only for sorting small arrays
//
DATA_TYPE* Array_Bubble_Sort(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size)
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


// обратная (реверсивная) пузырьковая сортировка
// 
// Данный алгоритм оптимален только для сортирвки небольших массивов
//
// -------------------------------------------------------------------------------
// reverse bubble sorting
// 
// This algorithm is optimal only for sorting small arrays
//
DATA_TYPE* Array_Reverse_Bubble_Sort(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size)
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


// сортировка вставками
// 
// Данный алгоритм оптимален для сортирвки почти отсортированных массивов
//
// -------------------------------------------------------------------------------
// insertion sorting
// 
// This algorithm is optimal for sorting almost sorted arrays
//
DATA_TYPE* Array_Insertion_Sort(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size)
{
	DATA_SIZE_TYPE i = 1;
	DATA_SIZE_TYPE j;

	DATA_TYPE tmp;


	while (i < arr_size)
	{
		tmp = arr[i];

		j = i - 1;

		while (j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j]; --j;
		}

		arr[j + 1] = tmp;

		++i;
	}

	return arr;
}


// обратная (реверсивная) сортировка вставками
// 
// Данный алгоритм оптимален для сортирвки почти отсортированных массивов
//
// -------------------------------------------------------------------------------
// reverse insertion sorting
// 
// This algorithm is optimal for sorting almost sorted arrays
//
DATA_TYPE* Array_Reverse_Insertion_Sort(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size)
{
	DATA_SIZE_TYPE i = 1;
	DATA_SIZE_TYPE j;

	DATA_TYPE tmp;


	while (i < arr_size)
	{
		tmp = arr[i];

		j = i - 1;

		while (j >= 0 && arr[j] < tmp)
		{
			arr[j + 1] = arr[j]; --j;
		}

		arr[j + 1] = tmp;

		++i;
	}

	return arr;
}


// сортировка выбором
// 
// Данный алгоритм оптимален в случаях необходимости
// минимизации операций записи в память
// (к примеру, когда сортировка проиходит в EEPROM или Flash памяти)
//
// -------------------------------------------------------------------------------
// selection sorting
// 
// This algorithm is optimal when it is necessary
// to minimize memory reads
// (for example, when sorting takes place in EEPROM or Flash memory)
//
DATA_TYPE* Array_Selection_Sort(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size)
{
	DATA_SIZE_TYPE i = 0;
	DATA_SIZE_TYPE j;

	DATA_SIZE_TYPE tmp_index;

	DATA_TYPE tmp;


	while (i < (arr_size - 1))
	{
		tmp_index = i;

		j = (i + 1);

		while (j < arr_size)
		{
			if (arr[j] < arr[tmp_index])
			{
				tmp_index = j;
			}

			++j;
		}

		tmp = arr[i];
		arr[i] = arr[tmp_index];
		arr[tmp_index] = tmp;

		++i;
	}

	return arr;
}


// обратная (реверсивная) сортировка выбором
// 
// Данный алгоритм оптимален в случаях необходимости
// минимизации операций записи в память
// (к примеру, когда сортировка проиходит в EEPROM или Flash памяти)
//
// -------------------------------------------------------------------------------
// reverse selection sorting
// 
// This algorithm is optimal when it is necessary
// to minimize write operations to memory
// (for example, when sorting takes place in EEPROM or Flash memory)
//
DATA_TYPE* Array_Reverse_Selection_Sort(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size)
{
	DATA_SIZE_TYPE i = 0;
	DATA_SIZE_TYPE j;

	DATA_SIZE_TYPE tmp_index;

	DATA_TYPE tmp;


	while (i < (arr_size - 1))
	{
		tmp_index = i;

		j = (i + 1);

		while (j < arr_size)
		{
			if (arr[j] > arr[tmp_index])
			{
				tmp_index = j;
			}

			++j;
		}

		tmp = arr[i];
		arr[i] = arr[tmp_index];
		arr[tmp_index] = tmp;

		++i;
	}

	return arr;
}


// реверс массива
//
// -------------------------------------------------------------------------------
// array reverse
//
DATA_TYPE* Array_Reverse(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size)
{
	DATA_TYPE temp;

	for (DATA_SIZE_TYPE i = 0, j = (arr_size - 1); i < (arr_size >> 1) || j > (arr_size >> 1); ++i, --j)
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
DATA_TYPE* Array_Shift_Left(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size)
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
DATA_TYPE* Array_Shift_Left_Pos(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size, const DATA_SIZE_TYPE n_pos)
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
DATA_TYPE* Array_Shift_Right(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size)
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
DATA_TYPE* Array_Shift_Right_Pos(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size, const DATA_SIZE_TYPE n_pos)
{

	for (DATA_SIZE_TYPE i = 0; i < n_pos; ++i)
	{
		Array_Shift_Right(arr, arr_size);
	}

	return arr;
}


// случайная перестановка элементов массива
// (в ней используется функции генератора псевдослучайных чисел srand() и rand()
// из библиотеки stdlib.h)
//
// -------------------------------------------------------------------------------
// random permutation of array elements
// (it uses the pseudo-random number generator functions srand() and rand()
// from the stdlib.h library)
//
DATA_TYPE* Array_Shuffle(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size, const uint16_t rand_seed)
{
	srand(rand_seed);


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


// инволюция предыдущей функции случайной перестановки элементов массива
// (в ней используется функции генератора псевдослучайных чисел rand()
// из библиотеки stdlib.h)
//
// -------------------------------------------------------------------------------
// an involution of the previous random array element permutation function
// (it uses the rand() pseudorandom number generator function
// from the stdlib.h library)
//
DATA_TYPE* Array_Unshuffle(DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size, const uint16_t rand_seed)
{
	DATA_TYPE tmp;

	volatile DATA_SIZE_TYPE tmp_index;


	for (DATA_SIZE_TYPE i = 0; i < arr_size; ++i)
	{
		srand(rand_seed);

		for (DATA_SIZE_TYPE j = 0; j < (arr_size - i - 1); ++j)
		{
			tmp_index = (DATA_SIZE_TYPE)rand();
		}

		tmp_index = (DATA_SIZE_TYPE)rand() % (i + 1);

		tmp = arr[i];
		arr[i] = arr[tmp_index];
		arr[tmp_index] = tmp;
	}

	return arr;
}


// линейный поиск элемента в массиве,
// возвращаемое значение - индекс элемента.
// 
// Если элемента в массиве нет, функция возвращает значение -1
//
// -------------------------------------------------------------------------------
// linear searching for an element in an array,
// the return value is the index of the element.
// 
// If there is no element in the array, the function returns the value -1
//
DATA_SIZE_TYPE Array_Linear_Search_Element_Index(const DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size, DATA_TYPE element)
{
	DATA_SIZE_TYPE element_index = -1;


	for (DATA_SIZE_TYPE i = 0; i < arr_size; ++i)
	{
		if (arr[i] == element)
		{
			element_index = i; break;
		}
	}

	return element_index;
}


// поиск элемента в отсортированном массиве,
// возвращаемое значение - индекс элемента.
// 
// Если элемента в массиве нет, функция возвращает значение -1
//
// -------------------------------------------------------------------------------
// searching for an element in a sorted array,
// the return value is the index of the element.
// 
// If there is no element in the array, the function returns the value -1
//
DATA_SIZE_TYPE Array_Binary_Search_Element_Index(const DATA_TYPE* arr, const DATA_SIZE_TYPE arr_size, DATA_TYPE element)
{
	DATA_TYPE tmp;

	DATA_SIZE_TYPE left_element_index = 0;
	DATA_SIZE_TYPE right_element_index = arr_size - 1;
	DATA_SIZE_TYPE median_element_index;


	while (left_element_index <= right_element_index)
	{
		median_element_index = (left_element_index + right_element_index) >> 1;

		tmp = arr[median_element_index];

		if (element == tmp)
		{
			return median_element_index;
		}


		if (element < tmp)
		{
			right_element_index = median_element_index - 1;
		}
		else
		{
			left_element_index = median_element_index + 1;
		}
	}

	return -1;
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



// определение и инициализация массива из 30 элементов
//
// -------------------------------------------------------------------------------
// defining and initializing an array of 30 elements
//
DATA_TYPE arr[] = { 13, 14, 4, 6, 17, 5, 16, 1, 3, 2, 7, 0, 11, 9, 12, 8, 10, 19, 20, 15, 18, 33, 34, 76, 54, 61, 94, 23, 67, 83 };



int main()
{
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





	// для работы с функцией случайной перестановки
	// (и функции с обратным преобразованием этой перестановки)
	// используются функции генератора псевдослучайных чисел из библиотеки stdlib.h.
	// 
	// Третьим параметром в функции передаются значение зерна для генератора rand()
	// (в случае функции Array_Unshuffle значение зерна должно быть тем же,
	// что использовался при вызове функции Array_Shuffle)
	//
	// -------------------------------------------------------------------------------
	// to work with the random permutation function
	// (and the function with the inverse transformation of this permutation),
	// the functions of the pseudo-random number generator from the stdlib.h library.
	// 
	// The third parameter in the function passes the grain value
	// for the rand() generator
	// (in the case of the Array_Unshuffle function,
	// the grain value must be the same as that used when calling
	// the Array_Shuffle function)
	//
	Array_Shuffle(arr, arr_size, 0x0000);
	__Print_Array("Random shuffled array", arr, arr_size);


	Array_Unshuffle(arr, arr_size, 0x0000);
	__Print_Array("Unshuffled array", arr, arr_size);





	Array_Reverse_Bubble_Sort(arr, arr_size);
	__Print_Array("Reverse sorted array", arr, arr_size);


	Array_Shift_Right_Pos(arr, arr_size, 3);
	__Print_Array("Shifted to right array (3 pos)", arr, arr_size);


	Array_Shift_Left_Pos(arr, arr_size, 3);
	__Print_Array("Shifted to left array (3 pos)", arr, arr_size);




	// линейный поиск элемента в массиве
	//
	// -------------------------------------------------------------------------------
	// linear searching for an element in an array
	//
	DATA_TYPE element = 18;

	DATA_SIZE_TYPE element_index = Array_Linear_Search_Element_Index(arr, arr_size, element);

	printf("Element \'%d\' is located at the index %d\n\n", element, element_index);



	// сортировка массива алгоритмом insertion sort
	//
	// -------------------------------------------------------------------------------
	// sorting an array using the insertion sort algorithm
	//
	Array_Insertion_Sort(arr, arr_size);
	__Print_Array("Sorted array (insertion sort)", arr, arr_size);




	// бинарный поиск элемента в массиве
	// 
	// Внимание! Бинарный поиск работает только на отсортированных данных!
	//
	// -------------------------------------------------------------------------------
	// binary searching for an element in an array
	// 
	// Attention! Binary search only works on sorted data!
	//
	element = 15;

	element_index = Array_Binary_Search_Element_Index(arr, arr_size, element);

	printf("Element \'%d\' is located at the index %d\n\n", element, element_index);
}





