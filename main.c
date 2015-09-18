/* 
 * File:   main.c
 * Author: Nick Sheptock
 * Description: Lab 0
 * Created on September 17, 2015
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

#define ON 0
#define OFF 1

//TODO: Define states of the state machine
typedef enum stateTypeEnum{
    Init, WaitPress, WaitRelease, Increment, Decrement
} stateType;

//TODO: Use volatile variables that change within interrupts
volatile stateType State = Init;

int main() {
    
    int i = 0;
    int LED = 0;
    //This function is necessary to use interrupts. 
    enableInterrupts();
    
    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
    initTimer1();
    
    while(1){
        
        switch(State){
            
            case Init:
                EnableLED(0); //Turns on first LED
                State = WaitPress;
                break;
                
            case WaitPress:
                if(PORTDbits.RD6 == ON){
                    State = WaitRelease;
                    Timer1Activate(1);
                }
                break;
                
            case WaitRelease:
                if(PORTDbits.RD6 == OFF){
                    if(IFS0bits.T1IF == 1){
                        State = Decrement;
                    }
                    else{
                        State = Increment;                        
                    }
                    Timer1Activate(0);
                }
                break;
                
            case Increment:
                EnableLED(3); //Turns off LEDs
                if(LED == 0){
                    LED = 1;
                }
                else if(LED == 1){
                    LED = 2;
                }
                else if(LED == 2){
                    LED = 0;
                }
                EnableLED(LED);
                IFS0bits.T1IF = 0;
                State = WaitPress;
                break;
                
            case Decrement:
                EnableLED(3); //Turns off LEDs
                if(LED == 0){
                    LED = 2;
                }
                else if(LED == 1){
                    LED = 0;
                }
                else if(LED == 2){
                    LED = 1;
                }
                EnableLED(LED);
                IFS0bits.T1IF = 0;
                State = WaitPress;
                break;
                
            default:
                break;
        }
    }
    
    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL3SRS) _T1Interrupt(){
    IFS0bits.T1IF = 0;
}