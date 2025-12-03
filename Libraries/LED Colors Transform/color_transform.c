
#include "color_transform.h"


HSV_t Color_Transform_RGB_To_HSV(RGB_t rgb)
{
	HSV_t hsv;

	uint8_t rgb_min, rgb_max;

	rgb_min = rgb.r < rgb.g ? (rgb.r < rgb.b ? rgb.r : rgb.b) : (rgb.g < rgb.b ? rgb.g : rgb.b);
	rgb_max = rgb.r > rgb.g ? (rgb.r > rgb.b ? rgb.r : rgb.b) : (rgb.g > rgb.b ? rgb.g : rgb.b);

	hsv.v = rgb_max;
	
	if (hsv.v == 0)
	{
		hsv.h = 0;
		hsv.s = 0;
		return hsv;
	}

	hsv.s = 255 * (int32_t)(rgb_max - rgb_min) / hsv.v;
	
	if (hsv.s == 0)
	{
		hsv.h = 0;
		return hsv;
	}

	if (rgb_max == rgb.r)
	{
		hsv.h = 0 + 43 * (rgb.g - rgb.b) / (rgb_max - rgb_min);
	}
	else if (rgb_max == rgb.g)
	{
		hsv.h = 85 + 43 * (rgb.b - rgb.r) / (rgb_max - rgb_min);
	}
	else
	{
		hsv.h = 171 + 43 * (rgb.r - rgb.g) / (rgb_max - rgb_min);
	}

	return hsv;
}


RGB_t Color_Transform_HSV_To_RGB(HSV_t hsv)
{
	RGB_t rgb;
	
	uint16_t region, remainder, p, q, t;
	
	if (hsv.s == 0)
	{
		rgb.r = hsv.v;
		rgb.g = hsv.v;
		rgb.b = hsv.v;
		
		return rgb;
	}
	
	region    =  hsv.h / 43;
	remainder = (hsv.h - (region * 43)) * 6;
	
	p = (hsv.v * (255 -   hsv.s)) >> 8;
	q = (hsv.v * (255 - ((hsv.s * remainder) >> 8))) >> 8;
	t = (hsv.v * (255 - ((hsv.s * (255 - remainder)) >> 8))) >> 8;
	
	switch (region)
	{
		case 0:
		rgb.r = hsv.v;
		rgb.g = t;
		rgb.b = p;
		break;
		
		case 1:
		rgb.r = q;
		rgb.g = hsv.v;
		rgb.b = p;
		break;
		
		case 2:
		rgb.r = p;
		rgb.g = hsv.v;
		rgb.b = t;
		break;
		
		case 3:
		rgb.r = p;
		rgb.g = q;
		rgb.b = hsv.v;
		break;
		
		case 4:
		rgb.r = t;
		rgb.g = p;
		rgb.b = hsv.v;
		break;
		
		case 5:
		default:
		rgb.r = hsv.v;
		rgb.g = p;
		rgb.b = q;
		break;
	}
	
	return rgb;
}


HSV_Float_t Color_Transform_RGB_To_HSV_Float(RGB_t rgb)
{
	HSV_Float_t hsv_f;

	float r = (float)rgb.r / 255.0;
	float g = (float)rgb.g / 255.0;
	float b = (float)rgb.b / 255.0;

	float min, max, delta;

	min = r < g ? r : g;
	min = min < b ? min : b;
	max = r > g ? r : g;
	max = max > b ? max : b;

	hsv_f.v = max;
	delta   = max - min;

	if (delta < 0.00001)
	{
		hsv_f.s = 0;
		hsv_f.h = 0;
		
		return hsv_f;
	}
	
	if (max > 0.0)
	{
		hsv_f.s = delta / max;
	}
	else
	{
		hsv_f.s = 0.0;
		hsv_f.h = 0.0;
		
		return hsv_f;
	}
	
	if (r >= max)
	{
		hsv_f.h = (g - b) / delta;
	}
	else
	{
		if (g >= max)
		{
			hsv_f.h = 2.0 + (b - r) / delta;
		}
		else
		{
			hsv_f.h = 4.0 + (r - g) / delta;
		}
	}

	hsv_f.h *= 60.0;

	if (hsv_f.h < 0.0)
	{
		hsv_f.h += 360.0;
	}
	
	return hsv_f;
}


RGB_t Color_Transform_HSV_Float_To_RGB(HSV_Float_t hsv_f)
{
	RGB_t   rgb;
	
	float   r, g, b;
	float   hh, p, q, t, ff;
	
	int32_t i;

	if (hsv_f.s <= 0.0)
	{
		r = hsv_f.v;
		g = hsv_f.v;
		b = hsv_f.v;

		rgb.r = (uint8_t)(r * 255.0 + 0.5);
		rgb.g = (uint8_t)(g * 255.0 + 0.5);
		rgb.b = (uint8_t)(b * 255.0 + 0.5);
		
		return rgb;
	}

	hh = hsv_f.h;

	if (hh >= 360.0)
	{
		hh = 0.0;
	}

	hh /= 60.0;
	i   = (int32_t)hh;
	ff  = hh - i;

	p = hsv_f.v * (1.0 -  hsv_f.s);
	q = hsv_f.v * (1.0 - (hsv_f.s * ff));
	t = hsv_f.v * (1.0 - (hsv_f.s * (1.0 - ff)));

	switch (i)
	{
		case 0:
		r = hsv_f.v;
		g = t;
		b = p;
		break;
		
		case 1:
		r = q;
		g = hsv_f.v;
		b = p;
		break;
		
		case 2:
		r = p;
		g = hsv_f.v;
		b = t;
		break;
		
		case 3:
		r = p;
		g = q;
		b = hsv_f.v;
		break;
		
		case 4:
		r = t;
		g = p;
		b = hsv_f.v;
		break;
		
		case 5:
		default:
		r = hsv_f.v;
		g = p;
		b = q;
		break;
	}
	
	rgb.r = (uint8_t)(r * 255.0 + 0.5);
	rgb.g = (uint8_t)(g * 255.0 + 0.5);
	rgb.b = (uint8_t)(b * 255.0 + 0.5);
	
	return rgb;
}



