//******************************************************************************
//   Name: System_Ports.c
//   Author: Rachel E. Williams
//   Date Created: February 23, 2025
//   Last Updated: 2/23/2025
//   Description: This file contains the configuration and initialization of 
//                Ports 1,2,3,4, and J for the system--the MSP430FR5739 board
//                and custom ASIC Control Board 
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//******************************************************************************  

/* #includes */
#include "msp430.h"
#include "System_Ports.h" 

/* Global Variables */


/* Constant Variables */

void Init_AllPorts(void){
  Init_Port1(); 
  Init_Port2(); 
  Init_Port3(); 
  Init_Port4(); 
  Init_PortJ(); 
}

void Init_Port1(void){
  // Configure Port 1
  //   V_DETECT_R                  (0x01u) // P1.0 
  //   V_DETECT_L                  (0x02u) // P1.1 
  //   IR_LED                      (0x04u) // P1.2 
  //   V_THUMB                     (0x08u) // P1.3
  //   SPI_CS_LCD                  (0x10u) // P1.4, LCD Chip Select  
  //   RS_LCD                      (0x20u) // P1.5, LCD SA0 H/L Slave Addr
  //   SPI_SIMO_B                  (0x40u) // P1.6, SPI Mode - Slave In/Master Out of eUSCI_B0 
  //   SPI_SOMI_B                  (0x80u) // P1.7, SPI Mode - Slave Out/Master In of eUSCI_B0  
  // Note: interrupts are disabled when either PxSEL0 or PxSEL1 are set to 1
  //----------------------------------------------------------------------
  
  // Clearing registers to prepare for initialization 
  P1OUT = RESET_REGISTER;
  P1DIR = RESET_REGISTER;
  P1REN = RESET_REGISTER; 
  P1SEL0 = RESET_REGISTER; 
  P1SEL1 = RESET_REGISTER; 
  P1SELC = RESET_REGISTER;
  P1IES = RESET_REGISTER; 
  P1IE = RESET_REGISTER; 
  P1IFG = RESET_REGISTER; 
  
  // P1.0 - V_DETECT_R
  P1OUT &= ~V_DETECT_R;            // Configured output to low 
  P1DIR &= ~V_DETECT_R;            // Configured as input  
  P1REN &= ~V_DETECT_R;            // Pull up/down resistor disabled 
  P1SEL0 |= V_DETECT_R;            // Configured port function as tertiary module 
  P1SEL1 |= V_DETECT_R;            // Configured port function as tertiary module 
  
  // P1.1 - V_DETECT_L
  P1OUT &= ~V_DETECT_L;            // Configured output to low 
  P1DIR &= ~V_DETECT_L;            // Configured as input  
  P1REN &= ~V_DETECT_L;            // Pull up/down resistor disabled 
  P1SEL0 |= V_DETECT_L;            // Configured port function as tertiary module
  P1SEL1 |= V_DETECT_L;            // Configured port function as tertiary module
  
  // P1.2 - IR_LED
  P1OUT &= ~IR_LED;                // Configured output to low
  P1DIR |= IR_LED;                 // Configured as output
  P1SEL0 &= ~IR_LED;               // Configured port function as GPIO 
  P1SEL1 &= ~IR_LED;               // Configured port function as GPIO
  P1IES &= ~IR_LED;                // Interrupt edge select - low to high 
  P1IE &= ~IR_LED;                 // Interrupts disabled 
  P1IFG &= ~IR_LED;                // No interrupt flags pending  
  
  // P1.3 - V_THUMB
  P1OUT &= ~V_THUMB;               // Configured output to low 
  P1DIR &= ~V_THUMB;               // Configured as input  
  P1REN &= ~V_THUMB;               // Pull up/down resistor disabled 
  P1SEL0 |= V_THUMB;               // Configured port function as tertiary module 
  P1SEL1 |= V_THUMB;               // Configured port function as tertiary module
  
  // P1.4 - SPI_CS_LCD
  P1OUT |= SPI_CS_LCD;             // Configured output to high
  P1DIR |= SPI_CS_LCD;             // Configured as output
  P1SEL0 &= ~SPI_CS_LCD;           // Configured port function as GPIO 
  P1SEL1 &= ~SPI_CS_LCD;           // Configured port function as GPIO
  P1IES &= ~SPI_CS_LCD;            // Interrupt edge select - low to high 
  P1IE &= ~SPI_CS_LCD;             // Interrupts disabled 
  P1IFG &= ~SPI_CS_LCD;            // No interrupt flags pending  

  // P1.5 - RS_LCD
  P1OUT &= ~RS_LCD;                // Configured output to low
  P1DIR |= RS_LCD;                 // Configured as output
  P1SEL0 &= ~RS_LCD;               // Configured port function as GPIO 
  P1SEL1 &= ~RS_LCD;               // Configured port function as GPIO
  P1IES &= ~RS_LCD;                // Interrupt edge select - low to high 
  P1IE &= ~RS_LCD;                 // Interrupts disabled 
  P1IFG &= ~RS_LCD;                // No interrupt flags pending 

  // P1.6 - SPI_SIMO_B
  P1OUT &= ~SPI_SIMO_B;            // Configured output to low
  P1DIR |= SPI_SIMO_B;             // Configured as output
  P1SEL0 &= ~SPI_SIMO_B;           // Configured port function as secondary module
  P1SEL1 |= SPI_SIMO_B;            // Configured port function as secondary module

  // P1.7 - SPI_SOMI_B
  P1OUT &= ~SPI_SOMI_B;            // Configured output to low
  P1DIR &= ~SPI_SOMI_B;            // Configured as input 
  P1REN |= SPI_SOMI_B;             // Enable input with pulldown resistor 
  P1SEL0 &= ~SPI_SOMI_B;            // Configured port function as secondary module
  P1SEL1 |= SPI_SOMI_B;            // Configured port function as secondary module  
  
}

void Init_Port2(void){

}

void Init_Port3(void){

}

void Init_Port4(void){

}

void Init_PortJ(void){
  // no support for interrupts 

}
