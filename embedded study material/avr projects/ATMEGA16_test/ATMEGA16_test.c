#define F_CPU 1000000UL
#include <avr/io.h>
#include<util/delay.h>


int main (void) 
{ 

   DDRC=0xFF;	//used as output pins

   //uint8_t brightness=0;

	//initADC();
	//InitPWM();


PORTC=0b00000000;
   for(;;)  // Loop Forever 
   { 
		PORTC=~PORTC;
		_delay_ms(2000);
   } 

}
