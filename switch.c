/* 
 * File:   switch.c
 * Author: Nick Sheptock
 *
 * Created on September 17, 2015
 */

#include <xc.h>

void initSwitch1(){
    TRISDbits.TRISD6 = 1;
    //CNCONDbits.ON = 1;          // Turn on CN device
    CNPUDbits.CNPUD6 = 1;       // Enable Internal Pull-up resistor
}