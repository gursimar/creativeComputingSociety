#define F_CPU 12000000
#include <avr/io.h>
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

int main (void)
	{
	char ReceivedByte;
	// Turn on the transmission and reception circuitry:
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	// Use 8-bit character sizes:
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	// Load lower 8-bits of the baud rate value into the low byte
	// of the UBRR register:
	UBRRL = BAUD_PRESCALE;
	// Load upper 8-bits of the baud rate value into the high byte
	// of the UBRR register:
	UBRRH = (BAUD_PRESCALE >> 8);
	for (;;) // Loop forever
	{
		// Do nothing until data have been recieved and is ready
		// to be read from the UDR register:
		while ((UCSRA & (1 << RXC)) == 0) {};
		// Fetch the recieved byte value into the variable
		// called "ByteReceived":
		ReceivedByte = UDR;
		// Do nothing until UDR is ready for more data to be
		// written to it:
		while ((UCSRA & (1 << UDRE)) == 0) {};
		// Echo back the received byte back to the computer:
		UDR = ReceivedByte;
	}
}
