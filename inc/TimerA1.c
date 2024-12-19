// TimerA1.c
// Runs on MSP432
// Use Timer A1 in periodic mode to request interrupts at a particular
// period.
// Daniel Valvano
// July 11, 2019
/* This example accompanies the book
   "Embedded Systems: Introduction to Robotics,
   Jonathan W. Valvano, ISBN: 9781074544300, copyright (c) 2019
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/

Simplified BSD License (FreeBSD License)
Copyright (c) 2019, Jonathan Valvano, All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are
those of the authors and should not be interpreted as representing official
policies, either expressed or implied, of the FreeBSD Project.
*/

#include <stdint.h>
#include "msp.h"

#define TIMER_A1_IRQ    	10
#define TIMER_A1_PRIORITY	2

void (*TimerA1Task)(void);   // user function

// ***************** TimerA1_Init ****************
// Activate Timer A1 interrupts to run user task periodically
// Inputs:  task is a pointer to a user function
//          period_2us in units (24/SMCLK), 16 bits
// Outputs: none
// With SMCLK 12 MHz, period has units 2us
void TimerA1_Init(void(*task)(void), uint16_t period_2us){

	TimerA1Task = task;

    // write this as part of Lab 13

	/*
	// halt timer A1
    // bits5-4=00,       stop mode
	TIMER_A1->CTL          // halt Timer A1

    // SMCLK, divide by 4, stop mode, clear, no interrupt
    // bits15-10=XXXXXX, reserved
    // bits9-8=10,       clock source to SMCLK
    // bits7-6=10,       input clock divider /4
    // bits5-4=00,       stop mode
    // bit3=X,           reserved
    // bit2=0,           set this bit to clear
    // bit1=0,           no interrupt on timer
	TIMER_A1->CTL

    // no capture mode, compare mode, enable capture/compare interrupt, clear
    // bits15-14=00,     no capture mode
    // bits13-12=XX,     capture/compare input select
    // bit11=X,          synchronize capture source
    // bit10=X,          synchronized capture/compare input
    // bit9=X,           reserved
    // bit8=0,           compare mode
    // bits7-5=XXX,      output mode
    // bit4=1,           enable capture/compare interrupt on CCIFG
    // bit3=X,           read capture/compare input from here
    // bit2=0,           output this value in output mode 0
    // bit1=X,           capture overflow status
    // bit0=0,           clear capture/compare interrupt pending
	TIMER_A1->CCTL[0]

	// compare match value
    TIMER_A1->CCR[0]

    // configure input clock divider / 6
    TIMER_A1->EX0

    // interrupts enabled in the main program after all devices initialized
    // priority 2
    NVIC->IP[ ]

    // enable interrupt 10 in NVIC
    NVIC->ISER[ ]

    // reset and start Timer A1 in up mode
    // MC = Up mode
    // TACLR = reset
    // bits5-4=01,       up mode
    // bit2=1,           TACLR clear
    TIMER_A1->CTL

    */
}


// ------------TimerA1_Stop------------
// Deactivate the interrupt running a user task periodically.
// Input: none
// Output: none
void TimerA1_Stop(void){
    // write this as part of Lab 13
    /*

    // halt Timer A1 - MC  = stop mode
	TIMER_A1->CTL
	// disable interrupt 10 in NVIC
    NVIC->ICER[ ]

    */
}


void TA1_0_IRQHandler(void){
    // write this as part of Lab 13
    /*
    // acknowledge capture/compare interrupt 0 / CCIFG = no interrupt pending
	TIMER_A1->CCTL[0]

	// execute user task
    (*TimerA1Task)();
    */

}
