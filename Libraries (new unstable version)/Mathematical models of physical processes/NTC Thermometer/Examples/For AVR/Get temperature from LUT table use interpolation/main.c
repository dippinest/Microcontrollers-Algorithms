

#include <util/delay.h>

#include "adc.h"
#include "uart.h"
#include "fdpn.h"



// LUT таблица с предрасчитанными значениями температуры.
// Код сгенерирован с помощью Python скрипта
// "Python scripts/Generate NTC LUT table/ntc_lut_tables_generator.py"
//
// Сгенерирована таблица размером 256 значений типа int16
// (тип FDPN (Fixed Decimal Point Number) с одним знаком после разделителя)
//
// -------------------------------------------------------------------------------
// LUT table with pre-calculated temperature values.
// The code was generated using the Python script
// "Python scripts/Generate NTC LUT table/ntc_lut_tables_generator.py"
//
// LUT table with 256 values int16 type has been generated
// (FDPN (Fixed Decimal Point Number) type with one character after the delimiter)
//


// ===============================================================================



#include <stdint.h>

#include <avr/pgmspace.h>



const int16_t LUT_Table[256] PROGMEM  =
{
	1796,  1199,   952,   820,   731,   665,   612,   568,
	531,   499,   470,   445,   422,   401,   381,   363,
	347,   331,   317,   303,   290,   277,   266,   255,
	244,   234,   224,   214,   205,   197,   188,   180,
	172,   165,   157,   150,   143,   136,   129,   123,
	117,   110,   104,    99,    93,    87,    82,    76,
	71,    66,    61,    56,    51,    46,    41,    37,
	32,    27,    23,    19,    14,    10,     6,     2,
	-1,    -6,   -10,   -13,   -17,   -21,   -25,   -29,
	-33,   -36,   -40,   -43,   -47,   -51,   -54,   -57,
	-61,   -64,   -68,   -71,   -74,   -78,   -82,   -85,
	-88,   -91,   -95,   -98,  -101,  -104,  -107,  -110,
	-113,  -116,  -119,  -122,  -125,  -128,  -131,  -134,
	-137,  -140,  -142,  -145,  -148,  -151,  -154,  -157,
	-159,  -162,  -165,  -168,  -171,  -173,  -176,  -179,
	-181,  -184,  -187,  -190,  -192,  -195,  -198,  -200,
	-203,  -206,  -208,  -211,  -214,  -216,  -219,  -222,
	-224,  -227,  -230,  -232,  -235,  -237,  -240,  -243,
	-245,  -248,  -251,  -253,  -256,  -259,  -261,  -264,
	-267,  -269,  -272,  -274,  -277,  -280,  -282,  -285,
	-288,  -291,  -293,  -296,  -299,  -301,  -304,  -307,
	-310,  -312,  -316,  -319,  -321,  -324,  -327,  -330,
	-333,  -335,  -338,  -341,  -344,  -347,  -350,  -353,
	-356,  -359,  -362,  -365,  -368,  -371,  -374,  -377,
	-380,  -383,  -387,  -390,  -393,  -396,  -400,  -403,
	-406,  -410,  -413,  -417,  -420,  -424,  -427,  -431,
	-435,  -438,  -442,  -446,  -450,  -454,  -458,  -462,
	-466,  -470,  -475,  -479,  -483,  -488,  -493,  -497,
	-502,  -507,  -512,  -517,  -523,  -528,  -534,  -540,
	-545,  -552,  -558,  -565,  -571,  -579,  -586,  -594,
	-602,  -610,  -619,  -629,  -639,  -650,  -661,  -674,
	-687,  -703,  -720,  -739,  -761,  -789,  -823,  -887
};


int16_t Get_Temperature_From_Lut_Table(uint16_t adc_value)
{
	if (adc_value > 255)
	{
		return LUT_Table[255];
	}


	return (int16_t)pgm_read_word(&LUT_Table[adc_value]);
};


int16_t Get_Temperature_From_Lut_Table_Use_Interpolation(uint16_t adc_value)
{
	if (adc_value >= 1023)
	{
		return LUT_Table[255];
	}


	const uint16_t index = adc_value >> 2;

	const uint16_t frac = adc_value & 3;


	const int16_t val1 = (int16_t)pgm_read_word(&LUT_Table[index]);
	const int16_t val2 = (int16_t)pgm_read_word(&LUT_Table[index + 1]);


	return val1 + (((int32_t)(val2 - val1)) * frac) / 4;
};



// ===============================================================================





char string_buffer[8];


int main(void)
{
	ADC_Initialize(0, ADC_PRESCALER_128, ADC_VREF_SOURCE_EXTERNAL_AVCC, true);
	
	UART_Initialize(9600, true, false);
	
	
	
	
	while (1)
	{
		uint16_t adc_val = ADC_Get_Value_10bit();
		
		
		// температура получается путём интерполяции промежуточных точек из LUT таблицы
		//
		// -------------------------------------------------------------------------------
		// temperature is obtained by interpolating intermediate points from the LUT table
		//
		// ===============================================================================
		//
		int16_t temp_to_celsius = Get_Temperature_From_Lut_Table_Use_Interpolation(adc_val);
		
		UART_String_Transmit("Temp (*C): "); UART_StringLn_Transmit(FDPN_Int16Base_Convert_Number_To_String(string_buffer, temp_to_celsius, 3, 1, '.'));
		
		
		_delay_ms(1000);
	}
}





