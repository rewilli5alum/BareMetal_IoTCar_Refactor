//******************************************************************************
//   Name: System.h
//   Author: Rachel E. Williams
//   Date Created: February 24, 2025
//   Last Updated: 3/24/2025
//   Description: This is the header file for System.c, containing 
//                function declarations and relevant macros 
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//   Primarily built with Code Composer Studio 20.1.0.6
//******************************************************************************  

/* Macros */ 

/* Function declarations */ 
//------------------------------------------------------------------------------
//   Name: System_InitAll
//   Description: Initialize entire system, including clock system, timers, 
//                interrupts, ADC10, eUSCI, DMA, and GPIO ports
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void System_InitAll(void); 