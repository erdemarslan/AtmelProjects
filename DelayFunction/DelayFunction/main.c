/*
 * DelayFunction.c
 *
 * Created: 17.02.2019 18:03:05
 * Author : erdemarslan
 */ 

#include <avr/io.h>
#define F_CPU 16000000L
#include "util/delay.h"


int main(void)
{
	DDRB = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		PORTB = 0xFF;
		_delay_ms(1000);
		PORTB = 0x00;
		_delay_ms(1000);
    }
}