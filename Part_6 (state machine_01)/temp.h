#ifndef TEMP_H
#define TEMP_H


void ow_reset (void);
unsigned char read_bytess (void);
void write_bytess (char);
void delay_18B20(unsigned int);
void read_temperature(void);
void hex2lcd (unsigned char hex);
void temp_serialdata_pc (void);

// seven segment display
void display_num7_seg (unsigned char);
void values_on_ssd (void);


#endif