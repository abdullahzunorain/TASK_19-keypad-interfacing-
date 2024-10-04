#include <reg51.h>
#include "TEMP.h"
#include "LCD.h"
#include <string.h>


sbit A= P2^2;
sbit D= P2^3;
sbit C= P2^4;

unsigned int index=0;
unsigned char temp_lsb=0; temp_msb=0;
unsigned char unit, ten, hundred, intpart, decpart;
char temp_f;
unsigned char temp_c;
sbit DQ=P3^7;
sbit buzzer_pin=P1^5;

//void temp_serialdata_pc (void)
//{
//	SBUF=hundred;
//		while(TI==0);
//			TI=0;
//		delay(100);
//		
//			SBUF=ten;
//		while(TI==0);                     //  tempdata send to pc
//			TI=0;
//		delay(100);
//		
//			SBUF=unit;
//		while(TI==0);
//			TI=0;
//		delay(100);
//		
//	
//	SBUF='\n';
//		while(TI==0);
//			TI=0;
//		delay(100);
//}	




void ow_reset (void)
{
	DQ=1;
	delay_18B20(8);
	DQ=0;
	delay_18B20(65);
	DQ=1;
	delay_18B20(20);	
}
void delay_18B20 (unsigned int ud)
{
	while(ud--);
}
unsigned char read_bytess (void)
{
	unsigned char i=0;
	unsigned char dat=0;
	for(i=8; i>0; i--)
	{
		DQ=0;
		dat>>=1;
		DQ=1;
		if(DQ)
		
			dat |= 0x80;
			delay_18B20(4);
		
	}
	return(dat);
}
void write_bytess (char dat)
{
	unsigned char i=0;
	for(i=8; i>0; i--)
	{
		DQ=0;
		DQ=dat&0x01;
		delay_18B20(5);
		DQ=1;
		dat>>=1;
	
	}
}
void read_temperature(void)
{
	ow_reset();
	write_bytess(0xCC); // skip rom
	write_bytess(0x44); //start conversion measure temp and convert into digital
	delay_18B20(10);
	ow_reset();
	write_bytess(0xCC); // skip rom
	write_bytess(0xBE);// read scratchpad memory
	delay_18B20(10);
	
	temp_msb=read_bytess();
	temp_lsb=read_bytess();
	
	temp_c=((temp_lsb*256+temp_msb)>>4);
	temp_f=(((int)temp_c)*9)/5+32;
}

void hex2lcd (unsigned char z)
{
	hundred=(z/100)+0x30;
	ten=(z%100/10)+0x30;
	unit=(z%10)+0x30;
	intpart=(int)z;
	decpart=(z-intpart)+0x30;
	
	lcd_char(hundred);
	lcd_char(ten);
	lcd_char(unit);
	lcd_string(".");
	lcd_char(decpart);
}



//void temperature_state()
//{
//		lcd_command (0xC0);
//		read_temperature();
//		hex2lcd(temp_c);
//		lcd_string("c");
//	hex2lcd(temp_f);
//		lcd_string("f");
//}








