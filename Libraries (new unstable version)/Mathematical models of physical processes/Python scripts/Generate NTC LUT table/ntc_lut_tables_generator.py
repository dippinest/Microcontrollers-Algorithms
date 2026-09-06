

# ===============================================================================
#
#  Скрипт для генерации LUT-таблиц для NTC терморезистора
#  с использованием уравнения Стейнхарта-Харта
#
#  Генерирует таблицу соответствия ADC -> температура для использования
#  на микроконтроллерах AVR с поддержкой PROGMEM и интерполяции
#
# -------------------------------------------------------------------------------
#
#  Script for generating LUT tables for NTC thermistor
#  using the Steinhart-Hart equation
#
#  Generates a table of ADC -> temperature mapping for use
#  on AVR microcontrollers with PROGMEM and interpolation support
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
class Platform_Type(Enum):

    '''
    класс перечислений типа платформы
    (особый случай - для микроконтроллера AVR, где для работы с постоянной памятью
    необходимо использовать специфические функции для чятения данных из Flash)
    -------------------------------------------------------------------------------
    class of platform type enumeration class
    (a special case for the AVR microcontroller, where specific functions
    must be used to read data from Flash memory)
    '''

    AVR_MCU = auto()
    OTHER   = auto()



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



@unique
class Output_Type(Enum):

    '''
    класс перечислений типов выходных данных
    -------------------------------------------------------------------------------
    output data type enumeration class
    '''

    FLOAT      = auto()
    INT8       = auto()
    INT16_X10  = auto()  # 25.5  *C -> 255
    INT16_X100 = auto()  # 25.55 *C -> 2555






# ===============================================================================
#                      ФУНКЦИИ КОНВЕРТАЦИИ ТЕМПЕРАТУРЫ
# ===============================================================================
#                      TEMPERATURE CONVERSION FUNCTIONS
# ===============================================================================


def convert_kelvin_to_celsius(kelvin_temperature):

    '''
    функция преобразования температуры из градусов Кельвина в градусы Цельсия
    -------------------------------------------------------------------------------
    function for converting temperature from Kelvin to Celsius
    '''


    return kelvin_temperature - 273.15




def convert_kelvin_to_fahrenheit(kelvin_temperature):

    '''
    функция преобразования температуры из градусов Кельвина в градусы Фаренгейта
    -------------------------------------------------------------------------------
    function for converting temperature from Kelvin to Fahrenheit
    '''


    return (kelvin_temperature - 273.15) * (9.0/5.0) + 32.0




def temperature_converter(
    kelvin_temperature,
    converter_type=Converter.KELVIN
):

    '''
    функция универсального конвертера температуры
    -------------------------------------------------------------------------------
    universal temperature converter function
    '''


    if converter_type == Converter.KELVIN:
        return kelvin_temperature

    elif converter_type == Converter.CELSIUS:
        return convert_kelvin_to_celsius(kelvin_temperature)

    elif converter_type == Converter.FAHRENHEIT:
        return convert_kelvin_to_fahrenheit(kelvin_temperature)

    else:
        raise ValueError(f"Неподдерживаемый тип (unsupported type): {converter_type}\n")




def output_type_converter(
    temperature_value,
    output_type=Output_Type.INT8
):

    '''
    функция преобразования различных типов данных температуры
    -------------------------------------------------------------------------------
    function of converting different types of temperature data
    '''


    if output_type == Output_Type.INT8:

        if temperature_value < -128:
            return -128

        elif temperature_value > 127:
            return 127

        return int(temperature_value)


    elif output_type == Output_Type.INT16_X10:

        value = int(temperature_value * 10)

        if value < -32768:
            return -32768

        elif value > 32767:
            return 32767

        return value


    elif output_type == Output_Type.INT16_X100:

        value = int(temperature_value * 100)

        if value < -32768:
            return -32768

        elif value > 32767:
            return 32767

        return value


    elif output_type == Output_Type.FLOAT:
        return temperature_value


    else:
        raise ValueError(f"Неподдерживаемый тип (unsupported type): {output_type}\n")




