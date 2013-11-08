/*
 * main.c
 *
 * Created: 2013-11-08 21:39:54
 *  Author: Marek
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD 51

void USART_init(uint16_t baud);
void USART_softsend(uint8_t data);
uint8_t USART_softread(void);


int main(void)
{
    volatile uint8_t data;
	
	USART_init(BAUD);
	
	while(1)
    {
        //TODO:: Please write your application code 
		_delay_ms(500);
		USART_softsend('0'+data);
		data++;
		if(data>9) 
		{
			data=0;
			while (USART_softread()=='f');
		}
		
	}
}

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