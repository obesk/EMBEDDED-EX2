/*
 * File:   timer.c
 * Author: obe
 *
 * Created on March 3, 2025, 11:03 AM
 */

#include <xc.h>
#include "timer.h"

void tmr_setup_period(int timer, int ms) {
	if (ms > 200) {
		return;
	}

	const int clocks = ms / 1000 * 281250;

	switch (timer) {
	case TIMER1:
		TMR1 = 0;
		T1CONbits.TCKPS = 0b11;
		PR1 = clocks;
		IFS0bits.T1IF = 0;
		T1CONbits.TON = 1;
		break;
	case TIMER2:
		TMR2 = 0;
		T2CONbits.TCKPS = 0b11;
		PR2 = clocks;
		IFS0bits.T2IF = 0;
		T2CONbits.TON = 1;
		break;
	default:
		break;
	}
}

void tmr_wait_period(int timer) {
	switch (timer) {
	case TIMER1:
		while (IFS0bits.T1IF == 0) {
			;
		}
		IFS0bits.T1IF = 0;
	case TIMER2:
		while (IFS0bits.T2IF == 0) {
			;
		}
		IFS0bits.T2IF = 0;
	}
}