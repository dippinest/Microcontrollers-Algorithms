

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







