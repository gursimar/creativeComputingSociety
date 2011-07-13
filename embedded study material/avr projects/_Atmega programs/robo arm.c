/*	simar	20/4/10
	the robot arm works fine forward and reverse regaining its
	origional position.

	now the connection with parallel port of pc is required..

*/


#define F_CPU 12000000UL
#include<avr/io.h>
#include<util/delay.h>

int main()
{
      char i=0,j,k;
	  DDRD=0xFF;
      DDRB=0xFF;
      DDRC=0xFF;
      for(k=0;k<10;k++)
	  {
		// forward
		i=0;
		for(j=0;j<8;j++)	//to create 8 steps
		{
			PORTD=1<<(i);
			_delay_ms(20);
			i++;
			if (i==4) i=0;
		}

		i=0;
		_delay_ms(150);

		for(j=0;j<8;j++)
		{
			PORTC=1<<(i);
			_delay_ms(20);
			i++;
			if (i==4) i=0;
		}

		i=0;

		_delay_ms(150);
		for(j=0;j<8;j++)
		{
			PORTB=2<<(i);
			_delay_ms(20);
			i++;
			if (i==4) i=0;
		}
		
		_delay_ms(150);

		//backward
		i=3;
		
		for(j=0;j<8;j++)
		{
			PORTB=2<<(i); //according to the pind of port b used
			_delay_ms(20);
			if (i==0) i=4;			
			i--;	//this is done intentiolly as a logic

		}
		_delay_ms(150);
		i=3;

		for(j=0;j<8;j++)
		{
			PORTC=1<<(i);
			_delay_ms(20);
			if (i==0) i=4;
			i--;
			
		}

		_delay_ms(150);
		i=3;
		
		for(j=0;j<8;j++)
		{
			PORTD=1<<(i);
			_delay_ms(20);
			if (i==0) i=4;
			i--;
			
		}
		_delay_ms(150);


	  }

}
