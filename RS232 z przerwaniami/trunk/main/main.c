/*
 * main.c
 *
 * Created: 2013-11-08 21:39:54
 *  Author: Marek
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "usart_lib.h"

 char tekst[] = {"Jakis tekst startowy "};


int main(void)
{
    volatile uint8_t data=0;
	uint8_t bufor[BUFFER_SIZE];
	
	USART_initInt(BAUD_8MHZ_9600);
	USART_WriteStrShort(tekst);
	sei();
	while(1)
    {
        //TODO:: Please write your application code 
		_delay_ms(500);
		bufor[0]=0x0A;
		bufor[1]=0x00;
		bufor[2]=data;
		bufor[3]=0x00;
		bufor[4]=data++;
		bufor[5]=0x0A;
		USART_sendInt(bufor);
		
		
		
	}
}

