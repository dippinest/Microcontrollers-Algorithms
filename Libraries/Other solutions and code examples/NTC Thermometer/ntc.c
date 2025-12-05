
#include "ntc.h"


float NTC_Get_Temperature_To_Kelvin
(
	uint16_t adc_value,
	uint16_t adc_max_val,
	float    U_ref,
	float    U_gen,
	float    R_serial,
	float    A_coef,
	float    B_coef,
	float    C_coef
)
{
	float U  = ((float)adc_value / adc_max_val) * U_ref;
	float R  = R_serial * (U / (U_gen - U));
	
	float lnR = log(R);
	
	return 1.0 / (A_coef + (B_coef * lnR) + (C_coef * (lnR * lnR * lnR)));
}


