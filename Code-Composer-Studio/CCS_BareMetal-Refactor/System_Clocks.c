//******************************************************************************
//   Name: System_Clocks.c
//   Author: Rachel E. Williams
//   Date Created: February 22, 2025
//   Last Updated: 3/31/2025
//   Description: This file contains the configuration and initialization of 
//                the Clock System for the MSP430FR5739 board, in addition to 
//                setup for Low-Power Mode(s) and time delays to be used 
//                throughout the entire system 
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//   Primarily built with Code Composer Studio 20.1.0.6
//******************************************************************************  

/* #includes */
#include "msp430.h"
#include "System_Clocks.h" 

/* Global Variables */


/* Constant Variables */

 
void Init_ClockSystem(){
  // Disabling WatchDog Timer A 
  WDTCTL = WDTPW | WDTHOLD; 
  
  /* Clock System Control Register 0: Unlock registers with CSKEY */
  CSCTL0 = CSKEY;  
  
  /* Clock System Control Register 1: DCO range and clock frequency selection */
  CSCTL1 = CLEAR_REGISTER;        // Clear register 
  CSCTL1 &= ~DCORSEL;             // Reset DCO Range (low-speed device) 
  //CSCTL1 |= DCOFSEL_0;            // DCOFSEL 0 -> set DCO frequency to 5.33MHz 
  //CSCTL1 |= DCOFSEL_1;            // DCOFSEL 1 -> set DCO frequency to 6.67MHz 
  //CSCTL1 |= DCOFSEL_2;            // DCOFSEL 2 -> set DCO frequency to 5.33MHz
  CSCTL1 |= DCOFSEL_3;            // DCOFSEL 3 -> set DCO frequency to 8MHz 
  
  /* Clock System Control Register 2: ACLK, SMCLK, MCLK clock source */
  CSCTL2 = CLEAR_REGISTER;       // Clear register 
  //CSCTL2 |= SELA__XT1CLK;        // ACLK source set to XT1 
  CSCTL2 |= SELA__VLOCLK;        // ACLK source set to VLO
  //CSCTL2 |= SELA__DCOCLK;        // ACLK source set to DCO
  //CSCTL2 |= SELA__XT2CLK;        // ACLK source set to XT2 
  
  //CSCTL2 |= SELS__XT1CLK;        // SMCLK source set to XT1 
  //CSCTL2 |= SELS__VLOCLK;        // SMCLK source set to VLO 
  CSCTL2 |= SELS__DCOCLK;        // SMCLK source set to DCO 
  //CSCTL2 |= SELS__XT2CLK;        // SMCLK source set to XT2 
  
  //CSCTL2 |= SELM__XT1CLK;        // MCLK source set to XT1
  //CSCTL2 |= SELM__VLOCLK;        // MCLK source set to VLO 
  CSCTL2 |= SELM__DCOCLK;        // MCLK source set to DCO 
  //CSCTL2 |= SELM__XT2CLK;        // MCLK source set to XT2
  
  /* Clock System Control Register 3: ACLK, SMCLK, MCLK clock source dividers */
  CSCTL3 = CLEAR_REGISTER;       // Clear register 
  CSCTL3 |= DIVA__1;             // ACLK source divider f(ACLK)/1 
  //CSCTL3 |= DIVA__2;             // ACLK source divider f(ACLK)/2 
  //CSCTL3 |= DIVA__4;             // ACLK source divider f(ACLK)/4 
  //CSCTL3 |= DIVA__8;             // ACLK source divider f(ACLK)/8 
  //CSCTL3 |= DIVA__16;            // ACLK source divider f(ACLK)/16 
  //CSCTL3 |= DIVA__32;            // ACLK source divider f(ACLK)/32 
  
  CSCTL3 |= DIVS__1;             // SMCLK source divider f(SMCLK)/1 
  //CSCTL3 |= DIVS__2;             // SMCLK source divider f(SMCLK)/2 
  //CSCTL3 |= DIVS__4;             // SMCLK source divider f(SMCLK)/4 
  //CSCTL3 |= DIVS__8;             // SMCLK source divider f(SMCLK)/8 
  //CSCTL3 |= DIVS__16;            // SMCLK source divider f(SMCLK)/16 
  //CSCTL3 |= DIVS__32;            // SMCLK source divider f(SMCLK)/32 
  
  CSCTL3 |= DIVM__1;             // MCLK source divider f(MCLK)/1 
  //CSCTL3 |= DIVM__2;             // MCLK source divider f(MCLK)/2 
  //CSCTL3 |= DIVM__4;             // MCLK source divider f(MCLK)/4 
  //CSCTL3 |= DIVM__8;             // MCLK source divider f(MCLK)/8 
  //CSCTL3 |= DIVM__16;            // MCLK source divider f(MCLK)/16 
  //CSCTL3 |= DIVM__32;            // MCLK source divider f(MCLK)/32 
  
  /* Clock System Control Register 4: XT2 & XT1 oscillator configuration */
  CSCTL4 = CLEAR_REGISTER;      // Clear register 
  CSCTL4 &= ~XT2DRIVE_0;        // Setting XT2 to lowest current consumption 
  CSCTL4 &= ~XT2BYPASS;         // XT2 sourced from external crystal
  CSCTL4 |= XT2OFF;             // Disable XT2 oscillator 
  CSCTL4 &= ~XT1DRIVE_0;        // Setting XT1 to lowest current consumption 
  CSCTL4 &= ~XTS;               // Setting XT1 mode to low-frequency mode 
  CSCTL4 &= ~XT1BYPASS;         // XT1 sourced from external crystal 
  CSCTL4 &= ~SMCLKOFF;          // SMCLK is turned on 
  CSCTL4 |= XT1OFF;             // Disable XT1 oscillator 

  /* Clock System Control Register 5: XT2 & XT1 startup counters and fault flags */
/*
  CSCTL5 = CLEAR_REGISTER;      // Clear register 
  CSCTL5 &= ~ENSTFCNT2;         // XT2 startup counter disabled, cleared 
  CSCTL5 &= ~ENSTFCNT1;         // XT1 startup counter disabled, cleared 
  CSCTL5 &= ~XT2OFFG;           // Clearing fault flag for XT2 
  CSCTL5 &= ~XT1OFFG;           // Clearing fault flag for XT1 
*/
  
  /* Clock System Control Register 6: Request enable for clocks */ 
/*
  CSCTL6 = CLEAR_REGISTER;      // Clear register 
  CSCTL6 &= ~MODCLKREQEN;       // Disables requests for MODCLK
  CSCTL6 &= ~SMCLKREQEN;        // Disables requests for SMCLK 
  CSCTL6 &= ~MCLKREQEN;         // Disables requests for MCLK 
  CSCTL6 &= ~ACLKREQEN;         // Disables requests for ACLK
*/

}

// Time delay logic 
void Delay_Xms(unsigned int myDelay){

}
