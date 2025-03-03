#ifndef TIMER_H
#define TIMER_H

#define TIMER1 1
#define TIMER2 2

#include <xc.h>

void tmr_setup_period(int timer, int ms);

void tmr_wait_period(int timer);

#endif
