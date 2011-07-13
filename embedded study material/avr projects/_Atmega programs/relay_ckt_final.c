#define F_CPU 1000000UL
#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>


char sen_roomside=0; //towards door room
char sen_doorside=0;	//towards room room
int pp=2;

/*
INT0	PD2	pin4	PC4	27_PIN DOOR SIDE
INT1	PD3	pin5	PC3	26_PIN	ROOM SIDE

*/



ISR(INT0_vect)	//door side ((sen1))
{
	if(sen_roomside==1 && sen_doorside==1)	//person is leaving
	{
		PORTB=0b00000000;
	//	_delay_ms(2000);
		pp--;
		sen_roomside=0;
		sen_doorside=0;
	}
	else
	{
	sen_doorside=1;	//set the flag of sensor1 wait for sensor 2
	}

}

ISR(INT1_vect)	//room side ((sen2))
{
	if(sen_roomside==1 && sen_doorside==1)	//person is entering
	{
		//PORTB=0b00000001;
		pp++;
		//_delay_ms(2);
		sen_roomside=0;
		sen_doorside=0;
	}
	else
	{
	sen_roomside=1;	//set the flag of sensor1 wait for sensor 2
	}
	
}


//1/5/10


void main()
{

	DDRD=0x00;	//input port
	DDRB=0xff;	//output port

	MCUCR |=(1<<ISC00) | (0<<ISC01);
	MCUCR |=(1<<ISC10) | (0<<ISC11);

	GICR |= (1<<INT0);
	GICR |= (1<<INT1);
	sei();	//SREG |= (1<<7);


	for(;;)
	{
		PORTB=0B00000000;
		//_delay_ms(2000);
		if( pp<=1 )
		{
			PORTB=0b00000000;
			//_delay_ms(9000);
		}
		
		else
			PORTB=0b00000001;
		
	}
}

