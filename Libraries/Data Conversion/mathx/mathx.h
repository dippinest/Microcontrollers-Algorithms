

// ===============================================================================
//
// Библиотека с полезными математическими функциями
//
//
// -------------------------------------------------------------------------------
//
// Library with useful mathematical functions
//
//
// ===============================================================================


#ifndef MATHX_H_
#define MATHX_H_


#include <stdint.h>
#include <limits.h>
#include <stdbool.h>




// переопределения числовых типов типов
//
// -------------------------------------------------------------------------------
// redefinitions of numeric type types
//
typedef int8_t     i8;
typedef uint8_t    u8;


typedef int16_t    i16;
typedef uint16_t   u16;


typedef int32_t    i32;
typedef uint32_t   u32;


#ifdef NUM_64BIT_SUPPORT

typedef int64_t    i64;
typedef uint64_t   u64;

#endif


typedef float      float32;
typedef float      f32;

typedef double     float64;
typedef float      f64;



// ===============================================================================



// минимальные и максимальные значения числовых типов
//
// -------------------------------------------------------------------------------
// min and max values of numeric types
//
#define MATHX_MIN_I8_VAL          SCHAR_MIN
#define MATHX_MAX_I8_VAL          SCHAR_MAX

#define MATHX_MIN_U8_VAL          0
#define MATHX_MAX_U8_VAL          UCHAR_MAX


#define MATHX_MIN_I16_VAL         SHRT_MIN
#define MATHX_MAX_I16_VAL         SHRT_MAX

#define MATHX_MIN_U16_VAL         0
#define MATHX_MAX_U16_VAL         USHRT_MAX


#define MATHX_MIN_I32_VAL         INT_MIN
#define MATHX_MAX_I32_VAL         INT_MAX

#define MATHX_MIN_U32_VAL         0
#define MATHX_MAX_U32_VAL         UINT_MAX


#ifdef NUM_64BIT_SUPPORT

#define MATHX_MIN_I64_VAL        LLONG_MIN
#define MATHX_MAX_I64_VAL        LLONG_MAX

#define MATHX_MIN_U64_VAL        0ULL
#define MATHX_MAX_U64_VAL        ULLONG_MAX

#endif


#define MATHX_MIN_F32_VAL        3.4E-38
#define MATHX_MAX_F32_VAL        3.4E+38

#define MATHX_MIN_FLOAT32_VAL    3.4E-38
#define MATHX_MAX_FLOAT32_VAL    3.4E+38



// ===============================================================================



// установка и сброс бита в целочисленной переменной
//
// -------------------------------------------------------------------------------
// setting and resetting a bit in an integer variable
//
#define MATHX_SETBIT_HIGH(val, pos) (val |=  (1 << pos))
#define MATHX_SETBIT_LOW(val, pos)  (val &= ~(1 << pos))


// получение бита в целочисленной переменной по определённой позиции
//
// -------------------------------------------------------------------------------
// getting a bit in an integer variable at a specific position
//
#define MATHX_GETBIT(val, pos) (val & (1 << pos))


// обмен значениями
//
// -------------------------------------------------------------------------------
// exchange of values
//
#define MATHX_TSWAP(A, B, val_type) do { val_type tmp = A; A = B; B = tmp; } while(0);


// циклический битовый сдвиг в целочисленной переменной
//
// -------------------------------------------------------------------------------
// cyclic bit shift in an integer variable
//
#define MATHX_ROTL(val, pos, val_type) (val << pos) | (val >> (sizeof(val_type) * 8 - pos))
#define MATHX_ROTR(val, pos, val_type) (val >> pos) | (val << (sizeof(val_type) * 8 - pos))



// ===============================================================================



// функции для получения наименьшего из двух чисел
//
// -------------------------------------------------------------------------------
// functions for getting the smallest of two numbers
//


