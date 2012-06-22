#ifndef USART_H_INCLUDED
#define USART_H_INCLUDED

#include <inttypes.h>

#define FOSC 1000000
#define BAUD_RATE 4800
#define UBBR_VALUE FOSC/16/BAUD_RATE-1

void USART_init(uint16_t ubrr);
void debug_send(char* str);

#endif // USART_H_INCLUDED
