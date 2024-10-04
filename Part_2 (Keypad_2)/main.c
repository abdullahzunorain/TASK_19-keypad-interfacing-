
/*
Display the pressed key on the LCD and seven segment display.
*/
#include <reg51.h>
#include "LCD.h"
#include "KEYPAD.h"
#include "SEVEN.h"

void main ()
{
	
	 lcd_init();

	while(1)
	{
		lcd_command(0x80);
		lcd_string("ENTER THE KEY");
		lcd_command(0xC0);
	keypad();
	A=1; D=0; C=1;
	keypad1();
		
		
		
	}
}