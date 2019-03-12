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
    // Önce Portlarýmýz giriþ mi çýkýþ mý onu belirleyelim!
	DDRD = 0xFF; // D portunun tamamý çýkýþ olarak tanýmlandý!
	int bekleme = 150; // Bekleme süresi için 150ms belirleyelim!

	// Loop döngümüze girelim!...
    while (1)
    {
		// Önce ledleri sýrayla yakalým. Bunun için for Döngüsü kullanacaðýz!
		for (int i = 0; i < 8; i++)
		{
			PORTD |= _BV(i); // i ile belirlenen ledi yak!
			_delay_ms(bekleme); // bekleme kadar bekle
			//PORTD &= ~_BV(i); // i ile belirtilen ledi söndür!
		}

		// geri dönüþü de yapalým!...
		for (int i = 7; i >= 0; i--)
		{
			//PORTD |= _BV(i);
			_delay_ms(bekleme);
			PORTD &= ~_BV(i);
		}
    }
}

