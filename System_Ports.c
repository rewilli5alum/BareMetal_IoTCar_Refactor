//******************************************************************************
//   Name: System_Ports.c
//   Author: Rachel E. Williams
//   Date Created: February 23, 2025
//   Last Updated: 2/24/2025
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
  //   V_DETECT_R                  (0x01u) // P1.0, Detector - right side  
  //   V_DETECT_L                  (0x02u) // P1.1, Detector - left side 
  //   IR_LED                      (0x04u) // P1.2, IR LED - middle 
  //   V_THUMB                     (0x08u) // P1.3, Thumbwheel 
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
  P1OUT &= ~V_DETECT_R;            // Configured pin as input 
  P1DIR &= ~V_DETECT_R;            // Configured pin as input  
  P1REN &= ~V_DETECT_R;            // No pull up/down resistor
  P1SEL0 |= V_DETECT_R;            // Configured pin function as tertiary module 
  P1SEL1 |= V_DETECT_R;            // Configured pin function as tertiary module 

  // P1.1 - V_DETECT_L
  P1OUT &= ~V_DETECT_L;            // Configured pin as input 
  P1DIR &= ~V_DETECT_L;            // Configured pin as input  
  P1REN &= ~V_DETECT_L;            // No pull up/down resistor
  P1SEL0 |= V_DETECT_L;            // Configured pin function as tertiary module
  P1SEL1 |= V_DETECT_L;            // Configured pin function as tertiary module
  
  // P1.2 - IR_LED
  P1OUT &= ~IR_LED;                // Configured pin output to low
  P1DIR |= IR_LED;                 // Configured pin as output
  P1SEL0 &= ~IR_LED;               // Configured pin function as GPIO 
  P1SEL1 &= ~IR_LED;               // Configured pin function as GPIO
  P1IES &= ~IR_LED;                // Interrupt edge select - low to high 
  P1IE &= ~IR_LED;                 // Interrupts disabled for pin 
  P1IFG &= ~IR_LED;                // No interrupt flags pending for pin
  
  // P1.3 - V_THUMB
  P1OUT &= ~V_THUMB;               // Configured pin as input  
  P1DIR &= ~V_THUMB;               // Configured pin as input  
  P1REN &= ~V_THUMB;               // No pull up/down resistor
  P1SEL0 |= V_THUMB;               // Configured pin function as tertiary module 
  P1SEL1 |= V_THUMB;               // Configured pin function as tertiary module
  
  // P1.4 - SPI_CS_LCD
  P1OUT |= SPI_CS_LCD;             // Configured output to high
  P1DIR |= SPI_CS_LCD;             // Configured pin as output
  P1SEL0 &= ~SPI_CS_LCD;           // Configured pin function as GPIO 
  P1SEL1 &= ~SPI_CS_LCD;           // Configured pin function as GPIO
  P1IES &= ~SPI_CS_LCD;            // Interrupt edge select - low to high 
  P1IE &= ~SPI_CS_LCD;             // Interrupts disabled 
  P1IFG &= ~SPI_CS_LCD;            // No interrupt flags pending  

  // P1.5 - RS_LCD
  P1OUT &= ~RS_LCD;                // Configured output to low
  P1DIR |= RS_LCD;                 // Configured pin as output
  P1SEL0 &= ~RS_LCD;               // Configured pin function as GPIO 
  P1SEL1 &= ~RS_LCD;               // Configured pin function as GPIO
  P1IES &= ~RS_LCD;                // Interrupt edge select - low to high 
  P1IE &= ~RS_LCD;                 // Interrupts disabled 
  P1IFG &= ~RS_LCD;                // No interrupt flags pending 

  // P1.6 - SPI_SIMO_B
  P1OUT &= ~SPI_SIMO_B;            // Configured output to low
  P1DIR |= SPI_SIMO_B;             // Configured pin as output
  P1SEL0 &= ~SPI_SIMO_B;           // Configured pin function as secondary module
  P1SEL1 |= SPI_SIMO_B;            // Configured pin function as secondary module

  // P1.7 - SPI_SOMI_B
  P1OUT &= ~SPI_SOMI_B;            // Configured pin as input
  P1DIR &= ~SPI_SOMI_B;            // Configured pin as input 
  P1REN |= SPI_SOMI_B;             // Enable input with pulldown resistor 
  P1SEL0 &= ~SPI_SOMI_B;           // Configured pin function as secondary module
  P1SEL1 |= SPI_SOMI_B;            // Configured pin function as secondary module  
  
}

