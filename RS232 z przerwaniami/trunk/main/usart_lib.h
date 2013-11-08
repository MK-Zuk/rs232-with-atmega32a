/*
 * usart_lib.h
 *
 * Created: 2013-11-08 23:20:19
 *  Author: Marek
 */ 


#ifndef USART_LIB_H_
#define USART_LIB_H_

#include <avr/interrupt.h>

#define BAUD_8MHZ_9600 51

void USART_init(uint16_t baud);
void USART_softsend(uint8_t data);
uint8_t USART_softread(void);



#endif /* USART_LIB_H_ */