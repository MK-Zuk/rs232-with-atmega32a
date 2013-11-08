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

void USART_WriteHex(uint8_t num)
{
	uint8_t hi, lo;
	hi=num & 0xF0;
	hi=hi >>4;
	lo=num & 0x0F;
	USART_softsend('0');
	USART_softsend('x');
	if(hi<10)
	{USART_softsend(hi+'0');
	}else USART_softsend(hi-10+'A');
	if(lo<10)
	{USART_softsend(lo+'0');
	}else USART_softsend(lo-10+'A');
}

void USART_WriteHexShort(uint8_t num)
{
	uint8_t hi, lo;
	hi=num & 0xF0;
	hi=hi >>4;
	lo=num & 0x0F;
	USART_softsend('x');
	if(hi<10)
	{USART_softsend(hi+'0');
	}else USART_softsend(hi-10+'A');
	if(lo<10)
	{USART_softsend(lo+'0');
	}else USART_softsend(lo-10+'A');
}

void USART_WriteDec8(uint8_t num)
{
	uint8_t sto,dzies,jedn;
	jedn = num % 10;
	num = num/10;
	dzies = num%10;
	sto = num/10;
	USART_softsend(sto+'0');
	USART_softsend(dzies+'0');
	USART_softsend(jedn+'0');
}

void USART_WriteDec8Short(uint8_t num)
{
	uint8_t sto,dzies,jedn;
	jedn = num % 10;
	num = num/10;
	dzies = num%10;
	sto = num/10;
	if(sto>0) USART_softsend(sto+'0');
	if(sto!=0 || dzies>0) USART_softsend(dzies+'0');
	USART_softsend(jedn+'0');
}

void USART_WriteDec16(uint16_t num)
{
	uint16_t temp[5];
	uint8_t i;
	for (i=0; i<5;i++)
	{
		temp[i] = num % 10;
		num = num/10;
	}
	
	for (i=0; i<5;i++)
	{
		USART_softsend(temp[4-i]+'0');
	}
}