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

void USART_WriteHex(uint8_t num);
void USART_WriteHexShort(uint8_t num);
void USART_WriteDec8(uint8_t num);
void USART_WriteDec8Short(uint8_t num);
void USART_WriteDec16(uint16_t num);

void USART_WriteStr(char *string, uint8_t lenght);
void USART_WriteStrShort(char *string);

#endif /* USART_LIB_H_ */