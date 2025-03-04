//******************************************************************************
//   Name: main.c
//   Author: Rachel E. Williams
//   Date Created: February 22, 2025
//   Last Updated: 2/24/2025
//   Description: This file contains the main routine to run the entire project
//                using while(1) "Super Loop" architecture
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//******************************************************************************  

/* #includes */ 
#include "msp430.h" 
#include "System.h"

/* Global Variables */ 

/* Constant Variables */ 


void main(void){
  // system-wide init 
  System_InitAll();   
  
  //GPIO-specific init 
  //---->LCD.c 
  //---->IoT.c '
  //---->Switches.c 
  //---->Motors.c 

}