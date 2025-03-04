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
    
    while(true) {

        LATA = 0x0001;
        tmr_wait_ms(TIMER2, 20);

        LATA = 0x0000; 
        tmr_wait_ms(TIMER2, 200);
    }

    return 0;
};

