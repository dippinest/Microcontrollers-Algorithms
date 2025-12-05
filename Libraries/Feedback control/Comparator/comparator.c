
#include "comparator.h"


bool Comparator_Int8_Update_And_Get_Output_Value
(
	bool *comparator_state,
	const int8_t input_positive,
	const int8_t input_negative,
	const int8_t high_hysteresys,
	const int8_t low_hysteresys
)
{
	if (input_positive >= (input_negative + high_hysteresys))
	{
		*comparator_state = true;
	}
	
	if (input_positive <= (input_negative + low_hysteresys))
	{
		*comparator_state = false;
	}
	
	
	return *comparator_state;
}


bool Comparator_Int16_Update_And_Get_Output_Value
(
	bool *comparator_state,
	const int16_t input_positive,
	const int16_t input_negative,
	const int16_t high_hysteresys,
	const int16_t low_hysteresys
)
{
	if (input_positive >= (input_negative + high_hysteresys))
	{
		*comparator_state = true;
	}
	
	if (input_positive <= (input_negative + low_hysteresys))
	{
		*comparator_state = false;
	}
	
	
	return *comparator_state;
}


bool Comparator_Int32_Update_And_Get_Output_Value
(
	bool *comparator_state,
	const int32_t input_positive,
	const int32_t input_negative,
	const int32_t high_hysteresys,
	const int32_t low_hysteresys
)
{
	if (input_positive >= (input_negative + high_hysteresys))
	{
		*comparator_state = true;
	}
	
	if (input_positive <= (input_negative + low_hysteresys))
	{
		*comparator_state = false;
	}
	
	
	return *comparator_state;
}


bool Comparator_Float_Update_And_Get_Output_Value
(
	bool *comparator_state,
	const float input_positive,
	const float input_negative,
	const float high_hysteresys,
	const float low_hysteresys
)
{
	if (input_positive >= (input_negative + high_hysteresys))
	{
		*comparator_state = true;
	}
	
	if (input_positive <= (input_negative + low_hysteresys))
	{
		*comparator_state = false;
	}
	
	
	return *comparator_state;
}