def get_type_header(output_type=Output_Type.INT8):

    '''
    функция получения текстового заголовка типа массива
    -------------------------------------------------------------------------------
    function of getting a text header of the array type
    '''


    if output_type == Output_Type.FLOAT:
        return "float"

    elif output_type == Output_Type.INT8:
        return "int8_t"

    elif (output_type == Output_Type.INT16_X10) or (output_type == Output_Type.INT16_X100):
        return "int16_t"

    else:
        raise ValueError(f"Неподдерживаемый тип (unsupported type): {output_type}\n")






# ===============================================================================
#                          МАТЕМАТИЧЕСКИЕ МОДЕЛИ
# ===============================================================================
#                           MATHEMATICAL MODELS
# ===============================================================================


def get_ntc_resistance(
    adc_value,
    adc_max_value,
    r_serial_ohm,
    u_ref_voltage,
    u_gen_voltage
):

    '''
    расчёт сопротивления NTC терморезистора
    -------------------------------------------------------------------------------
    calculation of the NTC resistance of the thermistor
    '''


    ntc_voltage = (adc_value / adc_max_value) * u_ref_voltage

    resistance = r_serial_ohm * (ntc_voltage / (u_gen_voltage - ntc_voltage))

    return resistance




def steinhart_hart_ntc_model(
    resistance_ohm,
    a_coef,
    b_coef,
    c_coef
):

    '''
    упрощённая математическая модель Стейнхарта-Харта
    -------------------------------------------------------------------------------
    simplified mathematical model of Steinhart–Hart
    '''


    ln_resistance_ohm = math.log(resistance_ohm)

    temperature = 1.0 / (a_coef + b_coef * ln_resistance_ohm + c_coef * (ln_resistance_ohm ** 3))

    return temperature






# ===============================================================================
#                  ГЕНЕРАТОРЫ LUT-ТАБЛИЦЫ И ФУНКЦИЙ НА ЯЗЫКЕ C
# ===============================================================================
#                LUT TABLE AND FUNCTION GENERATORS IN C LANGUAGE
# ===============================================================================


def generate_lut_table(
    num_of_points,
    converter=Converter.CELSIUS
):

    '''
    функция генератора LUT-таблицы значения температуры
    -------------------------------------------------------------------------------
    function of the LUT table generator for temperature values
    '''


    lut_table = []


    step = ADC_MAX_VALUE / (num_of_points - 1)
    
    for i in range(num_of_points):

        adc_val = int(i * step)

        
        if adc_val == 0:
            adc_val = 1
            

        ntc_resistance = get_ntc_resistance(adc_val, ADC_MAX_VALUE, R_SERIAL_OHM, U_REF_VOLTAGE, U_GEN_VOLTAGE)

        temperature_k  = steinhart_hart_ntc_model(ntc_resistance, A_COEF, B_COEF, C_COEF)

        temperature = temperature_converter(temperature_k, converter)
        

        lut_table.append(temperature)


    
    return lut_table




def print_lut_table_as_c_array(
    lut_table,
    num_points,
    lut_table_name="ntc_lut",
    output_type=Output_Type.FLOAT,
    platform_type=Platform_Type.OTHER
):

    '''
    функция печати сгенерированной LUT-таблицы в виде C-массива
    -------------------------------------------------------------------------------
    function for printing the generated LUT table as a C array
    '''


    converted_lut = [output_type_converter(val, output_type) for val in lut_table]
    

    max_width = 0

    for val in converted_lut:

        if output_type == Output_Type.FLOAT:
            width = len(f"{val:.3f}")

        else:
            width = len(str(val))


        max_width = max(max_width, width)
    

    max_width += 2




    print("\n\n#include <stdint.h>")


    avr_progmem_specificator = ""

    if platform_type == Platform_Type.AVR_MCU:
        print("\n#include <avr/pgmspace.h>\n")

        avr_progmem_specificator = " PROGMEM "



    print(f"\n\nconst {get_type_header(output_type)} {lut_table_name}[{num_points}]{avr_progmem_specificator} =")

    print("{")
    


    for i, val in enumerate(converted_lut):

        if i % 8 == 0:
            print("  ", end="")
        

        if output_type == Output_Type.FLOAT:
            formatted_val = f"{val:.3f}"

        else:
            formatted_val = str(val)
        

        if i == num_points - 1:
            print(f"{formatted_val:>{max_width}}", end="")

        else:
            print(f"{formatted_val:>{max_width}},".ljust(max_width + 1), end="")
        
        if (i + 1) % 8 == 0 or i == num_points - 1:
            print("")
    

    print("};\n\n")




