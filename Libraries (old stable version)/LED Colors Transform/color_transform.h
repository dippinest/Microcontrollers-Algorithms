
// ===============================================================================
//
// Библиотека для преобразования цветовых пространств RGB в HSV и обратно.
//
// Библиотека предназначена для использования в проектах, где требуется
// управление разноцветными светодиодными лентами, рейками и пр.
// (например, для подсветки, в гирляндах и пр.).
//
// Цветовое пространство HSV представлено в двух вариациях:
// 1. с плавующей точкой (компонента h изменяется от 0 до 360,
//    s и v - от 0 до 1.0)
// 2. и в целочисленном исполнении
//    (компоненты h, s и v изменяется от 0 до 255).
//
// -------------------------------------------------------------------------------
//
// Library for converting RGB color spaces to HSV and conversely.
//
// The library is intended for use in projects where management
// of multi-colored LED strips, rails, etc. is required
// (for example, for illumination, in garlands, etc.).
//
// The HSV color space is represented in two variations:
// 1. floating point (component h varies from 0 to 360,
//    s and v - from 0 to 1.0)
// 2. and integer (components h, s and v varies from 0 to 255).
//
// ===============================================================================


#ifndef COLOR_TRANSFORM_H_
#define COLOR_TRANSFORM_H_

#include <stdint.h>


typedef struct
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	
} RGB_t;


typedef struct
{
	uint8_t h;
	uint8_t s;
	uint8_t v;
	
} HSV_t;


typedef struct
{
	float h;
	float s;
	float v;

} HSV_Float_t;


// ===============================================================================


HSV_t Color_Transform_RGB_To_HSV(RGB_t rgb);

RGB_t Color_Transform_HSV_To_RGB(HSV_t hsv);

HSV_Float_t Color_Transform_RGB_To_HSV_Float(RGB_t rgb);

RGB_t Color_Transform_HSV_Float_To_RGB(HSV_Float_t hsv_f);


#endif

