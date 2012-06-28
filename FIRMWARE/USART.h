/*
 to be honest this file includes physical debugging methods like LEDs and others
*/

#ifndef USART_H_INCLUDED
#define USART_H_INCLUDED

#include <avr/io.h>
#include <inttypes.h>

#define FOSC 1000000
#define BAUD_RATE 4800
#define UBBR_VALUE FOSC/16/BAUD_RATE-1

typedef enum
{
    LED1=PINC3,
    LED2=PINC4,
    LED3=PINC5
} eLeds;

typedef enum
{
    OFF,
    ON,
    TOGGLE
} eLedAction;
void USART_init(uint16_t ubrr);
void debug_send(char* str);
void LED_action(uint8_t led,uint8_t action);

#endif // USART_H_INCLUDED
