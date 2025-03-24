//******************************************************************************
//   Name: System_Timers.c
//   Author: Rachel E. Williams
//   Date Created: February 22, 2025
//   Last Updated: 3/24/2025
//   Description: This file contains the configuration and initialization of 
//                the Clock System for the MSP430FR5739 board, in addition to 
//                setup for Low-Power Mode(s) and time delays to be used 
//                throughout the entire system 
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//   Primarily built with Code Composer Studio 20.1.0.6
//******************************************************************************  

/* #includes */
#include "msp430.h"
#include "msp430fr5739.h"
#include "msp430fr57xxgeneric.h"
#include "System_Timers.h" 

/* Global Variables */


/* Constant Variables */


void Init_Timers(void){
  Init_TimerA0();                // Required for all other timers for this application 
  //Init_TimerA1();
  //Init_TimerB0(); 
  //Init_TimerB1(); 
  Init_Timer_B2();                // Required for instructor-provided code 
}

void Init_TimerA0(void){
  TA0CTL = TASSEL__SMCLK;        // Configuring clock source: SMCLK
  TA0CTL |= TACLR;               // Clearing TA0 register, clock divider, and count direction
  TA0CTL |= ID__8;               // Configuring input divider: /8 
  TA0CTL |= MC__CONTINOUS;       // Configuring timer mode: Continuous up 
  TA0EX0 |= TAIDEX_7;            // Configuring for additional input divider: /8 
  TA0CTL &= ~TAIE;               // Disabling interrupts 
  TA0CTL &= ~TAIFG;              // Clearing interrupt flag 

  TA0CCR0 = TACCR0_INTERVAL;     // Setting value for CCR0 
  TA0CCTL0 |= CCIE;              // Enabling interrupts for TA0CCTL 
//  TA0CCR1 = TACCR1_INTERVAL;     // Setting value for CCR0 
//  TA0CCTL1 |= CCIE;              // Enabling interrupts for TA0CCTL 
//  TA0CCR2 = TACCR2_INTERVAL;     // Setting value for CCR0 
//  TA0CCTL2 |= CCIE;              // Enabling interrupts for TA0CCTL 
}

/*
void Init_TimerA1(void){

}
*/

/*
void Init_TimerB0(void){

}
*/

/*
void Init_TimerB1(void){

}
*/

void Init_Timer_B2(void){

}
