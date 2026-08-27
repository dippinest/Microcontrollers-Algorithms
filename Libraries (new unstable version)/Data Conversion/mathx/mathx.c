

#include "mathx.h"



int32_t MATHX_Scaling_Int32(int32_t val, int32_t input_min_val, int32_t input_max_val, int32_t output_min_val, int32_t output_max_val)
{
	int32_t new_val = ((val - input_min_val) * (output_max_val - output_min_val)) /
	(input_max_val - input_min_val) + output_min_val;

	return new_val;
}

uint32_t MATHX_Scaling_UInt32(uint32_t val, uint32_t input_min_val, uint32_t input_max_val, uint32_t output_min_val, uint32_t output_max_val)
{
	uint32_t new_val = ((val - input_min_val) * (output_max_val - output_min_val)) /
	(input_max_val - input_min_val) + output_min_val;

	return new_val;
}


#ifdef NUM_64BIT_SUPPORT


int64_t MATHX_Scaling_Int64(int64_t val, int64_t input_min_val, int64_t input_max_val, int64_t output_min_val, int64_t output_max_val)
{
	int64_t new_val = ((val - input_min_val) * (output_max_val - output_min_val)) /
	(input_max_val - input_min_val) + output_min_val;

	return new_val;
}

uint64_t MATHX_Scaling_UInt64(uint64_t val, uint64_t input_min_val, uint64_t input_max_val, uint64_t output_min_val, uint64_t output_max_val)
{
	uint64_t new_val = ((val - input_min_val) * (output_max_val - output_min_val)) /
	(input_max_val - input_min_val) + output_min_val;

	return new_val;
}

#endif


float MATHX_Scaling_Float(float val, float input_min_val, float input_max_val, float output_min_val, float output_max_val)
{
	float new_val = ((val - input_min_val) * (output_max_val - output_min_val)) /
	(input_max_val - input_min_val) + output_min_val;

	return new_val;
}



// ===============================================================================



uint32_t MATHX_Get_GCD_UInt32(uint32_t num1, uint32_t num2)
{
	uint32_t temp;
	
	while (num2 != 0)
	{
		temp = num2;
		
		num2 = num1 % num2;
		
		num1 = temp;
	}
	
	return num1;
}



#ifdef NUM_64BIT_SUPPORT

uint64_t MATHX_Get_GCD_UInt64(uint64_t num1, uint64_t num2)
{
	uint64_t temp;
	
	while (num2 != 0)
	{
		temp = num2;
		
		num2 = num1 % num2;
		
		num1 = temp;
	}
	
	return num1;
}

#endif



// ===============================================================================



uint32_t MATHX_Get_LCM_UInt32(uint32_t a, uint32_t b)
{
	uint32_t lcm = (a / MATHX_Get_GCD_UInt32(a, b)) * b;
	
	return lcm;
}



#ifdef NUM_64BIT_SUPPORT

uint64_t MATHX_Get_LCM_UInt64(uint64_t a, uint64_t b)
{
	uint64_t lcm = (a / MATHX_Get_GCD_UInt64(a, b)) * b;
	
	return lcm;
}

#endif



// ===============================================================================



bool MATHX_Is_Prime_UInt32(uint32_t num)
{
	if (num < 2)
	{
		return false;
	}
	
	if ((num & 0b1) == 0)
	{
		return (bool)(num == 2);
	}
	
	
	for (uint32_t i = 3; (i * i) <= num; i += 2)
	{
		if ((num % i) == 0)
		{
			return false;
		}
	}
	
	
	return true;
}



#ifdef NUM_64BIT_SUPPORT

bool MATHX_Is_Prime_UInt64(uint64_t num)
{
	if (num < 2)
	{
		return false;
	}
	
	if ((num & 0b1) == 0)
	{
		return (bool)(num == 2);
	}
	
	
	for (uint64_t i = 3; (i * i) <= num; i += 2)
	{
		if ((num % i) == 0)
		{
			return false;
		}
	}
	
	
	return true;
}

#endif



// ===============================================================================



uint32_t MATHX_Get_Factorial_UInt32(uint8_t num)
{
	if (num > 12)
	{
		return 0;
	}
	
	
	uint32_t result = 1;
	
	for (uint8_t i = 2; i <= num; i++)
	{
		result *= (uint32_t)i;
	}
	
	return result;
}



#ifdef NUM_64BIT_SUPPORT

uint64_t MATHX_Get_Factorial_UInt64(uint8_t num)
{
	if (num > 20)
	{
		return 0;
	}
	
	
	uint64_t result = 1;
	
	for (uint8_t i = 2; i <= num; i++)
	{
		result *= (uint64_t)i;
	}
	
	return result;
}

#endif



// ===============================================================================



void MATHX_Convert_Decimal_Fraction_To_Common_Fraction
(
	float val,

	int32_t *numerator,
	int32_t *denominator,

	const float epsilon
)
{
	int8_t sign = 1;


	if (val < 0)
	{
		sign = -1;
		val = -val;
	}


	if (val < epsilon)
	{
		*numerator = 0;
		*denominator = 1;

		return;
	}



	int32_t integer_part = (int32_t)val;

	float fractional = val - integer_part;




	if (fractional < epsilon)
	{
		*numerator = sign * integer_part;
		*denominator = 1;

		return;
	}




	int32_t a0 = integer_part;
	int32_t a;

	float f = fractional;


	int32_t prev_num = 1;
	int32_t curr_num = a0;
	int32_t prev_den = 0;
	int32_t curr_den = 1;

	int max_iter = 50;



	for (int i = 0; i < max_iter; i++)
	{
		if (f < epsilon)
		{
			break;
		}


		a = (int32_t)(1.0f / f);
		f = (1.0f / f) - a;


		int32_t next_num = (a * curr_num) + prev_num;
		int32_t next_den = (a * curr_den) + prev_den;


		if ((next_num > 1000000) || (next_den > 1000000))
		{
			break;
		}



		float approx = (float)next_num / (float)next_den;

		float error;


		if (approx > val)
		{
			error = approx - val;
		}
		else
		{
			error = val - approx;
		}



		if (error < epsilon)
		{
			*numerator = sign * next_num;
			*denominator = next_den;

			return;
		}


		prev_num = curr_num;
		curr_num = next_num;
		prev_den = curr_den;
		curr_den = next_den;
	}


	*numerator   = sign * curr_num;
	*denominator = curr_den;
}



// ===============================================================================




