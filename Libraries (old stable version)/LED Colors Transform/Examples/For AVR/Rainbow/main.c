
// ===============================================================================
//
// Пример преобразования цветового пространства HSV в цветовое
// пространство RGB при управлении трехканальной RGB светодиодной лентой.
//
// ШИМ в данном примере использован программный разрядностью 4 бита
// (16 градаций цвета для каждого канала)
//
// -------------------------------------------------------------------------------
//
// An example of converting HSV color space to RGB color space
// when controlling a three-channel RGB LED strip.
//
// The PWM in this example uses a 4-bit program bit
// (16 color gradations for each channel)
//
// ===============================================================================


#include <avr/io.h>
#include <avr/interrupt.h>

#include <util/delay.h>

#include "softpwm_inline.h"
#include "color_transform.h"


// макросы с определениями разрядности программного ШИМ (16 градаций) и количества каналов
//
// -------------------------------------------------------------------------------
// macros with definitions of the bit depth of the software PWM (16 gradations) and the
// number of channels
//
#define MAX_PWM_WIDTH 0xF
#define SOFTPWM_NUM_OF_CHANNELS 3


// массив каналов программного ШИМ
//
// -------------------------------------------------------------------------------
// array of software PWM channels
//
SOFTPWM_Inline_t softpwm[SOFTPWM_NUM_OF_CHANNELS];


// инициализируем таймера 2 (Timer2)
//
// -------------------------------------------------------------------------------
// Timer2 initialize
//
inline void TIMER2_Initialize()
{
	TCCR2 = (1 << CS20);  // div F_CPU / 8 (16 MHz / (8 * MAX_PWM_WIDTH) = 125 kHz)
	TIMSK = (1 << TOIE2); // set overflow interrupt
}


// обработка всех каналов ШИМ в прерывании по переполнению таймера 2 (Timer2)
//
// -------------------------------------------------------------------------------
// processing of all PWM channels in the overflow interrupt Timer2
//
ISR(TIMER2_OVF_vect)
{
	SOFTPWM_Inline_All_Channels_Processing(softpwm, SOFTPWM_NUM_OF_CHANNELS);
}


int main(void)
{
	TIMER2_Initialize();
	
	// инициализация портов GPIO и каналов программного ШИМ
	//
	// -------------------------------------------------------------------------------
	// initialization of GPIO ports and software PWM channels
	//
	DDRB |= (1 << 1) | (1 << 2) | (1 << 3);

	softpwm[0] = SOFTPWM_Inline_Create_Object(T(PORTB), 1, MAX_PWM_WIDTH, MAX_PWM_WIDTH);
	softpwm[1] = SOFTPWM_Inline_Create_Object(T(PORTB), 2, MAX_PWM_WIDTH, MAX_PWM_WIDTH);
	softpwm[2] = SOFTPWM_Inline_Create_Object(T(PORTB), 3, MAX_PWM_WIDTH, MAX_PWM_WIDTH);
	
	sei();
	
	HSV_t hsv = { 0x00, 0xFF, 0xFF };
	
	while (1)
	{
		// инкрементируем компоненту h, вращая цветовой круг с целью получения радуги
		//
		// -------------------------------------------------------------------------------
		// increment the h component by rotating the color wheel to produce a rainbow
		//
		hsv.h++;
		
		// преобразуем цветовое пространство HSV в цветовое пространство RGB
		//
		// -------------------------------------------------------------------------------
		// convert HSV color space to RGB color space
		//
		RGB_t rgb = Color_Transform_HSV_To_RGB(hsv);
		
		// масштабируем 8-ми битное значение каждого канала
		// цветового пространства RGB в 4-х битное значение
		// (16 градаций) путём деления на 16 (сдвиг вправо на 4)
		//
		// -------------------------------------------------------------------------------
		// scaling the 8-bit value of each RGB color space
		// channel into a 4-bit value (16 gradations) by
		// dividing by 16 (right shift by 4)
		//
		SOFTPWM_INLINE_DUTY_CYCLE(softpwm[0]) = rgb.r >> 4;
		SOFTPWM_INLINE_DUTY_CYCLE(softpwm[1]) = rgb.g >> 4;
		SOFTPWM_INLINE_DUTY_CYCLE(softpwm[2]) = rgb.b >> 4;
		
		_delay_ms(5);
	}
}



