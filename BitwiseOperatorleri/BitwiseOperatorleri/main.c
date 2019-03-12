/*
 * BitwiseOperatorleri.c
 *
 * Created: 17.02.2019 18:46:43
 * Author : erdemarslan
 */ 


// Bu da yorum satýrý bu arada!


#include <avr/io.h>
#define F_CPU 16000000L
#include "util/delay.h"


int main(void)
{
	// 0 input - 1 Output
	//DDRB = 0xFF; // B pinlerinin hepsi 11111111 -> Hepsi çýkýþ pini
	//PORTB = 0x00; // B pinlerinlerinin hepsini LOW alalým. Yalnýz böyle yapýnca tam olarak low olmuyor!
	// PIN BELÝRLEME YAPALIM BAKALIM OLACAK MI?
	DDRB = (1<<4); // B portunun 3. elemanýný çýkýþ olarak al! Bu pinMode fonksiyonu yerine kullanýlýr. Diðerleri otomatik olarak giriþ oldu galiba. denemek lazým :)
	
    /* Replace with your application code */
    while (1) 
    {
		/*
		0 	0 	0 	0 	0 	0 	0 	0
		0 	0 	0 	0 	0 	1 	0 	0
		0 	0 	0 	0 	0 	1 	0 	0
		
		Aþaðýdaki ifade bu yukarýdaki olay olur. OR ile 1 ve 0 lar karþýlaþtýrýlýr.
		*/
		PORTB |= (1<<PORTB4);
		//PORTB |= (1<<3); // B Portunun 3. elemanýný high yap!
		_delay_ms(100);
		
		/*
		0 	0 	0 	0 	0 	1 	0 	0
		1 	1 	1 	1 	1 	0 	1 	1
		0 	0 	0 	0 	0 	0 	0 	0
		
		Aþaðýdaki ifade bu yukarýdaki olay olur. V ile 1 ve 0 lar karþýlaþtýrýlýr. Tabiki karþýlaþtýrýlmadan önce portlardan alýnan bilgi ters çevrilir.
		*/
		PORTB &= ~(1<<4); // B Portunun 3. elemanýný low yapalým!
		_delay_ms(100);
    }
}

