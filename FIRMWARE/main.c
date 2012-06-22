
/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <olololwtfomg@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Jaroslav Mucka
 * ----------------------------------------------------------------------------
 */

#include <avr/io.h>
#include "initialization.h"
#include "USART.h"

int main(void)
{
    //initializations

    init_periph();
    init_all();
    debug_send("Welcome to hell!!!\r\n\0");
    while(1)
    ;

    return 0;
}
