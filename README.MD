


# Microcontrollers Algorhitms
___

#### Набор кросс-платформенных библиотек различных алгоритмов, оптимизированных под малые ресурсы микроконтроллеров и других компьютерных систем.

___

#### A set of cross-platform libraries of various algorithms optimized for small resources of microcontrollers and other computer systems.

___

<img src="/resources/lib_logo.png" alt="Algorithm logo"/>

___

#### Среди них:

- Алгоритмы работы с числовыми данными и преобразования чисел различных типов

   - [Функции преобразования целых чисел в ASCII строки](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/itoa)

   - [Функции преобразования ASCII строки в целые числа](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/atoi)

   - [Функции преобразования чисел с плавающей точкой в ASCII строки](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/ftoa)

   - [Функции преобразования ASCII строки в числа с плавающей точкой](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/atof)

   - [Функции преобразования целых чисел в ASCII строку двоичного представления](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/itobina)

   - [Функции преобразования целых чисел в ASCII строку шестнадцетиричного представления](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/itohexa)

   - [Функции преобразования целых чисел в двоично-десятичное представление и обратно](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/bcd)

   - [Функции преобразования данных по стандартам Base64, Base32, Base16, Base8, Base4 и Base2](https://github.com/dippinest/Microcontrollers-Algorithms/tree/main/Libraries/Data%20Conversion/base%20coding%20standards)

   - [Функции преобразования чисел в код Грея и обратно](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/grayscode)

   - [Функции работы с числами с фиксированной точкой](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/fixpoint)

   - [Функции математического преобразования чисел (расширяющие стандартную библиотеку math.h)](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/mathx)

   - [Функции работы с C-строками (расширяющие стандартную библиотеку string.h)](https://github.com/dippinest/Microcontrollers-Algorithms/tree/main/Libraries/Data%20Conversion/strx)

   - [Функции конвертирования различных физических величин](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/valconvert)


- Алгоритмы генераторов псевдослучайных чисел (ГПСЧ)

   - [Функции для облегчения работы со стандартной функцией rand()](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/PRNG%20Algorithms/random)

   - [Лёгкий и быстрый алгоритм ГПСЧ](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/PRNG%20Algorithms/fast%20random)

   - [Библиотека генератора псевдослучайных чисел на основе изменяемого массива (MAPRNG - Mutable Array Pseudo-Random Number Generator)](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/PRNG%20Algorithms/MAPRNG)

   - [Библиотека ГПСЧ из класса Xorshift генераторов с длиной регистра 128 бит](https://github.com/dippinest/Microcontrollers-Algorithms/tree/main/Libraries/PRNG%20Algorithms/XOR128LFSR)


- Криптографические алгоритмы:

   - [Алгоритм стандарта ГОСТ 28147-89](https://github.com/dippinest/Microcontrollers-Algorithms/tree/main/Libraries/Cryptography/GOST%2028147-89) 

   - [Алгоритмы семейства TEA (TEA, XTEA, XTEA1, XTEA2, XTEA3, RTEA, Raiden)](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Cryptography/TEA%20Series)

   - [Стандартный и модифицированный алгоритм Виженера](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Cryptography/Vigenere)


- Алгоритмы цифровой фильтрации данных ([ссылка](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Digital%20Filters))


- Алгоритмы преобразования цветового пространства RGB в HSV и обратно (для LED источников) ([ссылка](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/LED%20Colors%20Transform))


- Алгоритмы CRT коррекции цвета, излучаемый светодиодными источниками ([ссылка](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/LED%20Gamma%20Correction))


- Алгоритмы вычисления хеш-функций ([ссылка](https://github.com/dippinest/Microcontrollers-Algorithms/tree/main/Libraries/Hash%20Function))


- Алгоритмы вычисления контрольной суммы (CRC) ([ссылка](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/CRC%20Calculation))


- Реализация алгоритма расчета температуры с помощью NTC терморезистора ([ссылка](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/NTC%20Thermometer))


___

##### В качестве примеров алгоритмов приведены реализации тестовых программ для микроконтроллеров семейства AVR (компилятор avr-gcc).

___
___
___

#### Among them:

- Algorithms for working with numeric data and converting numbers of various types

   - [Functions for converting integers to ASCII string](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/itoa )

   - [ASCII string conversion functions to integers](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/atoi )

   - [Functions for converting floating-point numbers to ASCII string](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/ftoa )

   - [ASCII string conversion functions to floating point numbers](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/atof )

   - [Functions for converting integers to ASCII string binary representation](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/itobina)

   - [Functions for converting integers to an ASCII hexadecimal string representation](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/itohexa)

   - [Functions for converting integers to binary-decimal representation and vice versa](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/bcd )

   - [Functions for data conversion according to Base64, Base32, Base16, Base8, Base4 and Base2 standards](https://github.com/dippinest/Microcontrollers-Algorithms/tree/main/Libraries/Data%20Conversion/base%20coding%20standards)

   - [Functions for converting numbers to Gray's code and vice versa](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/grayscode)

   - [Functions for working with fixed-point numbers](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/fixpoint )

   - [Mathematical number conversion functions (extending the standard math.h library)](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/mathx )

   - [Functions for working with C strings (extending the standard string.h library)](https://github.com/dippinest/Microcontrollers-Algorithms/tree/main/Libraries/Data%20Conversion/strx )

   - [Various physical conversion functions](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Data%20Conversion/valconvert)


- Algorithms of pseudorandom number generators (RNG)

   - [Functions to make it easier to work with the standard rand() function](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/PRNG%20Algorithms/random )

   - [Easy and fast RNG algorithm](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/PRNG%20Algorithms/fast%20random)

   - [A library for a pseudo-random number generator based on a mutable array (MAPRNG - Mutable Array Pseudo-Random Number Generator)](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/PRNG%20Algorithms/MAPRNG)

   - [A library of RNGs from the Xorshift class of generators with a register length of 128 bits](https://github.com/dippinest/Microcontrollers-Algorithms/tree/main/Libraries/PRNG%20Algorithms/XOR128LFSR)


- Cryptographic algorithms:

   - [Algorithm of the USSR GOST 28147-89 standard](https://github.com/dippinest/Microcontrollers-Algorithms/tree/main/Libraries/Cryptography/GOST%2028147-89)

   - [TEA family algorithms (TEA, XTEA, XTEA1, XTEA2, XTEA3, RTEA, Raiden)](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Cryptography/TEA%20Series )

   - [Standard and modified Vigener algorithm](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Cryptography/Vigenere )


- Algorithms for digital data filtering ([link](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/Digital%20Filters ))


- Algorithms for converting RGB color space to HSV and vice versa (for LED sources) ([link](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/LED%20Colors%20Transform ))


- CRT algorithms for correcting the color emitted by LED sources ([link](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/LED%20Gamma%20Correction ))


- Algorithms for calculating hash functions ([link](https://github.com/dippinest/Microcontrollers-Algorithms/tree/main/Libraries/Hash%20Function))


- Checksum Calculation Algorithms (CRC) ([link](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/CRC%20Calculation ))


- Implementation of the temperature calculation algorithm using an NTC thermistor ([link](https://github.com/dippinest/MCU-Algorithms/tree/main/Libraries/NTC%20Thermometer ))


___

##### The implementation of test programs for AVR family microcontrollers (avr-gcc compiler) is given as examples of algorithms.




























