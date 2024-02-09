/*
 * timer2_ovflow.c
 *
 * Created: 23/07/2023 11:27:09 م
 *  Author: handsa
 */ 
#include "std_macros1.h"
#include <avr/io.h>
#include <avr/interrupt.h>
void timer2_ovf_interrupt_1_sec(void)
{
	set_bit(ASSR,AS2);//clk sellect of prescaller from TOSC1
	set_bit(TCCR2,CS20);
set_bit(TCCR2,CS22);
sei();
set_bit(TIMSK,TOIE2);//enable overflow of timer 2 interrupt

}