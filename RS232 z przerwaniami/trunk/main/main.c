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




int main(void)
{
    volatile uint8_t data;
	
	USART_init(BAUD_8MHZ_9600);
	
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