void Init_Port2(void){
  // Configure Port 2
  //   USB_TXD                     (0x01u) // P2.0, USB transmission 
  //   USB_RXD                     (0x02u) // P2.1, USB receive 
  //   SPI_SCK                     (0x04u) // P2.2 
  //   P23_UNK                     (0x08u) // P2.3, Unknown/unused 
  //   P24_UNK                     (0x10u) // P2.4, Unknown/unused
  //   CPU_TXD                     (0x20u) // P2.5, CPU transmission 
  //   CPU_RXD                     (0x40u) // P2.6, CPU receive 
  //   P27_UNK                     (0x80u) // P2.7, Unknown/unsued
  // Note: interrupts are disabled when either PxSEL0 or PxSEL1 are set to 1
  //----------------------------------------------------------------------
  
  // Clearing registers to prepare for initialization 
  P2OUT = RESET_REGISTER;
  P2DIR = RESET_REGISTER;
  P2REN = RESET_REGISTER; 
  P2SEL0 = RESET_REGISTER; 
  P2SEL1 = RESET_REGISTER; 
  P2SELC = RESET_REGISTER;
  P2IES = RESET_REGISTER; 
  P2IE = RESET_REGISTER; 
  P2IFG = RESET_REGISTER; 
  
  // P2.0 - USB_TXD 
  P2OUT &= ~USB_TXD;               // Configured output to low 
  P2DIR |= USB_TXD;                // Configured pin as output 
  P2SEL0 &= ~USB_TXD;              // Configured pin function as secondary module
  P2SEL1 |= USB_TXD;               // Configured pin function as secondary module
                                       
  // P2.1 - USB_RXD
  P2OUT &= ~USB_RXD;               // Configured pin as input
  P2DIR &= ~USB_RXD;               // Configured pin as input 
  P2SEL0 &= ~USB_RXD;              // Configured pin function as secondary module
  P2SEL1 |= USB_RXD;               // Configured pin function as secondary module
  
  // P2.2 - SPI_SCK 
  P2OUT |= SPI_SCK;                // Configured output to high 
  P2DIR |= SPI_SCK;                // Configured pin as output 
  P2SEL0 &= ~SPI_SCK;              // Configured pin function as secondary module
  P2SEL1 |= SPI_SCK;               // Configured pin function as secondary module
  
  // P2.3 - P23_UNK
  P2OUT &= ~P23_UNK;               // Unused: Configured output to low
  P2DIR |= P23_UNK;                // Unused: Configured pin as output 
  P2SEL0 &= ~P23_UNK;              // Unused: Configured pin function as GPIO 
  P2SEL1 &= ~P23_UNK;              // Unused: Configured pin function as GPIO 
  P2IES &= ~P23_UNK;               // Unused: Interrupts set to low-high transition 
  P2IE &= ~P23_UNK;                // Unused: Interrupts disabled for port pin 
  P2IFG &= ~P23_UNK;               // Unused: Interrupt flag cleared for port pin 
  
  // P2.4 - P24_UNK
  P2OUT &= ~P24_UNK;               // Unused: Configured output to low
  P2DIR |= P24_UNK;                // Unused: Configured pin as output 
  P2SEL0 &= ~P24_UNK;              // Unused: Configured pin function as GPIO 
  P2SEL1 &= ~P24_UNK;              // Unused: Configured pin function as GPIO 
  P2IES &= ~P24_UNK;               // Unused: Interrupts set to low-high transition 
  P2IE &= ~P24_UNK;                // Unused: Interrupts disabled for port pin 
  P2IFG &= ~P24_UNK;               // Unused: Interrupt flag cleared for port pin 

  // P2.5 - CPU_TXD
  P2OUT &= ~CPU_TXD;               // Configured output to low 
  P2DIR |= CPU_TXD;                // Configured pin as output 
  P2SEL0 &= ~CPU_TXD;              // Configured pin function as secondary module
  P2SEL1 |= CPU_TXD;               // Configured pin function as secondary module  
  
  // P2.6 - CPU_RXD 
  P2OUT &= ~CPU_RXD;               // Configured pin as input
  P2DIR &= ~CPU_RXD;               // Configured pin as input 
  P2SEL0 &= ~CPU_RXD;              // Configured pin function as secondary module
  P2SEL1 |= CPU_RXD;               // Configured pin function as secondary module
  
  // P2.7 - P27_UNK 
  P2OUT &= ~P27_UNK;               // Unused: Configured output to low
  P2DIR |= P27_UNK;                // Unused: Configured pin as output 
  P2SEL0 &= ~P27_UNK;              // Unused: Configured pin function as GPIO 
  P2SEL1 &= ~P27_UNK;              // Unused: Configured pin function as GPIO 
  P2IES &= ~P27_UNK;               // Unused: Interrupts set to low-high transition 
  P2IE &= ~P27_UNK;                // Unused: Interrupts disabled for port pin 
  P2IFG &= ~P27_UNK;               // Unused: Interrupt flag cleared for port pin 
}

