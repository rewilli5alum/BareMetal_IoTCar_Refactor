//******************************************************************************
//   Name: System_Clocks.h
//   Author: Rachel E. Williams
//   Date Created: February 22, 2025
//   Last Updated: 3/24/2025
//   Description: This is the header file for System_Clocks.c, containing 
//                function declarations and relevant macros 
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//   Primarily built with Code Composer Studio 20.1.0.6
//******************************************************************************  

/* Macros */ 
#define CLEAR_REGISTER                   (0x0000u) 
#define ONE_SECOND                       (1000)


/* Function declarations */ 
//------------------------------------------------------------------------------
//   Name: Init_ClockSystem()
//   Description: Configures and initializes Clock System Registers 0-6 for the 
//                entire system.  
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_ClockSystem(); 



