

# ===============================================================================
#
#  Скрипт для расчёта коэффициентов A, B и C уравнения Стейнхарта-Харта
#  по трём известным точкам (при известных сопротивлении и температуры)
#
#  Используется метод решения системы линейных уравнений (метод Крамера).
#  На выходе получаются коэффициенты для использования в NTC-библиотеке
#  и в скрипте для генерации LUT-таблиц
#
#  Подробнее об использованном методе можно узнать из Википедии:
#  https://ru.wikipedia.org/wiki/Уравнение_Стейнхарта_—_Харта
#
# -------------------------------------------------------------------------------
#
#  Script for calculating the coefficients A, B and C of the Steinhart-Hart
#  equation using three known points (given the resistance and temperature)
#
#  Uses the method of solving a system of linear equations (Cramer's method).
#  The output is coefficients for use in the NTC library
#  and in the script for generating LUT tables
#
#  You can learn more about the method used on Wikipedia:
#  https://en.wikipedia.org/wiki/Steinhart–Hart_equation
#
# ===============================================================================




import math
from enum import Enum, auto, unique






# ===============================================================================
#                               ПЕРЕЧИСЛЕНИЯ
# ===============================================================================
#                                  ENUMS
# ===============================================================================


@unique
class Converter(Enum):

    '''
    класс перечислений единиц измерения температуры
    -------------------------------------------------------------------------------
    temperature measurement unit enumeration class
    '''

    KELVIN     = auto()
    CELSIUS    = auto()
    FAHRENHEIT = auto()






# ===============================================================================
#                      ФУНКЦИИ КОНВЕРТАЦИИ ТЕМПЕРАТУРЫ
# ===============================================================================
#                      TEMPERATURE CONVERSION FUNCTIONS
# ===============================================================================


def celsius_to_kelvin(celsius_temperature):

    '''
    функция преобразования температуры из градусов Цельсия в Кельвины
    -------------------------------------------------------------------------------
    function for converting temperature from Celsius to Kelvin
    '''


    return celsius_temperature + 273.15




def fahrenheit_to_kelvin(fahrenheit_temperature):

    '''
    функция преобразования температуры из градусов Фаренгейта в Кельвины
    -------------------------------------------------------------------------------
    function for converting temperature from Fahrenheit to Kelvin
    '''


    return (fahrenheit_temperature - 32.0) * (5.0 / 9.0) + 273.15




def temperature_to_kelvin(
    temperature_value,
    converter_type=Converter.CELSIUS
):

    '''
    функция универсального конвертера температуры в Кельвины
    -------------------------------------------------------------------------------
    universal temperature converter function to Kelvin
    '''


    if converter_type == Converter.KELVIN:
        return temperature_value

    elif converter_type == Converter.CELSIUS:
        return celsius_to_kelvin(temperature_value)

    elif converter_type == Converter.FAHRENHEIT:
        return fahrenheit_to_kelvin(temperature_value)

    else:
        raise ValueError(f"Неподдерживаемый тип (unsupported type): {converter_type}\n")






# ===============================================================================
#                     РЕШЕНИЕ СИСТЕМЫ ЛИНЕЙНЫХ УРАВНЕНИЙ
# ===============================================================================
#                  SOLUTION OF A SYSTEM OF LINEAR EQUATIONS
# ===============================================================================


def solve_linear_system_3x3(matrix, vector):

    '''
    решение системы линейных уравнений 3x3 методом Крамера
    -------------------------------------------------------------------------------
    solving a 3x3 system of linear equations using Cramer's method
    '''


    # извлекаем коэффициенты матрицы
    a11, a12, a13 = matrix[0]
    a21, a22, a23 = matrix[1]
    a31, a32, a33 = matrix[2]

    # извлекаем вектор правой части
    b1, b2, b3 = vector


    # вычисляем определитель основной матрицы
    det_main = (a11 * (a22 * a33 - a23 * a32) -
                a12 * (a21 * a33 - a23 * a31) +
                a13 * (a21 * a32 - a22 * a31))

    # проверка на вырожденность матрицы
    if abs(det_main) < 1e-12:
        raise ValueError(
            "Определитель матрицы равен нулю! (Matrix determinant is zero!)\n"
            "Проверьте входные данные (Check the input data)\n"
        )


    # вычисляем определители для каждого неизвестного
    det_x = (b1 * (a22 * a33 - a23 * a32) -
             a12 * (b2 * a33 - a23 * b3) +
             a13 * (b2 * a32 - a22 * b3))

    det_y = (a11 * (b2 * a33 - a23 * b3) -
             b1 * (a21 * a33 - a23 * a31) +
             a13 * (a21 * b3 - b2 * a31))

    det_z = (a11 * (a22 * b3 - b2 * a32) -
             a12 * (a21 * b3 - b2 * a31) +
             b1 * (a21 * a32 - a22 * a31))


    # вычисляем неизвестные
    a_coef = det_x / det_main
    b_coef = det_y / det_main
    c_coef = det_z / det_main


    return a_coef, b_coef, c_coef




