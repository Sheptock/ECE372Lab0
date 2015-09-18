/* 
 * File:   led.c
 * Author: Nick Sheptock
 *
 * Created on September 17, 2015
 */

#include <xc.h>
#include "led.h"


void initLEDs(){
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    LATDbits.LATD0 = 0;
    LATDbits.LATD1 = 0;
    LATDbits.LATD2 = 0;
}

void EnableLED(int LED){
    //TODO: You may choose to write this function
    // as a matter of convenience
    if(LED == 0){
        LATDbits.LATD0 = 1;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 0;
    }
    else if(LED == 1){
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 1;
        LATDbits.LATD2 = 0;        
    }
    else if(LED == 2){
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 1;
    }
    else{
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 1;
    }
}