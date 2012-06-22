#ifndef SPI_H_INCLUDED
#define SPI_H_INCLUDED

#include <inttypes.h>

void SPI_MasterInit(void);

char SPI_RW(uint8_t byte_to_send);
void RFM70_CSN(uint8_t state);
void RFM70_CE(uint8_t state);
void RFM70_MOSI(uint8_t state);
void RFM70_SCK(uint8_t state);

#endif // SPI_H_INCLUDED
