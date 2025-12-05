
// ===============================================================================
//
// Библиотека программной реализации компаратора с верхним и нижним гистерезисом.
//
// Компаратор сравнивает значения положительного (input_positive)
// и отрицательного (input_negative) входов и даёт на выходе следующие значения:
//
//
//                     / COMPARATOR_OUTPUT_IS_HIGH (true): если input_positive >= (input_negative + high_hysteresys)
// Comparator_output = |
//                     \ COMPARATOR_OUTPUT_IS_LOW (false): если input_positive <= (input_negative + high_hysteresys)
//
//
// Компаратор используется в простых системах управления объектами, обладающими большой инерционностью
// (например, управление включения света в зависимости от освещённости,
// управление мощным нагревателем и т.д.)
//
// -------------------------------------------------------------------------------
//
// Library for software implementation
// of the upper and lower hysteresis comparator.
//
// The comparator compares the values of the positive (input_positive)
// and negative (input_negative) inputs and outputs the following values:
//
//
//
//                     / COMPARATOR_OUTPUT_IS_HIGH (true): если input_positive >= (input_negative + high_hysteresys)
// Comparator_output = |
//                     \ COMPARATOR_OUTPUT_IS_LOW (false): если input_positive <= (input_negative + high_hysteresys)
//
// The comparator is used in simple control systems
// (for example, control of turning on the light depending on the illumination,
// control of a powerful heater, etc.)
//
// ===============================================================================


#ifndef COMPARATOR_H_
#define COMPARATOR_H_


#include <stdint.h>
#include <stdbool.h>



#define COMPARATOR_OUTPUT_IS_HIGH true
#define COMPARATOR_OUTPUT_IS_LOW  false


// ===============================================================================


bool Comparator_Int8_Update_And_Get_Output_Value
(
	bool *comparator_state,
	const int8_t input_positive,
	const int8_t input_negative,
	const int8_t high_hysteresys,
	const int8_t low_hysteresys
);


bool Comparator_Int16_Update_And_Get_Output_Value
(
	bool *comparator_state,
	const int16_t input_positive,
	const int16_t input_negative,
	const int16_t high_hysteresys,
	const int16_t low_hysteresys
);


bool Comparator_Int32_Update_And_Get_Output_Value
(
	bool *comparator_state,
	const int32_t input_positive,
	const int32_t input_negative,
	const int32_t high_hysteresys,
	const int32_t low_hysteresys
);


bool Comparator_Float_Update_And_Get_Output_Value
(
	bool *comparator_state,
	const float input_positive,
	const float input_negative,
	const float high_hysteresys,
	const float low_hysteresys
);



#endif




