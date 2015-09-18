/* 
 * File:   timer.c
 * Author: Nick Sheptock
 *
 * Created on September 17, 2015
 */

#include <xc.h>

void initTimer1(){
    TMR1 = 0; // Clear TMR1
    PR1 = 5000;
    T1CONbits.TCKPS = 3;
    T1CONbits.TCS = 0;
    //IEC0bits.T1IE = 1;// Enable the interrupt
    IFS0bits.T1IF = 0;// Put the flag down
    //IPC1bits.T1IP = 3;// Configure the Interrupt Priority
    T1CONbits.TON = 1;// Turn the timer on
}

void Timer1Activate(int OnOff) {
    switch (OnOff){
        case 0:
            T1CONbits.ON = 0;
            break;
        case 1:
            TMR1 = 0;         //Reinitialize TMR1
            T1CONbits.ON = 1; //Re-enable TMR1
            break;
        default:
            T1CONbits.ON = 0;
            break;
    }
}