void Init_Port3(void){
  // Configure Port 3 
  //   P30_X                       (0x01u) // P3.0, X direction - input  
  //   P31_Y                       (0x02u) // P3.1, Y direction - input 
  //   P32_Z                       (0x04u) // P3.2, Z direction - input 
  //   LCD_BACKLITE                (0x08u) // P3.3, LCD backlight 
  //   RIGHT_FWD                   (0x10u) // P3.4, Right wheel - forward
  //   RIGHT_REV                   (0x20u) // P3.5, Right wheel - reverse
  //   LEFT_FWD                    (0x40u) // P3.6, Left wheel - forward 
  //   LEFT_REV                    (0x80u) // P3.7, Left wheel - reverse 
  //----------------------------------------------------------------------
  
  // Clearing registers to prepare for initialization 
  P3OUT = RESET_REGISTER;
  P3DIR = RESET_REGISTER;
  P3REN = RESET_REGISTER; 
  P3SEL0 = RESET_REGISTER; 
  P3SEL1 = RESET_REGISTER; 
  P3SELC = RESET_REGISTER;
  P3IES = RESET_REGISTER; 
  P3IE = RESET_REGISTER; 
  P3IFG = RESET_REGISTER; 
  
  // P3.0 - P30_X
  P3OUT &= ~P30_X;                 // Configured pin as input
  P3DIR &= ~P30_X;                 // Configured pin as input 
  P3REN &= ~P30_X;                 // No pull up/down resistor 
  P3SEL0 &= ~P30_X;                // Configured pin function as GPIO 
  P3SEL1 &= ~P30_X;                // Configured pin function as GPIO 
  P3IES &= ~P30_X;                 // Interrupts set to low-high transition 
  P3IE &= ~P30_X;                  // Interrupts disabled for port pin 
  P3IFG &= ~P30_X;                 // Interrupt flag cleared for port pin 
                                       
  // P3.1 - P31_Y
  P3OUT &= ~P31_Y;                 // Configured pin as input
  P3DIR &= ~P31_Y;                 // Configured pin as input 
  P3REN &= ~P31_Y;                 // No pull up/down resistor
  P3SEL0 &= ~P31_Y;                // Configured pin function as GPIO 
  P3SEL1 &= ~P31_Y;                // Configured pin function as GPIO 
  P3IES &= ~P31_Y;                 // Interrupts set to low-high transition 
  P3IE &= ~P31_Y;                  // Interrupts disabled for port pin 
  P3IFG &= ~P31_Y;                 // Interrupt flag cleared for port pin 
  
  // P3.2 - P32_Z
  P3OUT &= ~P32_Z;                 // Configured pin as input 
  P3DIR &= ~P32_Z;                 // Configured pin as input 
  P3REN &= ~P32_Z;                 // No pull up/down resistor 
  P3SEL0 &= ~P32_Z;                // Configured pin function as GPIO 
  P3SEL1 &= ~P32_Z;                // Configured pin function as GPIO 
  P3IES &= ~P32_Z;                 // Interrupts set to low-high transition 
  P3IE &= ~P32_Z;                  // Interrupts disabled for port pin 
  P3IFG &= ~P32_Z;                 // Interrupt flag cleared for port pin
  
  // P3.3 - LCD_BACKLITE
  P3OUT &= ~LCD_BACKLITE;          // Configured output as low 
  P3DIR |= LCD_BACKLITE;           // Configured pin as output 
  P3SEL0 &= ~LCD_BACKLITE;         // Configured pin function as GPIO 
  P3SEL1 &= ~LCD_BACKLITE;         // Configured pin function as GPIO 
  P3IES &= ~LCD_BACKLITE;          // Interrupts set to low-high transition 
  P3IE &= ~LCD_BACKLITE;           // Interrupts disabled for port pin 
  P3IFG &= ~LCD_BACKLITE;          // Interrupt flag cleared for port pin
  
  // P3.4 - RIGHT_FWD
  P3OUT &= ~RIGHT_FWD;             // Configured output as low 
  P3DIR |= RIGHT_FWD;              // Configured pin as output 
  P3SEL0 &= ~RIGHT_FWD;            // Configured pin function as GPIO 
  P3SEL1 &= ~RIGHT_FWD;            // Configured pin function as GPIO 
  P3IES &= ~RIGHT_FWD;             // Interrupts set to low-high transition 
  P3IE &= ~RIGHT_FWD;              // Interrupts disabled for port pin 
  P3IFG &= ~RIGHT_FWD;             // Interrupt flag cleared for port pin
   
  // P3.5 - RIGHT_REV
  P3OUT &= ~RIGHT_REV;             // Configured output as low 
  P3DIR |= RIGHT_REV;              // Configured pin as output 
  P3SEL0 &= ~RIGHT_REV;            // Configured pin function as GPIO 
  P3SEL1 &= ~RIGHT_REV;            // Configured pin function as GPIO 
  P3IES &= ~RIGHT_REV;             // Interrupts set to low-high transition 
  P3IE &= ~RIGHT_REV;              // Interrupts disabled for port pin 
  P3IFG &= ~RIGHT_REV;             // Interrupt flag cleared for port pin
  
  // P3.6 - LEFT_FWD
  P3OUT &= ~LEFT_FWD;              // Configured output as low 
  P3DIR |= LEFT_FWD;               // Configured pin as output 
  P3SEL0 &= ~LEFT_FWD;             // Configured pin function as GPIO 
  P3SEL1 &= ~LEFT_FWD;             // Configured pin function as GPIO 
  P3IES &= ~LEFT_FWD;              // Interrupts set to low-high transition 
  P3IE &= ~LEFT_FWD;               // Interrupts disabled for port pin 
  P3IFG &= ~LEFT_FWD;              // Interrupt flag cleared for port pin
  
  // P3.7 - LEFT_REV
  P3OUT &= ~LEFT_REV;              // Configured output as low 
  P3DIR |= LEFT_REV;               // Configured pin as output 
  P3SEL0 &= ~LEFT_REV;             // Configured pin function as GPIO 
  P3SEL1 &= ~LEFT_REV;             // Configured pin function as GPIO 
  P3IES &= ~LEFT_REV;              // Interrupts set to low-high transition 
  P3IE &= ~LEFT_REV;               // Interrupts disabled for port pin 
  P3IFG &= ~LEFT_REV;              // Interrupt flag cleared for port pin
}

