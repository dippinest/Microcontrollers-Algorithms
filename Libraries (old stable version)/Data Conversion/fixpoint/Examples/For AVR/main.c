
#include <util/delay.h>

#include "adc.h"
#include "i2c.h"
#include "hd44780_i2c.h"

#include "fixpoint.h"

static char str_buf[16];

int main(void)
{
	ADC_Initialize(0, ADC_PRESCALER_128, ADC_VREF_SOURCE_EXTERNAL_AVCC, true);
	
	// maximum value of the ADC voltage multiplied by 100 (to shift the decimal point to the end to the right)
	const int32_t FIXPOINT_MAX_VOLTAGE = 481; // (4.81 * 100)
	
	I2C_Initialize(100000);
	
	FIXPoint_Set_Number_Of_Decimal_Places(2); // fixing a point at position 2
	FIXPoint_Set_String_Buffer(str_buf);
	
	HD44780_I2C_t display = HD44780_I2C_Create_Object(HD44780_I2C_PCF8574_DEV_ADDR_A2T_A1T_A0T, true);
	HD44780_I2C_Set_Target_Object(&display);
	
	HD44780_I2C_Set_Cursor_Pos(0, 0); HD44780_I2C_Print_String("Voltage in ADC0:");
	HD44780_I2C_Set_Cursor_Pos(2, 0); HD44780_I2C_Print_String("Voltage =");
	
	while (1)
	{
		// working with fixed-type numbers
		int32_t FIXPOINT_voltage = (((FIXPOINT_MAX_VOLTAGE * 10000) / 1023) * ADC_Get_Value_10bit()) / 10000;
		
		HD44780_I2C_Clear_String_By_Pos(2, 10, 19); HD44780_I2C_Set_Cursor_Pos(2, 10);
		HD44780_I2C_Print_String(FIXPoint_Int32FP_To_String(FIXPOINT_voltage, 1, 2));
		
		_delay_ms(200);
	}
}




