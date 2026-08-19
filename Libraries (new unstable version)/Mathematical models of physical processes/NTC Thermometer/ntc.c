

#include "ntc.h"



float NTC_Get_Temperature_To_Kelvin(const NTC_Data_Struct_t *ntc, const uint16_t adc_value)
{
	float U  = ((float)adc_value / ntc->adc_max_val) * ntc->U_ref;
	float R  = ntc->R_serial * (U / (ntc->U_gen - U));
	
	float lnR = logf(R);
	
	return 1.0 / (ntc->A_coef + (ntc->B_coef * lnR) + (ntc->C_coef * (lnR * lnR * lnR)));
}