def calculate_steinhart_hart_coefficients(

    r1, t1,
    r2, t2,
    r3, t3,

    temperature_unit=Converter.CELSIUS
):

    '''
    расчёт коэффициентов A, B и C уравнения Стейнхарта-Харта
    по трём известным точкам
    -------------------------------------------------------------------------------
    calculation of the coefficients A, B, and C of the Steinhart-Hart equation
    using three known points
    '''


    # конвертируем температуры в Кельвины
    t1_k = temperature_to_kelvin(t1, temperature_unit)
    t2_k = temperature_to_kelvin(t2, temperature_unit)
    t3_k = temperature_to_kelvin(t3, temperature_unit)


    # вычисляем обратные температуры
    inv_t1 = 1.0 / t1_k
    inv_t2 = 1.0 / t2_k
    inv_t3 = 1.0 / t3_k


    # вычисляем логарифмы сопротивлений
    ln_r1 = math.log(r1)
    ln_r2 = math.log(r2)
    ln_r3 = math.log(r3)


    # возводим логарифмы в куб
    ln_r1_3 = ln_r1 ** 3
    ln_r2_3 = ln_r2 ** 3
    ln_r3_3 = ln_r3 ** 3


    # формируем матрицу системы линейных уравнений
    # [1, ln(R1), ln(R1)^3]   [A]   [1/T1]
    # [1, ln(R2), ln(R2)^3] * [B] = [1/T2]
    # [1, ln(R3), ln(R3)^3]   [C]   [1/T3]
    matrix = [
        [1.0, ln_r1, ln_r1_3],
        [1.0, ln_r2, ln_r2_3],
        [1.0, ln_r3, ln_r3_3]
    ]

    vector = [inv_t1, inv_t2, inv_t3]


    # решаем систему
    a_coef, b_coef, c_coef = solve_linear_system_3x3(matrix, vector)


    return a_coef, b_coef, c_coef






# ===============================================================================
#                         ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
# ===============================================================================
#                           AUXILIARY FUNCTIONS
# ===============================================================================


def validate_temperature_point(r, t, temperature_unit=Converter.CELSIUS):

    '''
    проверка валидности точки (сопротивление, температура)
    -------------------------------------------------------------------------------
    validation of a point (resistance, temperature)
    '''


    if r <= 0:
        raise ValueError(f"Сопротивление должно быть положительным! (Resistance must be positive!): {r} Ом\n")

    if (temperature_unit == Converter.KELVIN) and (t < 0):
        raise ValueError(f"Температура в Кельвинах не может быть отрицательной! (Temperature in Kelvin cannot be negative!): {t} K\n")

    if (temperature_unit == Converter.CELSIUS) and (t < -273.15):
        raise ValueError(f"Температура ниже абсолютного нуля! (Temperature below absolute zero!): {t} °C\n")


    return True




# ===============================================================================
#                             ПЕЧАТЬ РЕЗУЛЬТАТОВ
# ===============================================================================
#                               PRINT RESULTS
# ===============================================================================


def print_coefficients(

    a_coef, b_coef, c_coef,

    r1, t1,
    r2, t2,
    r3, t3,

    temperature_unit=Converter.CELSIUS
):

    '''
    печать результатов расчёта коэффициентов
    -------------------------------------------------------------------------------
    printing the results of the coefficient calculation
    '''


    temperature_str = {

        Converter.KELVIN:     "*K",
        Converter.CELSIUS:    "*C",
        Converter.FAHRENHEIT: "*F"

    }.get(temperature_unit, "*C")


    print("\n\nВходные данные (Input data):\n")

    print(f"\tТочка 1 (Point 1): R1 = {r1:.2f} Ом, T1 = {t1:.2f} {temperature_str}")
    print(f"\tТочка 2 (Point 2): R2 = {r2:.2f} Ом, T2 = {t2:.2f} {temperature_str}")
    print(f"\tТочка 3 (Point 3): R3 = {r3:.2f} Ом, T3 = {t3:.2f} {temperature_str}")


    print("\n\n\nРезультаты (Results):\n")

    print(f"\tA = {a_coef:.12e}")
    print(f"\tB = {b_coef:.12e}")
    print(f"\tC = {c_coef:.12e}")







# ===============================================================================
#                          ОСНОВНАЯ ФУНКЦИЯ
# ===============================================================================
#                            MAIN FUNCTION
# ===============================================================================


if __name__ == "__main__":

    '''
    основная функция
    -------------------------------------------------------------------------------
    main function
    '''


    print("\n\n\nРАСЧЁТ КОЭФФИЦИЕНТОВ УРАВНЕНИЯ СТЕЙНХАРТА-ХАРТА:")
    print("\nCALCULATION OF THE STEINHART-HART EQUATION COEFFICIENTS:\n\n")


    
    # точка 1 (point 1)
    R1 = 9433.561500
    T1 = 26.339996

    # точка 2 (point 2)
    R2 = 7945.754400
    T2 = 30.329285

    # точка 3 (point 3)
    R3 = 6718.177200
    T3 = 34.321320

    # единицы измерения температуры
    # (units of temperature measurement)
    temperature_unit = Converter.CELSIUS




    try:

        validate_temperature_point(R1, T1, temperature_unit)
        validate_temperature_point(R2, T2, temperature_unit)
        validate_temperature_point(R3, T3, temperature_unit)


        a_coef, b_coef, c_coef = calculate_steinhart_hart_coefficients(

            R1, T1,
            R2, T2,
            R3, T3,

            temperature_unit
        )


        print_coefficients(

            a_coef, b_coef, c_coef,

            R1, T1,
            R2, T2,
            R3, T3,

            temperature_unit
        )

        print("\n\n")



    except ValueError as e:
        print(f"\nОшибка (Error): {e}")

    except Exception as e:
        print(f"\nНепредвиденная ошибка (Unexpected error): {e}")










