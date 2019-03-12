/*
 * KaraSimsek.c
 *
 * Created: 12.03.2019 23:48:02
 * Author : erdemarslan
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "util/delay.h"


int main(void)
{
    // �nce Portlar�m�z giri� mi ��k�� m� onu belirleyelim!
	DDRD = 0xFF; // D portunun tamam� ��k�� olarak tan�mland�!
	int bekleme = 150; // Bekleme s�resi i�in 150ms belirleyelim!

	// Loop d�ng�m�ze girelim!...
    while (1)
    {
		// �nce ledleri s�rayla yakal�m. Bunun i�in for D�ng�s� kullanaca��z!
		for (int i = 0; i < 8; i++)
		{
			PORTD |= _BV(i); // i ile belirlenen ledi yak!
			_delay_ms(bekleme); // bekleme kadar bekle
			//PORTD &= ~_BV(i); // i ile belirtilen ledi s�nd�r!
		}

		// geri d�n��� de yapal�m!...
		for (int i = 7; i >= 0; i--)
		{
			//PORTD |= _BV(i);
			_delay_ms(bekleme);
			PORTD &= ~_BV(i);
		}
    }
}

