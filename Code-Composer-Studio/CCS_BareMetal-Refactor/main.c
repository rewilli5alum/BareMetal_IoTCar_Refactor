/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/

//******************************************************************************
//   Name: main.c
//   Author: Rachel E. Williams
//   Date Created: February 22, 2025
//   Last Updated: 4/2/2025
//   Description: This file contains the main routine to run the entire project
//                using while(1) "Super Loop" architecture
//   Previously built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//   Primarily built with Code Composer Studio 20.1.0.6
//******************************************************************************  

/* #includes */ 
#include "driverlib.h"
#include "msp430.h" 
#include "System.h"
#include "LCD.h"

/* Global Variables */ 

/* Constant Variables */ 


void main(void){
  // system-wide init 
  System_InitAll(); 

  /* Unable to run LCD due to unable to open .r43 IAR object file
  Init_LCD(); 
  display_1 = "Test"; 
  posL1 = 3; 
  display_2 = "Hello"; 
  posL2 = 1; 
  display_3 = "No"; 
  posL3 = 2; 
  display_4 = "hehe";  
  posL4 = 1; 
  LCD_Update();  
  */

  //GPIO-specific init 
  //---->IoT.c 
  //---->Motors.c 

}

