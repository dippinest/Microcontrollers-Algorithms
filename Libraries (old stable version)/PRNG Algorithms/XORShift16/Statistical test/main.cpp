
#include <iostream>

#include "xorshift16.h"


const size_t NUM_OF_VALUES = 20000;


int main(void)
{
	XORShift16_t generator = XORShift16_Create_Object(0x1234);

	// генерирация 10.000 чисел в диапазоне от 0 до 256
	// -------------------------------------------------------------------------------
	// generating 10,000 numbers in the range from 0 to 256
	for (size_t i = 0; i < NUM_OF_VALUES; i++)
	{
		std::cout << XORShift16_Get_UInt16_Value(&generator, 0, 256) << ", ";
	}
}

