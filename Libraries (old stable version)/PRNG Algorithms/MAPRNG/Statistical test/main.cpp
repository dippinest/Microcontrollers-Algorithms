
#include <iostream>


// Инициализация участка памяти внутренней RAM (массива) для MAPRNG
// размером 16 байта
// -------------------------------------------------------------------------------
// Initialization of an internal RAM (array) memory segment for a 16-byte MAPRNG
const size_t MAPRNG_MUTABLE_ARRAY_SIZE = 16;

uint8_t MAPRNG_MUTABLE_ARRAY[MAPRNG_MUTABLE_ARRAY_SIZE];



// колбэк функции для I/O операций с участком памяти (массивом) для MAPRNG
// -------------------------------------------------------------------------------
// callback functions for I/O operations with a memory area (array) for MAPRNG
void write_byte(uint16_t addr, uint8_t value)
{
	MAPRNG_MUTABLE_ARRAY[addr] = value;
}

uint8_t read_byte(uint16_t addr)
{
	return MAPRNG_MUTABLE_ARRAY[addr];
}


const size_t NUM_OF_VALUES = 100000;

int main(void)
{
	// Инициализация ГПСЧ. Адрес начальной рабочей ячейки - 0x0000.
	// Диапазон рабочих адресов - от 0x0000 до 0x0020 (32 dec)
	// -------------------------------------------------------------------------------
	// Initialization of the PRNG. The address of the initial working cell is 0x0000.
	// The range of working addresses is from 0x0000 to 0x0020 (32 dec)
	MAPRNG_t maprng = MAPRNG_Create_Object(0x0001, 0x0000, MAPRNG_MUTABLE_ARRAY_SIZE, read_byte, write_byte);

	// генерирация 10.000 чисел в диапазоне от 0 до 256
	// -------------------------------------------------------------------------------
	// generating 10,000 numbers in the range from 0 to 256
	for (size_t i = 0; i < NUM_OF_VALUES; i++)
	{
		std::cout << MAPRNG_Get_UInt16_Value(&maprng, 0, 256) << ", ";
	}
}




