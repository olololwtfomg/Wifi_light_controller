#ifndef TIMERS_H_INCLUDED
#define TIMERS_H_INCLUDED

#define TIMER0_THRESHOLD 1
#define TIMER1_THRESHOLD 50
#define TIMER2_THRESHOLD 5
#define TIMER3_THRESHOLD 20

#define SWTIMERNUM 4

void init_timer1();
void start_timer1();
void reset_timer1();
void SW_timer_handler();

void go_to_sleep();

#endif // TIMERS_H_INCLUDED
