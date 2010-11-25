#define F_CPU 12000000UL
#include<avr/io.h>
#include<util/delay.h>

#define INPUT 0x00 
#define OUTPUT 0xFF 

int main()
{

	  //Setting up the data direction registers
	  DDRD= OUTPUT;
      DDRB= INPUT;

      while (1)
	  {
	  	if (PINB & (1<<0))
	  	{
	  		PORTD = 0b00000001;	//AC ON
	  	}
		else
		{
			PORTD = 0b00000000;	//AC OFF
		}
		_delay_ms(150);
	  }

}