def print_c_function_for_getting_temperature(
    num_points,
    lut_table_name="ntc_lut",
    c_function_name="get_temperature_from_lut_table",
    output_type=Output_Type.FLOAT,
    platform_type=Platform_Type.OTHER
):

    '''
    печать текста C-функции прямого получения температуры из LUT-таблицы
    -------------------------------------------------------------------------------
    printing the text of the C function for directly retrieving temperature
    from the LUT table
    '''


    avr_progmem_read_function = ""

    if platform_type == Platform_Type.AVR_MCU:

        if output_type == Output_Type.FLOAT:
            avr_progmem_read_function = "pgm_read_float"

        elif output_type == Output_Type.INT8:
            avr_progmem_read_function = "(int8_t)pgm_read_byte"

        elif (output_type == Output_Type.INT16_X10) or (output_type == Output_Type.INT16_X100):
            avr_progmem_read_function = "(int16_t)pgm_read_word"

        else:
            raise ValueError(f"Неподдерживаемый тип (unsupported type): {output_type}\n")



    print(f"{get_type_header(output_type)} {c_function_name}(uint16_t adc_value)")
    print(
         "{\n"
        f"\tif (adc_value > {num_points - 1})\n"
         "\t{\n"
        f"\t\treturn {lut_table_name}[{num_points - 1}];\n"
         "\t}\n\n"
         )

    if platform_type == Platform_Type.AVR_MCU:
        print(
        f"\treturn {avr_progmem_read_function}(&{lut_table_name}[adc_value]);\n"
         "};\n\n"
        )

    else:
        print(
        f"\treturn {lut_table_name}[adc_value];\n"
         "};\n\n"
        )




def print_c_function_for_getting_temperature_with_interpolation(
    num_points,
    adc_max_value,
    lut_table_name="ntc_lut",
    c_function_name="get_temperature_from_lut_table_with_interpolation",
    output_type=Output_Type.FLOAT,
    platform_type=Platform_Type.OTHER
):
    """
    печать текста C-функции получения температуры из LUT-таблицы
    с линейной интерполяцией
    -------------------------------------------------------------------------------
    printing the text of the C function for obtaining temperature
    from the LUT table with linear interpolation
    """


    if not ((adc_max_value & (adc_max_value + 1) == 0) and (adc_max_value != 0)):
        raise ValueError(f"Разрядность АЦП должна быть степенью двойки! (the ADC bit depth must be a power of two!)\n")


    step  = (adc_max_value + 1) // num_points
    shift = int(math.log2(adc_max_value + 1)) - int(math.log2(num_points))




    avr_progmem_read_function = ""


    if platform_type == Platform_Type.AVR_MCU:

        if output_type == Output_Type.FLOAT:
            avr_progmem_read_function = "pgm_read_float"

        elif output_type == Output_Type.INT8:
            avr_progmem_read_function = "(int8_t)pgm_read_byte"

        elif (output_type == Output_Type.INT16_X10) or (output_type == Output_Type.INT16_X100):
            avr_progmem_read_function = "(int16_t)pgm_read_word"

        else:
            raise ValueError(f"Неподдерживаемый тип (unsupported type): {output_type}\n")




    type_str = get_type_header(output_type)




    print(f"{type_str} {c_function_name}(uint16_t adc_value)")


    print("{\n"
          f"\tif (adc_value >= {adc_max_value})\n"
          "\t{\n"
          f"\t\treturn {lut_table_name}[{num_points - 1}];\n"
          "\t}\n\n\n"
          
          f"\tconst uint16_t index = adc_value >> {shift};\n\n"
          

          f"\tconst uint16_t frac = adc_value & {step - 1};\n\n"
          )



    if platform_type == Platform_Type.AVR_MCU:

        print(
          f"\tconst {type_str} val1 = {avr_progmem_read_function}(&{lut_table_name}[index]);\n"
          f"\tconst {type_str} val2 = {avr_progmem_read_function}(&{lut_table_name}[index + 1]);\n"
        )

    else:

        print(
          f"\tconst {type_str} val1 = {lut_table_name}[index];\n"
          f"\tconst {type_str} val2 = {lut_table_name}[index + 1];\n"
        )





    if output_type == Output_Type.INT8:
        type_string = "int16_t"

    elif (output_type == Output_Type.INT16_X10) or (output_type == Output_Type.INT16_X100):
        type_string = "int32_t"

    else:
        type_string = "float"



    print(
        "\n"
        f"\treturn val1 + ((({type_string})(val2 - val1)) * frac) / {step};\n"
        "};\n\n"
        )







