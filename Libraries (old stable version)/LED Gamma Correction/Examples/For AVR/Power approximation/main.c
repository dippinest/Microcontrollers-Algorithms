

#include <avr/io.h>

#include <util/delay.h>

#include "gamma.h"


// инициализация ШИМ сигнала на выводе PD7 (ATmega32A, Таймер 2)
//
// -------------------------------------------------------------------------------
// initialization of the PWM signal on the PD7 pin (ATmega32A, Timer 2)
//
inline void TIMER0_PWM_Initialize()
{
	DDRD    |= (1 << 7); // PD7 - PWM output
	
	TCCR2   |= (1 << WGM20)
		|  (1 << WGM21) // Fast PWM
		|  (1 << COM20)
		|  (1 << COM21)
		|  (1 << CS20); // not div
		  
	OCR2 = 0;
}

#define TIMER2_PWM_PD7_OUT OCR2



int main(void)
{
	TIMER0_PWM_Initialize();
	
	uint8_t   value = 0;
	int8_t additive = 1;
	
	while (1)
	{
		// будем плавно зажигать и гасить светодиод
		//
		// -------------------------------------------------------------------------------
		// we will smoothly light and extinguish the LED
		//
		
		if (value == 0x00)
		{
			additive =  1;
		}
		
		if (value == 0xFF)
		{
			additive = -1;
		}
		
		value += additive;
		
		// выполняем CRT коррекцию
		//
		// -------------------------------------------------------------------------------
		// performing CRT correction
		//
		TIMER2_PWM_PD7_OUT = Gamma_Correction_Get_Power_Approximation_Value(value);
		
		_delay_ms(10);
	}
}


