#include <avr/io.h>
#include <inttypes.h>

void USART_init(uint16_t ubrr)
{
    UBRRH = (uint8_t) (ubrr>>8);
    UBRRL = (uint8_t) ubrr;
    UCSRB = (1<<RXEN)|(1<<TXEN);
    UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

void USART_SEND(char znak)
{
    while(!(UCSRA & (1<<UDRE)));
    UDR=znak;
}

void debug_send(char* str)
{
    uint8_t strPos;
    for(strPos=0;str[strPos]!='\0';strPos++)
    {
        USART_SEND(str[strPos]);
    }
}
