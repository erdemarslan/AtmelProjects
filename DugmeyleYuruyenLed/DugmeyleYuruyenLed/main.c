/*
 * DugmeyleYuruyenLed.c
 *
 * Created: 13.03.2019 00:15:29
 * Author : erdemarslan
 */ 

#define F_CPU 16000000UL // 16MHz şeklinde işlemci frekansımızı belirtelim.
#include <avr/io.h>
#include "util/delay.h" // delay kütüphanemizi ekleyelim

/*
 * Bu uygulamada PORTD2 ve PORTD3 birer butona atanacak!
 * PORTB0-5 arası ise ledlere bağlanacak!
*/


int main(void)
{
	DDRB = 0xFF; // B portunun tamamını çıkış olarak belirleyelim!

	DDRD &= ~(0<<2) | ~(0<<3); // 2. ve 3. pinleri giriş olarak ayarlıyoruz.
	PORTD |= (1<<2) | (1<<3); // bu pinleri high yaparak girişlerin pull-up olduklarını belirtiyoruz.

	PORTB |= (1<<PORTB); // ilk ledi yakıyoruz. Artık ileri geri komutlarını vereceğiz.

	int led = 0;
	
    /* Replace with your application code */
    while (1) 
    {
		// 2. pindeki düğmeye basılmış ise ileri git!
		if(bit_is_clear(PIND, 2) && led < 5) {
			PORTB <<= 1;
			led++;
			_delay_ms(250);
		}

		if (bit_is_clear(PIND, 3) && led > 0)
		{
			PORTB >>=1;
			led--;
			_delay_ms(250);
		}
    }
}

