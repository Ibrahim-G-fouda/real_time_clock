/*
 * REAL_TIME_proj.c
 *
 * Created: 23/07/2023 09:51:10 م
 *  Author: handsa
 */ 

#include "std_macros1.h"
#include <avr/io.h>
  #include <avr/interrupt.h>
#include "prog init.h"
volatile unsigned char sec_count =0;
unsigned char minut_count=0;
unsigned char hour_count=0;
unsigned char val, first_digit,second_digit;

int main(void)
{
keypad_init('b');
lcd_init();
sev_seg_pcd_init_h('a');
set_bit(DDRC,0);
set_bit(DDRC,1);
set_bit(DDRC,2);
set_bit(DDRC,3);
set_bit(DDRC,4);
set_bit(DDRC,5);
lcd_send_string("press 1 to");
lcd_move_cursor(2,1);
lcd_send_string("set clock");
timer2_ovf_interrupt_1_sec();

    while(1)
    {
val=keypad_read('b');
if (val!=oo)
{
if (val=='1')
{
lcd_clrscrean();
lcd_send_string("hour--");
lcd_move_cursor(1,5);
dm(500);
do 
{
	first_digit=keypad_read('b');
} while (first_digit==oo);
lcd_send_char(first_digit);
dm(350);
do
{
	second_digit=keypad_read('b');
} while (second_digit==oo);
lcd_send_char(second_digit);
dm(350);
hour_count=((first_digit-48)*10)+(second_digit-48);
lcd_clrscrean();
lcd_send_string("minut --");
lcd_move_cursor(1,7);
do
{
	first_digit=keypad_read('b');
} while (first_digit==oo);
lcd_send_char(first_digit);
dm(350);
do
{
	second_digit=keypad_read('b');
} while (second_digit==oo);
lcd_send_char(second_digit);
dm(350);
minut_count=((first_digit-48)*10)+(second_digit-48);
lcd_clrscrean();
lcd_send_string("second --");
lcd_move_cursor(1,8);
do
{
	first_digit=keypad_read('b');
} while (first_digit==oo);
lcd_send_char(first_digit);
dm(350);
do
{
	second_digit=keypad_read('b');
} while (second_digit==oo);
lcd_send_char(second_digit);
dm(350);
sec_count=((first_digit-48)*10)+(second_digit-48);
lcd_clrscrean();
lcd_send_string("press 1 to");
lcd_move_cursor(2,1);
lcd_send_string("set clock");
}
else
{
lcd_clrscrean();
lcd_send_string("wrong choic!!");
dm(1000);
lcd_clrscrean();	
lcd_send_string("press 1 to");
lcd_move_cursor(2,1);
lcd_send_string("set clock");
}
}
  
   PORTC=0b011111110;
sev_seg_pcd_write_h('a',sec_count%10);
   dm(5);
   PORTC=0b11111101;
sev_seg_pcd_write_h('a',sec_count/10);
   dm(5);
    sev_seg_pcd_write_h('a',minut_count%10);
   PORTC=0b11111011;


   dm(5);
   PORTC=0b11110111;
   sev_seg_pcd_write_h('a',minut_count/10);
   dm(5);
    PORTC=0b11101111;
    sev_seg_pcd_write_h('a',hour_count%10);
    dm(5);
    PORTC=0b11011111;
    sev_seg_pcd_write_h('a',hour_count/10);
    dm(5);
	if (sec_count==60)
	{
	sec_count=0;
	minut_count++;
	}
	if (minut_count==60)
	{
		minut_count=0;
		hour_count++;
	}
	if (hour_count==24)
	{
	hour_count=0;
	
	}
	
	}
}
ISR(TIMER2_OVF_vect)
{
	sec_count++;
}