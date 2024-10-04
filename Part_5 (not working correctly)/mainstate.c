#include <reg51.h>
#include "LCD.h"
#include "CALCULATOR.h"
#include "TEMP.h"
#include "RTC.h"
#include <string.h>
char scan_key();
void rtc_state();
typedef enum {
	state_calculator,
	state_temperature,
	state_rtc,
}STATE;



STATE current_state = state_calculator;
char key='\0';
void main()
{
	lcd_init();
	DS1302_init();
	DS1302_settime(0x23,0x59,0x50);
	DS1302_setdate(0x31,0x12,0x23);
	while(1)
	{
	   key=scan_key();
		switch(current_state)
		{
			case state_calculator:
				lcd_clear();
			calculator_state();
			if(key=='C')
			{
				current_state= 	state_temperature;
			}
			break;
			
//			case 	state_temperature:
//				lcd_clear();
//			temperature_state();
//			if(key=='C')
//			{
//				current_state=state_rtc;
//			}
//			break;
			
			case state_rtc:
				lcd_clear();
			rtc_state();
			if(key=='C')
			{
				current_state= state_calculator;
			}
			break;
		}
	}
}