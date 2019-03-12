/*
 * FirstApp.c
 *
 * Created: 17.02.2019 14:24:16
 * Author: Erdem Arslan
 */ 


#include <avr/io.h>


int main(void)
{
	DDRB = 0xFF;
	PORTB = 0x00;
}