void Init_Port4(void){
  // Configure Port 4
  //   SW1                         (0x01u) // P4.0, Switch 1  
  //   SW2                         (0x02u) // P4.1, Switch 2 
  //----------------------------------------------------------------------
  
  // Clearing registers to prepare for initialization 
  P4OUT = RESET_REGISTER;
  P4DIR = RESET_REGISTER;
  P4REN = RESET_REGISTER; 
  P4SEL0 = RESET_REGISTER; 
  P4SEL1 = RESET_REGISTER; 
  P4SELC = RESET_REGISTER;
  P4IES = RESET_REGISTER; 
  P4IE = RESET_REGISTER; 
  P4IFG = RESET_REGISTER; 
  
  // P4.0 - SW1
  P4OUT |= SW1;                    // Pin is pulled up 
  P4DIR &= ~SW1;                   // Configured pin as input 
  P4REN |= SW1;                    // Configured pin as input with pullup resistor
  P4SEL0 &= ~SW1;                  // Configured pin function as GPIO 
  P4SEL1 &= ~SW1;                  // Configured pin function as GPIO 
  P4IES |= SW1;                    // Interrupts set on high-to-low transition 
  P4IE &= ~SW1;                    // Interrupts enabled for pin 
  P4IFG &= ~SW1;                   // Clearing interrupt flag for pin  
  
  // P4.1 - SW2
  P4OUT |= SW2;                    // Pin is pulled up
  P4DIR &= ~SW2;                   // Configured pin as input 
  P4REN |= SW2;                    // Configured pin as input with pullup resistor
  P4SEL0 &= ~SW2;                  // Configured pin function as GPIO 
  P4SEL1 &= ~SW2;                  // Configured pin function as GPIO 
  P4IES |= SW2;                    // Interrupts set on high-to-low transition 
  P4IE &= ~SW2;                    // Interrupts enabled for pin 
  P4IFG &= ~SW2;                   // Clearing interrupt flag for pin  
}

