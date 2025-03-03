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
    bool toggle = true;
    TRISA = 0x0000;

    tmr_setup_period(TIMER1, 200);

    
    unsigned long i = 0;
    while(true) {
        if (toggle) {
            LATA = 0x0001;
        } else {
            LATA = 0x0000;
        }
        
        if (i % 10 == 0) {
            toggle = !toggle;
        }
        
        tmr_wait_period(TIMER1);
        ++i;

    }

    return 0;
};

