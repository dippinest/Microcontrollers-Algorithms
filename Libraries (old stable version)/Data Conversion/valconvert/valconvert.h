
// ===============================================================================
//
// Небольшая библиотека - конвертер некоторых величин.
//
// Это библиотека из старых наработок, вдруг кому-нибудь пригодится :)
//
// -------------------------------------------------------------------------------
//
// A small library - converter of some quantities.
//
// This is a library of old developments, suddenly it will be useful to someone :)
//
// ===============================================================================


#ifndef VALCONVERT_H_
#define VALCONVERT_H_


#define VALCONVERT_ANGLE_NUM_RADIANS_TO_ONE_DEGREE                         0.0174459f;
#define VALCONVERT_ANGLE_NUM_DEGREES_TO_ONE_RADIAN                         57.295779f;
#define VALCONVERT_SPEED_NUM_KILOMETERS_PER_HOUR_TO_ONE_METERS_PER_SECOND  3.6f;
#define VALCONVERT_SPEED_NUM_METERS_PER_SECOND_TO_ONE_KILOMETERS_PER_HOUR  0.2777777f;
#define VALCONVERT_SPEED_NUM_MILES_PER_HOUR_TO_ONE_KILOMETERS_PER_HOUR     0.621371f;
#define VALCONVERT_SPEED_NUM_KILOMETERS_PER_HOUR_TO_ONE_MILES_PER_HOUR     1.60934f;
#define VALCONVERT_LENGTH_NUM_METERS_TO_ONE_FOOT                           3.28084;
#define VALCONVERT_LENGTH_NUM_FOOTS_TO_ONE_METER                           0.3048f;
#define VALCONVERT_LENGTH_NUM_METERS_TO_ONE_YARD                           0.9144f;
#define VALCONVERT_LENGTH_NUM_YARD_TO_ONE_METER                            1.09361f;
#define VALCONVERT_LENGTH_NUM_INCHS_TO_ONE_CENTIMETER                      0.393701f;
#define VALCONVERT_LENGTH_NUM_CENTIMETERS_TO_ONE_INCH                      2.54f;
#define VALCONVERT_LENGTH_NUM_KILOMETERS_TO_ONE_MILES                      1.60934f;
#define VALCONVERT_LENGTH_NUM_MILES_TO_ONE_KILOMETERS                      0.621371f;



// ===============================================================================


float VALCONVERT_Angle_Radians_To_Degrees(float radians);

float VALCONVERT_Angle_Degrees_To_Radians(float degrees);

float VALCONVERT_Speed_Meters_Per_Second_To_Kilometers_Per_Hour(float meters_per_second);

float VALCONVERT_Speed_Kilometers_Per_Hour_To_Meters_Per_Second(float kms_per_hour);

float VALCONVERT_Speed_Miles_Per_Hour_To_Kilometers_Per_Hour(float kms_per_hour);

float VALCONVERT_Speed_Kilometers_Per_Hour_To_Miles_Per_Hour(float miles_per_hour);

float VALCONVERT_Length_Meters_To_Foots(float meters);

float VALCONVERT_Length_Foots_To_Meters(float foots);

float VALCONVERT_Length_Meters_To_Yards(float meters);

float VALCONVERT_Length_Yards_To_Meters(float yards);

float VALCONVERT_Length_Centimeters_To_Inchs(float centimeters);

float VALCONVERT_Length_Inchs_To_Centimeters(float inchs);

float VALCONVERT_Length_Kilometers_To_Miles(float kilometers);

float VALCONVERT_Length_Miles_To_Kilometers(float miles);

float VALCONVERT_Temperature_Celsius_To_Fahrenheit(float celsius_degrees);

float VALCONVERT_Temperature_Fahrenheit_To_Celsius(float fahrenheit_degrees);

float VALCONVERT_Temperature_Celsius_To_Kelvin(float celsius_degrees);

float VALCONVERT_Temperature_Kelvin_To_Celsius(float kelvin_degrees);

float VALCONVERT_Temperature_Celsius_To_Reaumur(float celsius_degrees);

float VALCONVERT_Temperature_Reaumur_To_Celsius(float reaumur_degrees);


#endif

