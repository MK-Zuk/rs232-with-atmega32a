/*
 * CFile1.c
 *
 * Created: 2013-11-08 23:21:39
 *  Author: Marek
 */ 


#include "usart_lib.h"


void USART_init(uint16_t baud)
{
	/* Set baud rate */
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSRB = _BV(RXEN)| _BV(TXEN);
	/* Set frame format: 8data, 2stop bit */
	//UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
	UCSRC = _BV(URSEL) | _BV(UCSZ0) | _BV(UCSZ1);
}

void USART_softsend(uint8_t data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = data;
}

uint8_t USART_softread(void)
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}