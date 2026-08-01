

#include <util/delay.h>

#include "uart.h"
#include "maprng.h"


// Инициализация участка памяти внутренней RAM (массива) для MAPRNG
// размером 32 байта
// -------------------------------------------------------------------------------
// Initialization of an internal RAM (array) memory segment for a 32-byte MAPRNG
#define MAPRNG_MUTABLE_ARRAY_SIZE 32

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


int main(void)
{
	UART_Initialize(9600, true, false);
	
	
	// Инициализация ГПСЧ. Адрес начальной рабочей ячейки - 0x0000.
	// Диапазон рабочих адресов - от 0x0000 до 0x0020 (MAPRNG_MUTABLE_ARRAY_SIZE)
	// -------------------------------------------------------------------------------
	// Initialization of the PRNG. The address of the initial working cell is 0x0000.
	// The range of working addresses is from 0x0000 to 0x0020 (MAPRNG_MUTABLE_ARRAY_SIZE)
	MAPRNG_t maprng = MAPRNG_Create_Object(0x0000, 0x0000, MAPRNG_MUTABLE_ARRAY_SIZE, read_byte, write_byte);
	
	while (1)
	{
		// Генерация 8-ми битного псевдослучайного значения
		// -------------------------------------------------------------------------------
		// Generating an 8-bit pseudo-random value
		uint8_t s = MAPRNG_Get_8Bit_Value(&maprng);
		
		UART_StringFmt_Transmit("%i, ", s); _delay_ms(100);
	}
}



