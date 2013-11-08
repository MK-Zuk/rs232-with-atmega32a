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
    volatile uint8_t data;
	
	USART_init(BAUD_8MHZ_9600);
	USART_WriteStrShort(tekst);
	
	while(1)
    {
        //TODO:: Please write your application code 
		_delay_ms(500);
		USART_WriteHexShort(data);
		USART_softsend(' ');
		USART_WriteDec8Short(data);
		USART_softsend(' ');
		data++;
		if(data>111) 
		{
			data=0;
			while (!(USART_softread()=='f'));
		}
		
	}
}

