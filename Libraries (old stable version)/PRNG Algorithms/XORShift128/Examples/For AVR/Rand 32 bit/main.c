
#include <util/delay.h>

#include "uart.h"
#include "adc.h"
#include "xorshift128.h"



int main(void)
{
	UART_Initialize(115200, true, false);
	
	
	ADC_Initialize(0, ADC_PRESCALER_128, ADC_VREF_SOURCE_EXTERNAL_AVCC, true);
	
	
	// в качестве начального значения генератора следует использовать
	// любую относительно случайную величину. Для данной реализации ГПСЧ
	// я рекомендую использовать несколько источников энтропии
	// (напаример, шум АЦП, значение ячейки EEPROM памяти, инкрементирующейся
	// при каждом запуске и пр.). Кроме того, при инициализации желательно
	// использовать ещё и какую-либо константу, чтобы исключить инициализацию
	// данного ГСПЧ нулевым значением. В данном примере первые 3 параметра были
	// инициализированы шумом АЦП, а четвёртый - константой.
	//
	// Внимание! Следите за тем, чтобы начальное значение (seed)
	// не было равным нулю, иначе генератор работать не будет!
	//
	// -------------------------------------------------------------------------------
	// any relatively random value should be used as the initial value
	// of the generator. For this implementation of the RNG, I recommend
	// using several sources of entropy (for example, ADC noise, the value of
	// an EEPROM memory cell that increments with each startup, etc.).
	// In addition, it is advisable to use some constant during initialization
	// to exclude initialization of this RNG with a zero value. In this example,
	// the first 3 parameters were initialized with ADC noise, and the fourth
	// parameter was a constant.
	//
	// Attention! Make sure that the initial value (seed)
	// is not zero, otherwise the generator will not work!
	//
	XORShift128_t generator = XORShift128_Create_Object(
	
		ADC_Get_Random_Entropy_Value_32bit(0),
		ADC_Get_Random_Entropy_Value_32bit(0),
		ADC_Get_Random_Entropy_Value_32bit(0),
		0x12345678
	);
	
	while (1)
	{
		// генерируем случайное число типа int32_t
		// в диапазоне от -100 до (100 - 1)
		//
		// -------------------------------------------------------------------------------
		// generating a random number of type int32_t
		// in the range from -100 to (100 - 1)
		//
		int32_t random_number = XORShift128_Get_Int32_Value(&generator, -100, 100);
		
		UART_StringFmt_Transmit("%d, ", random_number);
		
		_delay_ms(100);
	}
}