# ===============================================================================
#                               КОНФИГУРАЦИЯ
# ===============================================================================
#                              CONFIGURATION
# ===============================================================================


'''
коэффициенты A, B и C NTC терморезистора
-------------------------------------------------------------------------------
coefficients A, B, and C of the NTC thermistor
'''
A_COEF = 1.129241e-3
B_COEF = 2.341077e-4
C_COEF = 8.767411e-8


'''
сопротивление постоянного резистора в Омах
-------------------------------------------------------------------------------
resistance of the constant resistor in Ohms
'''
R_SERIAL_OHM  = 99650


'''
напряжение питания делителя
-------------------------------------------------------------------------------
divider supply voltage
'''
U_GEN_VOLTAGE = 5.03


'''
опорное напряжение АЦП
-------------------------------------------------------------------------------
ADC reference voltage
'''
U_REF_VOLTAGE = 5.00


'''
максимальное значение АЦП
-------------------------------------------------------------------------------
maximum ADC value
'''
ADC_MAX_VALUE = (2 ** 10) - 1    # 10 bit ADC = (2^10 - 1)


'''
необходимый размер LUT-таблицы (количество точек)
-------------------------------------------------------------------------------
required size of the LUT table (number of points)
'''
NUM_OF_POINTS = 256






# ===============================================================================
#                               ОСНОВНАЯ ФУНКЦИЯ
# ===============================================================================
#                                 MAIN FUNCTION
# ===============================================================================


if __name__ == "__main__":

    
    # генерация LUT-таблицы
    # -------------------------------------------------------------------------------
    # LUT table generation
    #
    lut_table = generate_lut_table(NUM_OF_POINTS, Converter.CELSIUS)
    


    print(f"\n\n\nСгенерировано точек (generated points): {NUM_OF_POINTS}\n")
    print(f"Скопируйте нижеприведённый код в свой проект (copy this code below into your project):\n\n\n")



    print("// ===============================================================================\n")

    # печать LUT-таблицы
    # -------------------------------------------------------------------------------
    # printing the LUT table
    #
    print_lut_table_as_c_array(

        lut_table, NUM_OF_POINTS,
        "LUT_Table",
        Output_Type.INT16_X10,
        Platform_Type.AVR_MCU
    )


    # печать функции прямого получения температуры
    # -------------------------------------------------------------------------------
    # printing a function to directly get temperature
    #
    print_c_function_for_getting_temperature(

        NUM_OF_POINTS,
        "LUT_Table",
        "Get_Temperature_From_Lut_Table",
        Output_Type.INT16_X10,
        Platform_Type.AVR_MCU
    )


    # печать функции получения температуры с интерполяцией
    # -------------------------------------------------------------------------------
    # printing a function to get temperature with interpolation
    #
    print_c_function_for_getting_temperature_with_interpolation(

        NUM_OF_POINTS,
        ADC_MAX_VALUE,
        "LUT_Table",
        "Get_Temperature_From_Lut_Table_Use_Interpolation",
        Output_Type.INT16_X10,
        Platform_Type.AVR_MCU
    )




    print("\n// ===============================================================================\n\n\n")











