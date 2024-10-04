#include <reg51.h>
#include "LCD.h"
#include "CALCULATOR.h"
#include <string.h>
sbit r0 =P1^0;
sbit r1 =P1^1;
sbit r2 =P1^2;
sbit r3 =P1^3;
sbit c0 =P1^4;
sbit c1 =P1^5;
sbit c2 =P1^6;
sbit c3 =P1^7;

//char scan_key(void);

int calculator_state(void)
{
	
	
	unsigned int r=0;
	int k2,k1;
	char key, key1;
	unsigned char ch2;
	//lcd_init();
	 lcd_set_cursor(0,0);
	lcd_string("Simplecalculator");
	
	key=scan_key();
	k2=get_num(key);
	lcd_set_cursor(1,0);
	lcd_char(key);
	
	
	ch2=scan_key();
	lcd_set_cursor(1,1);
	lcd_char(ch2);
	
	
	key1=scan_key();
	k1=get_num(key1);
	lcd_set_cursor(1,2);
	lcd_char(key1);
	lcd_set_cursor(1,3);
	lcd_string("=");
	lcd_set_cursor(1,4);
	
	switch(ch2)
	{
		case '+':
			disp_num(k1+k2);
		break;
		case '-':
			disp_num(k2-k1);
		break;
		case '*':
			disp_num(k2*k1);
		break;
		case '/':
			disp_num(k2/k1);
		break;	
	}
   return 0;
	while(scan_key()!=0);
}
	
char scan_key()
{
	char keypressed='\0';
	while(!(keypressed == '0'|| keypressed == '1'|| keypressed == '2'|| keypressed == '3'||
		      keypressed == '4'|| keypressed == '5'|| keypressed == '6'|| keypressed == '7'||
	        keypressed == '8'|| keypressed == '9'|| keypressed == '-'|| keypressed == '*'|| 
          keypressed == '='|| keypressed == '+'|| keypressed == '/'|| keypressed == 'C'	))
{
	    r0=0; r1=1;r2=1;r3=1;
	if(c0==0 && r0==0){keypressed='+';}
	if(c1==0 && r0==0){keypressed='-';}
	if(c2==0 && r0==0){keypressed='*';}
	if(c3==0 && r0==0){keypressed='/';}
		
	    r0=1; r1=0;r2=1;r3=1;
	if(c0==0 && r1==0){keypressed='=';}
	if(c1==0 && r1==0){keypressed='3';}
	if(c2==0 && r1==0){keypressed='6';}
	if(c3==0 && r1==0){keypressed='9';}
	
	    r0=1; r1=1;r2=0;r3=1;
	if(c0==0 && r2==0){keypressed='0';}
	if(c1==0 && r2==0){keypressed='2';}
	if(c2==0 && r2==0){keypressed='5';}
	if(c3==0 && r2==0){keypressed='8';}
		
	    r0=1; r1=1;r2=1;r3=0;
	if(c0==0 && r3==0){keypressed='C';}
	if(c1==0 && r3==0){keypressed='1';}
	if(c2==0 && r3==0){keypressed='4';}
	if(c3==0 && r3==0){keypressed='7';}
}
			delay(500);
  return keypressed;
}
int get_num (char ch)
{
	switch(ch)
	{
		case '0': return 0; break;
		case '1': return 1; break;
		case '2': return 2; break;
		case '3': return 3; break;
		case '4': return 4; break;
		case '5': return 5; break;
		case '6': return 6; break;
		case '7': return 7; break;
		case '8': return 8; break;
		case '9': return 9; break;
	}
	return 0;
}
void disp_num(float num)
{
	unsigned char unitdigit =0;
	unsigned char tenthdigit =0;
	unsigned char decimal =0;
	int j;
	int numb;
	 j=(int)(num*10);
		 numb=(int)num;
	 
	if(numb<0)
	{
		numb=-1*numb;
		lcd_char('-');
	}		
	tenthdigit=(numb/10);
	if(tenthdigit!=0)
	
		lcd_char(tenthdigit+0x30);
	  unitdigit=numb - tenthdigit*10;
	lcd_char(unitdigit+0x30);
	lcd_char('.');
	decimal=(j%10)+0x30;
	lcd_char(decimal);
	delay(2000);
	
	
}

