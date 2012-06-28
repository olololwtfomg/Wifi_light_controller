
/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <olololwtfomg@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Jaroslav Mucka
 * ----------------------------------------------------------------------------
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "initialization.h"
#include "USART.h"
#include "timers.h"


int main(void)
{
    //initializations
    init_all();
    debug_send("Welcome to hell!!!\r\n\0");
    sei();
    start_timer1();
    //LED_action(LED2,ON);
    while(1)
    {
        SW_timer_handler();
    }
    return 0;
}
