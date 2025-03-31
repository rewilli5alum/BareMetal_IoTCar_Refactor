//******************************************************************************
//   Name: System_ADC10_B.c
//   Author: Rachel E. Williams
//   Date Created: March 31, 2025
//   Last Updated: 3/31/2025
//   Description: This file contains the configuration and initialization of 
//                the ADC10_B Core for the MSP430FR5739 board
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//   Primarily built with Code Composer Studio 20.1.0.6
//******************************************************************************  

/* #includes */
#include "msp430.h"
#include "msp430fr57xxgeneric.h"
#include "System_ADC10_B.h" 

/* Global Variables */


/* Constant Variables */


void Init_ADC10_B(){
  /* ADC10 Control Register 0: Sampling Rate and Conversion Configuration */
  ADC10CTL0 = CLEAR_REGISTER; 
  ADC10CTL0 |= ADC10SHT2;        // Sample and hold time: 16 clock cycles 
  ADC10CTL0 &= ~ADC10MSC;        // Multiple sample and conversion: Single Sample
  ADC10CTL0 |= ADC10ON;          // ADC10_B Core: Set to ON 

  /* ADC10 Control Register 1: Clock Source and Conversion Mode Configuration */
  ADC10CTL1 = CLEAR_REGISTER; 
  ADC10CTL1 |= ADC10SHS_0;      // Sample and hold source: ADC10SC bit (start conversion)
  ADC10CTL1 |= ADC10SHP;        // Pulse mode select: sampling timer 
  ADC10CTL1 &= ~ADC10ISSH;      // Invert Signal Sample: signal sample NOT inverted 
  ADC10CTL1 |= ADC10DIV_0;      // Clock divider selection: Divide by 1 
  ADC10CTL1 |= ADC10SSEL_0;     // Clock source select: MODCLK 
  ADC10CTL1 |= ADC10CONSEQ_0;   // Conversion seq mode select: single channel, singl conv.

  /* ADC10 Control Register 2: Sampling Rate, Resolution, Data Format Configuration */
  ADC10CTL2 = CLEAR_REGISTER; 
  ADC10CTL2 |= ADC10PDIV_0;    // Pre-divider: Divide by 1 
  ADC10CTL2 |= ADC10RES;       // Resolution: Set to 10-bit resolution 
  ADC10CTL2 &= ~ADC10DF;       // Data read-back format: Binary, unsigned 
  ADC10CTL2 &= ~ADC10SR;       // Sampling rate: 200 kilo samples per second (ksps)

  /* ADC10 Conversion Memory Control Register 0: Reference and Input Channel(s) */
  ADC10MCTL0 = CLEAR_REGISTER; 
  ADC10MCTL0 |= ADC10SREF_0;   // Reference select: V_r+ = AVCC V_r- = AVSS 
  ADC10MCTL0 |= ADC10INCH_0;   // Input channel select: Channel A0 

  /* ADC10 Interrupt Enable Regiser: Enable Interrupts for ADC10 */ 
  ADC10IE = CLEAR_REGISTER; 
  ADC10IE |= ADC10IE0;        // Interrupt Enable: Interrupts enabled for ADC10 conversion

} 
