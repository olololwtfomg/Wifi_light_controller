#include <avr/io.h>
#include <inttypes.h>

#include "spi.h"
#include "bitops.h"

void SPI_MasterInit(void)
{
   //SPCR = 0b01010001;
#if SPI_INTERRUPT_ENABLED==1
   SPCR = (1<<SPIE)|(1<<SPE)|(1<<MSTR);
#else
    SPCR = (1<<SPE)|(1<<MSTR);
#endif
   SPSR = (1<<SPI2X); //DOUBLE SPEED WOOHOO
}

/*
*/
char SPI_RW(uint8_t sentByte)
{
    SPDR = sentByte;
#if SPI_INTERRUPT_ENABLED==0
    char retByte;
    while(!(SPSR&(1<<SPIF)));
    retByte=SPDR;
    return retByte;
#else

#endif
}

void RFM70_CSN(uint8_t state)
{
    if(state==0)
        BitClr(PORTD,(1<<PD3));
    else
        BitSet(PORTD,(1<<PD3));
}

void RFM70_CE(uint8_t state)
{
    if(state==0)
        BitClr(PORTD,(1<<PD4));
    else
        BitSet(PORTD,(1<<PD4));
}

void RFM70_MOSI(uint8_t state)
{
    if(state==0)
        BitClr(PORTB,(1<<PB3));
    else
        BitSet(PORTB,(1<<PB3));
}

void RFM70_SCK(uint8_t state)
{
    if(state==0)
        BitClr(PORTB,(1<<PB5));
    else
        BitSet(PORTB,(1<<PB5));
}

/*
void SPI_MasterTransmit(char cData)
{

   PORTB = 0b00000000;
     SPDR = cData;
     while(SPSR == 0b00000000);
   PORTB = 0b00000100;

}
*/
