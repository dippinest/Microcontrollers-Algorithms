

#include <util/delay.h>

#include "uart.h"
#include "maprng.h"
#include "softi2c.h"
#include "eepromi2c.h"


// я использую чип 24C16 с 16-ю килобитами памяти
// -------------------------------------------------------------------------------
// I use 24C16 chip (16 kbit)
#define EEPROM_CHIP_ADDR     EEPROMI2C_DEV_ADDR_A2F_A1F_A0F
#define EEPROM_PAGE_SIZE     EEPROMI2C_24C16_PAGE_SIZE
#define EEPROM_MAX_MEM_ADDR  EEPROMI2C_24C16_MAX_MEM_ADDR


// колбэк функции для I/O операций с участком памяти (массивом) для MAPRNG
// -------------------------------------------------------------------------------
// callback functions for I/O operations with a memory area (array) for MAPRNG
void write_byte(uint16_t addr, uint8_t value)
{
	EEPROMI2C_Write_Byte(addr, value);
}

uint8_t read_byte(uint16_t addr)
{
	return EEPROMI2C_Read_Byte(addr);
}


// Размер рабочего участка памяти внешней EEPROM - 32 байта
// -------------------------------------------------------------------------------
// The size of the working memory area of the external EEPROM is 32 bytes
#define MAPRNG_MUTABLE_ARRAY_SIZE 32


int main(void)
{
	UART_Initialize(9600, true, false);
	
	SOFTI2C_Initialize();
	
	
	// Инициализация внешней EEPROM
	// -------------------------------------------------------------------------------
	// Initializing an external EEPROM
	EEPROMI2C_t eeprom = EEPROMI2C_Create_Object(EEPROM_CHIP_ADDR, EEPROM_MAX_MEM_ADDR, EEPROM_PAGE_SIZE);
	
	EEPROMI2C_Set_Target_Object(&eeprom);
	
	
	
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



