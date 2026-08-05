
// ===============================================================================
//
// Библиотека, реализующая функции CRT коррекции цвета, излучаемый светодиодными
// источниками (отдельные светодиоды, светодиодные ленты и т.д.).
//
// Необходимость коррекции цвета обусловлена нелинейностью восприятия
// интенсивности света человеческим глазом
// (см. закон Велера-Фехнера - https://ru.wikipedia.org/wiki/Закон_Вебера_—_Фехнера).
//
// Экспериментальным путём (с помощью Scilab) были выявлены функции,
// наиболее близко описывающие зависимость зрительного восприятия
// интенсивности цвета S от светового потока светодиодов R:
//
// 1. S(R) = k * R^n   - степенная зависимость,
//                       где k и n - const (k = 16.04 и n = 0.(3))
//
// 2. S(R) = k * ln(R) - логарифмическая зависимость,
//                       где k - const = 18.02
//
// Значения этих функции для 8-ми битного аргумента были выведены в таблицы,
// по которым и происходит CRT коррекция
//
// -------------------------------------------------------------------------------
//
// Library that implements the functions of CRT color
// correction emitted by LED sources (individual LEDs, LED strips, etc.).
//
// The need for color correction is due to the nonlinearity of the
// perception of light intensity by the human eye
// (see the Wehler-Fechner law - https://en.wikipedia.org/wiki/Weber–Fechner_law).
//
// Experimentally (using Scilab), functions were identified that most
// closely describe the dependence of visual perception of color
// intensity S on the luminous flux of LEDs R:
//
// 1. S(R) = k * R^n   - power dependence,
//                       where k and n - const (k = 16.04 и n = 0.(3))
//
// 2. S(R) = k * ln(R) - logarithmic dependence,
//                       where k - const = 18.02
//
// The values of these functions for the 8-bit argument were output
// to tables, according to which the CRT correction takes place
//
// ===============================================================================


#ifndef GAMMA_H_
#define GAMMA_H_

#include <avr/pgmspace.h>

#include <stdint.h>


uint8_t Gamma_Correction_Get_Power_Approximation_Value(uint8_t value);

uint8_t Gamma_Correction_Get_Logarithmic_Approximation_Value(uint8_t value);


#endif

