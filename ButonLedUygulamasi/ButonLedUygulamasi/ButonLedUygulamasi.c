/*
 * ButonLedUygulamasi.c
 *
 * Created: 17.02.2019 17:08:48
 *  Author: erdemarslan
 */ 

#include <avr/io.h>

int main(void)
{
	DDRD = 0x00;
	DDRB = 0xFF;
    while(1)
    {
        //TODO:: Please write your application code
		PORTB = PIND;
    }
}