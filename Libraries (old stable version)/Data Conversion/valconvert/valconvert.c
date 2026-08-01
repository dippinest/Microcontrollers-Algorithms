
#include "valconvert.h"


float VALCONVERT_Angle_Radians_To_Degrees(float radians)
{
	return radians * VALCONVERT_ANGLE_NUM_DEGREES_TO_ONE_RADIAN;
}

float VALCONVERT_Angle_Degrees_To_Radians(float degrees)
{
	return degrees * VALCONVERT_ANGLE_NUM_RADIANS_TO_ONE_DEGREE;
}

float VALCONVERT_Speed_Meters_Per_Second_To_Kilometers_Per_Hour(float meters_per_second)
{
	return meters_per_second * VALCONVERT_SPEED_NUM_KILOMETERS_PER_HOUR_TO_ONE_METERS_PER_SECOND;
}

float VALCONVERT_Speed_Kilometers_Per_Hour_To_Meters_Per_Second(float kms_per_hour)
{
	return kms_per_hour * VALCONVERT_SPEED_NUM_METERS_PER_SECOND_TO_ONE_KILOMETERS_PER_HOUR;
}

float VALCONVERT_Speed_Miles_Per_Hour_To_Kilometers_Per_Hour(float kms_per_hour)
{
	return kms_per_hour * VALCONVERT_SPEED_NUM_KILOMETERS_PER_HOUR_TO_ONE_MILES_PER_HOUR;
}

float VALCONVERT_Speed_Kilometers_Per_Hour_To_Miles_Per_Hour(float miles_per_hour)
{
	return miles_per_hour * VALCONVERT_SPEED_NUM_MILES_PER_HOUR_TO_ONE_KILOMETERS_PER_HOUR;
}

float VALCONVERT_Length_Meters_To_Foots(float meters)
{
	return meters * VALCONVERT_LENGTH_NUM_METERS_TO_ONE_FOOT;
}

float VALCONVERT_Length_Foots_To_Meters(float foots)
{
	return foots * VALCONVERT_LENGTH_NUM_FOOTS_TO_ONE_METER;
}

float VALCONVERT_Length_Meters_To_Yards(float meters)
{
	return meters * VALCONVERT_LENGTH_NUM_YARD_TO_ONE_METER;
}

float VALCONVERT_Length_Yards_To_Meters(float yards)
{
	return yards * VALCONVERT_LENGTH_NUM_METERS_TO_ONE_YARD;
}

float VALCONVERT_Length_Centimeters_To_Inchs(float centimeters)
{
	return centimeters * VALCONVERT_LENGTH_NUM_INCHS_TO_ONE_CENTIMETER;
}

float VALCONVERT_Length_Inchs_To_Centimeters(float inchs)
{
	return inchs * VALCONVERT_LENGTH_NUM_CENTIMETERS_TO_ONE_INCH;
}

float VALCONVERT_Length_Kilometers_To_Miles(float kilometers)
{
	return kilometers * VALCONVERT_LENGTH_NUM_MILES_TO_ONE_KILOMETERS;
}

float VALCONVERT_Length_Miles_To_Kilometers(float miles)
{
	return miles * VALCONVERT_LENGTH_NUM_KILOMETERS_TO_ONE_MILES;
}

float VALCONVERT_Temperature_Celsius_To_Fahrenheit(float celsius_degrees)
{
	return (celsius_degrees * 1.8f) + 32.0f;
}

float VALCONVERT_Temperature_Fahrenheit_To_Celsius(float fahrenheit_degrees)
{
	return (fahrenheit_degrees - 32.0) * 0.555555f;
}

float VALCONVERT_Temperature_Celsius_To_Kelvin(float celsius_degrees)
{
	return celsius_degrees + 273.15f;
}

float VALCONVERT_Temperature_Kelvin_To_Celsius(float kelvin_degrees)
{
	return kelvin_degrees - 273.15f;
}

float VALCONVERT_Temperature_Celsius_To_Reaumur(float celsius_degrees)
{
	return celsius_degrees * 0.8f;
}

float VALCONVERT_Temperature_Reaumur_To_Celsius(float reaumur_degrees)
{
	return reaumur_degrees * 1.25f;
}