inline int8_t MATHX_Get_Min_Int8(int8_t num1, int8_t num2)
{
	if (num1 <= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline uint8_t MATHX_Get_Min_UInt8(uint8_t num1, uint8_t num2)
{
	if (num1 <= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline int16_t MATHX_Get_Min_Int16(int16_t num1, int16_t num2)
{
	if (num1 <= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline uint16_t MATHX_Get_Min_UInt16(uint16_t num1, uint16_t num2)
{
	if (num1 <= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline int32_t MATHX_Get_Min_Int32(int32_t num1, int32_t num2)
{
	if (num1 <= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline uint32_t MATHX_Get_Min_UInt32(uint32_t num1, uint32_t num2)
{
	if (num1 <= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}



#ifdef NUM_64BIT_SUPPORT


inline int64_t MATHX_Get_Min_Int64(int64_t num1, int64_t num2)
{
	if (num1 <= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline uint64_t MATHX_Get_Min_UInt64(uint64_t num1, uint64_t num2)
{
	if (num1 <= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

#endif



inline float MATHX_Get_Min_Float(float num1, float num2)
{
	if (num1 <= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}



// ===============================================================================



// функции для получения наибольшего значения из двух чисел
//
// -------------------------------------------------------------------------------
// functions for getting the largest value of two numbers
//


inline int8_t MATHX_Get_Max_Int8(int8_t num1, int8_t num2)
{
	if (num1 >= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline uint8_t MATHX_Get_Max_UInt8(uint8_t num1, uint8_t num2)
{
	if (num1 >= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline int16_t MATHX_Get_Max_Int16(int16_t num1, int16_t num2)
{
	if (num1 >= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline uint16_t MATHX_Get_Max_UInt16(uint16_t num1, uint16_t num2)
{
	if (num1 >= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline int32_t MATHX_Get_Max_Int32(int32_t num1, int32_t num2)
{
	if (num1 >= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline uint32_t MATHX_Get_Max_UInt32(uint32_t num1, uint32_t num2)
{
	if (num1 >= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}



#ifdef NUM_64BIT_SUPPORT


inline int64_t MATHX_Get_Max_Int64(int64_t num1, int64_t num2)
{
	if (num1 >= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}


inline uint64_t MATHX_Get_Max_UInt64(uint64_t num1, uint64_t num2)
{
	if (num1 >= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

#endif



inline float MATHX_Get_Max_Float(float num1, float num2)
{
	if (num1 >= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}



// ===============================================================================



// функции для получения абсолютного значения переменной (модуля числа)
//
// -------------------------------------------------------------------------------
// functions for obtaining the absolute value of a variable (modulus of a number)
//


inline int8_t MATHX_Get_Abs_Int8(int8_t num)
{
	if (num < 0)
	{
		return -num;
	}
	else
	{
		return num;
	}
}


inline int16_t MATHX_Get_Abs_Int16(int16_t num)
{
	if (num < 0)
	{
		return -num;
	}
	else
	{
		return num;
	}
}


inline int32_t MATHX_Get_Abs_Int32(int32_t num)
{
	if (num < 0)
	{
		return -num;
	}
	else
	{
		return num;
	}
}



#ifdef NUM_64BIT_SUPPORT


inline int64_t MATHX_Get_Abs_Int64(int64_t num)
{
	if (num < 0)
	{
		return -num;
	}
	else
	{
		return num;
	}
}

#endif


inline float MATHX_Get_Abs_Float(float num)
{
	if (num < 0)
	{
		return -num;
	}
	else
	{
		return num;
	}
}



// ===============================================================================



// функции для ограничения значения переменной в заданном диапазоне
//
// -------------------------------------------------------------------------------
// functions for limiting the value of a variable in a given range
//


inline int8_t MATHX_Constrain_Int8(int8_t val, int8_t min, int8_t max)
{
	if (val <= min)
	{
		return min;
	}

	if (val >= max)
	{
		return max;
	}

	return val;
}


inline uint8_t MATHX_Constrain_UInt8(uint8_t val, uint8_t min, uint8_t max)
{
	if (val <= min)
	{
		return min;
	}

	if (val >= max)
	{
		return max;
	}

	return val;
}


inline int16_t MATHX_Constrain_Int16(int16_t val, int16_t min, int16_t max)
{
	if (val <= min)
	{
		return min;
	}

	if (val >= max)
	{
		return max;
	}

	return val;
}


inline uint16_t MATHX_Constrain_UInt16(uint16_t val, uint16_t min, uint16_t max)
{
	if (val <= min)
	{
		return min;
	}

	if (val >= max)
	{
		return max;
	}

	return val;
}


inline int32_t MATHX_Constrain_Int32(int32_t val, int32_t min, int32_t max)
{
	if (val <= min)
	{
		return min;
	}

	if (val >= max)
	{
		return max;
	}

	return val;
}


inline uint32_t MATHX_Constrain_UInt32(uint32_t val, uint32_t min, uint32_t max)
{
	if (val <= min)
	{
		return min;
	}

	if (val >= max)
	{
		return max;
	}

	return val;
}


#ifdef NUM_64BIT_SUPPORT



inline int64_t MATHX_Constrain_Int64(int64_t val, int64_t min, int64_t max)
{
	if (val <= min)
	{
		return min;
	}

	if (val >= max)
	{
		return max;
	}

	return val;
}


inline uint64_t MATHX_Constrain_UInt64(uint64_t val, uint64_t min, uint64_t max)
{
	if (val <= min)
	{
		return min;
	}

	if (val >= max)
	{
		return max;
	}

	return val;
}

#endif



inline float MATHX_Constrain_Float(float val, float min, float max)
{
	if (val <= min)
	{
		return min;
	}

	if (val >= max)
	{
		return max;
	}

	return val;
}



// ===============================================================================



// функции для линейного масштабирования значения переменной
//
// -------------------------------------------------------------------------------
// functions for linear scaling of a variable value
//


int32_t MATHX_Scaling_Int32(int32_t val, int32_t input_min_val, int32_t input_max_val, int32_t output_min_val, int32_t output_max_val);

uint32_t MATHX_Scaling_UInt32(uint32_t val, uint32_t input_min_val, uint32_t input_max_val, uint32_t output_min_val, uint32_t output_max_val);



#ifdef NUM_64BIT_SUPPORT

int64_t MATHX_Scaling_Int64(int64_t val, int64_t input_min_val, int64_t input_max_val, int64_t output_min_val, int64_t output_max_val);

uint64_t MATHX_Scaling_UInt64(uint64_t val, uint64_t input_min_val, uint64_t input_max_val, uint64_t output_min_val, uint64_t output_max_val);

#endif



float MATHX_Scaling_Float(float val, float input_min_val, float input_max_val, float output_min_val, float output_max_val);



// ===============================================================================



uint32_t MATHX_Get_GCD_UInt32(uint32_t num1, uint32_t num2);



#ifdef NUM_64BIT_SUPPORT

uint64_t MATHX_Get_GCD_UInt64(uint64_t num1, uint64_t num2);

#endif



// ===============================================================================



uint32_t MATHX_Get_LCM_UInt32(uint32_t a, uint32_t b);



#ifdef NUM_64BIT_SUPPORT

uint64_t MATHX_Get_LCM_UInt64(uint64_t a, uint64_t b);

#endif



// ===============================================================================



bool MATHX_Is_Prime_UInt32(uint32_t num);



#ifdef NUM_64BIT_SUPPORT

bool MATHX_Is_Prime_UInt64(uint64_t num);

#endif



// ===============================================================================



uint32_t MATHX_Get_Factorial_UInt32(uint8_t num);



#ifdef NUM_64BIT_SUPPORT

uint64_t MATHX_Get_Factorial_UInt64(uint8_t num);

#endif



#endif


