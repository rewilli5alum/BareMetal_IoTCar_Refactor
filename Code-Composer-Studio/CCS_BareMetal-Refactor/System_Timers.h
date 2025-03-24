//******************************************************************************
//   Name: System_Timers.c
//   Author: Rachel E. Williams
//   Date Created: February 22, 2025
//   Last Updated: 3/24/2025
//   Description: This file contains the configuration and initialization of 
//                the Timers for the MSP430FR5739 board
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//   Primarily built with Code Composer Studio 20.1.0.6
//****************************************************************************** 

/* Macros */
#define TACCR0_INTERVAL                   (125) 
//#define TACCR1_INTERVAL                   (1)
//#define TACCR2_INTERVAL                   (1) 

/* Function declarations */ 
//------------------------------------------------------------------------------
//   Name: Init_Timers()
//   Description: Runs configuration and initialization of timers required for 
//                the application 
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_Timers(void);

//------------------------------------------------------------------------------
//   Name: Init_TimerA0()
//   Description: Completes configuration and initialization of TimerA0 
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_TimerA0(void);

//------------------------------------------------------------------------------
//   Name: Init_TimerA1()
//   Description: Completes configuration and initialization of TimerA1 
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_TimerA1(void);

//------------------------------------------------------------------------------
//   Name: Init_TimerB0()
//   Description: Completes configuration and initialization of TimerB0 
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_TimerB0(void);

//------------------------------------------------------------------------------
//   Name: Init_TimerB1()
//   Description: Completes configuration and initialization of TimerB1 
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_TimerB1(void);

//------------------------------------------------------------------------------
//   Name: Init_TimerB2()
//   Description: Completes configuration and initialization of TimerB2 
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_Timer_B2(void);
