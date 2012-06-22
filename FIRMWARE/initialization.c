#include <avr/io.h>

#include "spi.h"
#include "rfm70.h"
#include "USART.h"
#include "initialization.h"

void init_periph()
{
    //SPI_MasterInit();
    //rfm70_init();
}

void init_io()
{
    //SPI
    DDRB |= (1<<DDB3)|(1<<DDB4)|(1<<DDB5);
    PORTB |= (1<<PINB4);
    //other pins required for RFM70
    DDRD |= (1<<DDD0)|(1<<DDD3)|(1<<DDD4);
    PORTD |= (1<<PIND1)|(1<<PIND2);
    //for LEDS and temperature sensor
    DDRC |= (1<<DDC3)|(1<<DDC4)|(1<<DDC5);
    PORTC |= (1<<PINC2)|(1<<PINC3)|(1<<PINC4)|(1<<PINC5);
}

void init_all()
{
    init_io();
    init_periph();
    USART_init(UBBR_VALUE);
}

