/*
 * File:   newmainXC16.c
 * Author: obe
 *
 * Created on March 3, 2025, 10:38 AM
 */

#include "timer.h"
#include "stdbool.h"
#include "xc.h"

int main(){
    ANSELA = ANSELB = ANSELC = ANSELD = ANSELE = ANSELG = 0x0000;
    TRISA = 0x0000;
    TRISG = 0x0000;

    tmr_setup_period(TIMER1, 200);
    int delay = 200;
    
    bool toggle = true;
 
    while(true) {
        tmr_wait_ms(TIMER2, delay);
        
        if (toggle) {
            LATA = 0x0001;
        } else {
            LATA = 0x0000;
        }
 
        toggle = !toggle;

		LATGbits.LATG9 =tmr_wait_period(TIMER1)
    }

    return 0;
};


