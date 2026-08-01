
#include <util/delay.h>

#include "uart.h"
#include "adc.h"
#include "itoa.h"
#include "random.h"


char buffer[16];

int main(void)
{
	UART_Initialize(115200, true, false);
	
	ITOA_Set_String_Buffer(buffer);
	
	
	ADC_Initialize(0, ADC_PRESCALER_128, ADC_VREF_SOURCE_EXTERNAL_AVCC, true);
	
	
	// в качестве начального зерна следует использовать любую относительно
	// случайную величину. Я рекомендую использовать шум на любом неподключенном
	// входе АЦП микроконтроллера. В библиотеке adc.h из набора библиотек
	// AVR Libraries есть соответствующая функция для чтения энтропийного значения
	//
	// -------------------------------------------------------------------------------
	// any relatively random value should be used for the initial grain.
	// I recommend using noise on any unconnected ADC input of the MCU.
	// The adc.h library from the AVR Libraries set has a corresponding
	// function for reading the entropy value
	//
	Random_Set_Seed(ADC_Get_Random_Entropy_Value_16bit(0));
	
	while (1)
	{
		// генерируем случайное число типа int32_t
		// в диапазоне от -1_000_000_000 до (1_000_000_000 - 1)
		//
		// -------------------------------------------------------------------------------
		// generating a random number of type int32_t
		// in the range from -1_000_000_000 to (1_000_000_000 - 1)
		//
		int32_t random_number = Random_Get_Int32_Value(-1000000000, 1000000000);
		
		UART_StringLn_Transmit(ITOA_Int32_To_String(random_number, 12));
		
		_delay_ms(100);
	}
}

