
#include <iostream>

#include "xorshift128.h"


const size_t NUM_OF_VALUES = 20000;


int main(void)
{
	XORShift128_t generator = XORShift128_Create_Object(0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210);

	// генерирация 10.000 чисел в диапазоне от 0 до 256
	// -------------------------------------------------------------------------------
	// generating 10,000 numbers in the range from 0 to 256
	for (size_t i = 0; i < NUM_OF_VALUES; i++)
	{
		std::cout << XORShift128_Get_UInt32_Value(&generator, 0, 256) << ", ";
	}
}