void Init_PortJ(void){
  // no support for interrupts
  // Configure Port J
  //   IOT_FACTORY                 (0x01u) // PJ.0, IoT factory initialization 
  //   IOT_WAKEUP                  (0x02u) // PJ.1, IoT module wakeup 
  //   IOT_STA_MINIAP              (0x04u) // PJ.2, IoT module miniap 
  //   IOT_RESET                   (0x08u) // PJ.3, IoT module reset 
  //   IOT_XINR                    (0x10u) // XINR
  //   IOT_XOUTR                   (0x20u) // XOUTR
  //----------------------------------------------------------------------  
  
  // Clearing registers to prepare for initialization 
  PJOUT = RESET_REGISTER;
  PJDIR = RESET_REGISTER;
  PJREN = RESET_REGISTER; 
  PJSEL0 = RESET_REGISTER; 
  PJSEL1 = RESET_REGISTER; 
  PJSELC = RESET_REGISTER;

  // PJ.0 - IOT_FACTORY 
  PJOUT &= ~IOT_FACTORY;          // Configured output as low   
  PJDIR |= IOT_FACTORY;           // Configured pin as output 
  PJSEL0 &= ~IOT_FACTORY;         // Configured pin function as GPIO
  PJSEL1 &= ~IOT_FACTORY;         // Configured pin function as GPIO
  
  // PJ.1 - IOT_WAKEUP
  PJOUT &= ~IOT_WAKEUP;           // Configured output as low 
  PJDIR |= IOT_WAKEUP;            // Configured pin as output
  PJSEL0 &= ~IOT_WAKEUP;          // Configured pin function as GPIO
  PJSEL1 &= ~IOT_WAKEUP;          // Configured pin function as GPIO
  
  // PJ.2 - IOT_STA_MINIAP
  PJOUT &= ~IOT_STA_MINIAP;       // Configured output as low 
  PJDIR |= IOT_STA_MINIAP;        // Configured pin as output  
  PJSEL0 &= ~IOT_STA_MINIAP;      // Configured pin function as GPIO
  PJSEL1 &= ~IOT_STA_MINIAP;      // Configured pin function as GPIO

  // PJ.3 - IOT_RESET
  PJOUT &= ~IOT_RESET;            // Configured output as low 
  PJDIR |= IOT_RESET;             // Configured pin as output 
  PJSEL0 &= ~IOT_RESET;           // Configured pin function as GPIO
  PJSEL1 &= ~IOT_RESET;           // Configured pin function as GPIO

  // XT1 Setup
  PJSEL0 |= IOT_XINR;
  PJSEL0 |= IOT_XOUTR;
}
