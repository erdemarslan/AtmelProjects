/*
 * BitwiseOperatorleri.c
 *
 * Created: 17.02.2019 18:46:43
 * Author : erdemarslan
 */ 


// Bu da yorum sat�r� bu arada!


#include <avr/io.h>
#define F_CPU 16000000L
#include "util/delay.h"


int main(void)
{
	// 0 input - 1 Output
	//DDRB = 0xFF; // B pinlerinin hepsi 11111111 -> Hepsi ��k�� pini
	//PORTB = 0x00; // B pinlerinlerinin hepsini LOW alal�m. Yaln�z b�yle yap�nca tam olarak low olmuyor!
	// PIN BEL�RLEME YAPALIM BAKALIM OLACAK MI?
	DDRB = (1<<4); // B portunun 3. eleman�n� ��k�� olarak al! Bu pinMode fonksiyonu yerine kullan�l�r. Di�erleri otomatik olarak giri� oldu galiba. denemek laz�m :)
	
    /* Replace with your application code */
    while (1) 
    {
		/*
		0 	0 	0 	0 	0 	0 	0 	0
		0 	0 	0 	0 	0 	1 	0 	0
		0 	0 	0 	0 	0 	1 	0 	0
		
		A�a��daki ifade bu yukar�daki olay olur. OR ile 1 ve 0 lar kar��la�t�r�l�r.
		*/
		PORTB |= (1<<PORTB4);
		//PORTB |= (1<<3); // B Portunun 3. eleman�n� high yap!
		_delay_ms(100);
		
		/*
		0 	0 	0 	0 	0 	1 	0 	0
		1 	1 	1 	1 	1 	0 	1 	1
		0 	0 	0 	0 	0 	0 	0 	0
		
		A�a��daki ifade bu yukar�daki olay olur. V ile 1 ve 0 lar kar��la�t�r�l�r. Tabiki kar��la�t�r�lmadan �nce portlardan al�nan bilgi ters �evrilir.
		*/
		PORTB &= ~(1<<4); // B Portunun 3. eleman�n� low yapal�m!
		_delay_ms(100);
    }
}

