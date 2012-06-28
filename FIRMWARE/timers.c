#include "timers.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include <avr/sleep.h>
#include "bitops.h"
#include "USART.h"
#include "therm_ds18b20.h"

uint16_t SWtimerFlags=0;

uint16_t SWtimers[16];

void init_timer1()
{
    TCNT1=0x0000;
    OCR1A=50000; //50 ms timer wakeup
    TCCR1B=(1<<WGM12);
    TIMSK=(1<<OCIE1A); //enable output compare interrupt
}

void start_timer1()
{
    TCCR1B=(1<<WGM12)|(1<<CS10);
}

void stop_timer1()
{
    TCCR1B=(1<<WGM12);
}

void reset_timer1()
{
    TCNT1=0;
}

//timer 1 OUTPUT COMPARE HANDLING

ISR(TIMER1_COMPA_vect)
{
    uint8_t timnum,threshold=1;
    //cli();
    for(timnum=0;timnum<SWTIMERNUM;timnum++)
    {
        SWtimers[timnum]++;
        switch (timnum)
        {
            case 0 : threshold=TIMER0_THRESHOLD; break;
            case 1 : threshold=TIMER1_THRESHOLD; break;
            case 2 : threshold=TIMER2_THRESHOLD; break;
            case 3 : threshold=TIMER3_THRESHOLD; break;
        }
        if(SWtimers[timnum]>=threshold)
        {
            BitSet(SWtimerFlags,BitMsk(timnum));
            SWtimers[timnum]=0;
        }
    }
    //sei();
}

void SW_timer_handler()
{
    char buffer[20];
    uint8_t timnum;
    for(timnum=0;timnum<SWTIMERNUM;timnum++)
    {
        if(BitTst(SWtimerFlags,BitMsk(timnum)))
        {
            switch (timnum)
            {
                case 0 :
                    LED_action(LED1,TOGGLE);
                    break;
                case 1 :
                    therm_read_temperature(buffer);
                    debug_send(buffer);
                    break;
                case 2 :
                    LED_action(LED2,TOGGLE);
                    break;
                case 3 :
                   LED_action(LED3,TOGGLE);
                    break;
            }

            BitClr(SWtimerFlags,BitMsk(timnum));
        }
    }
    go_to_sleep();
}

void go_to_sleep()
{
    cli();
    sleep_enable();
    //sleep_bod_disable();
    sei();
    sleep_cpu();
    sleep_disable();
    sei();
}
