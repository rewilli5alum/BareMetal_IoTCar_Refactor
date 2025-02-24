//******************************************************************************
//   Name: System.c
//   Author: Rachel E. Williams
//   Date Created: February 24, 2025
//   Last Updated: 2/24/2025
//   Description: This file contains high-level system directives for the 
//                project
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//******************************************************************************  

/* #includes */
#include "msp430.h"
#include "System.h" 
#include "System_Ports.h"
#include "System_Clocks.h"

/* Global Variables */

/* Constant Variables */

//------------------------------------------------------------------------------
// System Configurations
// Description: Tells the compiler to provide the value in reg as an input to an 
//              inline assembly block.  Even though the block contains no 
//              instructions, the compiler may not optimize it away, and is 
//              told that the value may change and should not be relied upon.
//------------------------------------------------------------------------------

/*
inline void READ_AND_DISCARD(unsigned int reg) __attribute__((always_inline));
void READ_AND_DISCARD(unsigned int reg){
  asm volatile ("" : "=m" (reg) : "r" (reg));
}
*/

//inline void enable_interrupts(void) __attribute__((always_inline));
void enable_interrupts(void){
  __bis_SR_register(GIE);              // enable interrupts
//  asm volatile ("eint \n");
}

/*
inline void disable_interrupts(void) __attribute__((always_inline));
void disable_interrupts(void){
//  asm volatile ("dint \n");
}
*/

void System_InitAll(void){
  // 1. System Resets, Interrupts, Operating Modes 
  // (d)2. Clock System 
  Init_ClockSystem(); 
  // 3. DMA 
  // (d)4. GPIO (Ports)
  Init_AllPorts(); 
  // 5. Timers (WDT, TimerA, TimerB) 
  // 6. ADC10_B 
  // 7. eUSCI - UART Mode 
  // 8. eUSCI - SPI Mode  
}