//******************************************************************************
//   Name: System_Timers.c
//   Author: Rachel E. Williams
//   Date Created: February 22, 2025
//   Last Updated: 2/22/2025
//   Description: This file contains the configuration and initialization of 
//                the Clock System for the MSP430FR5739 board, in addition to 
//                setup for Low-Power Mode(s) and time delays to be used 
//                throughout the entire system 
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//******************************************************************************  

/* #includes */
#include "msp430.h"
#include "System_Timers.h" 

/* Global Variables */


/* Constant Variables */


void Init_Timers(void){
  Init_TimerA0(); 
  Init_TimerA1();
  Init_TimerB0(); 
  Init_TimerB1(); 
  Init_TimerB2(); 
}

void Init_TimerA0(void){

}

void Init_TimerA1(void){

}

void Init_TimerB0(void){

}

void Init_TimerB1(void){

}

void Init_TimerB2(void){

}