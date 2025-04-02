//******************************************************************************
//   Name: LCD.h
//   Author: Rachel E. Williams
//   Date Created: February 22, 2025
//   Last Updated: 3/24/2025
//   Description: This is the header file for LCD.c
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//   Primarily built with Code Composer Studio 20.1.0.6
//****************************************************************************** 

/* Macros */
#define LCD_HOME_L1	              (0x80)
#define LCD_HOME_L2               (0xA0)
#define LCD_HOME_L3               (0xC0)
#define LCD_HOME_L4               (0xE0)
#define POS_1                     (0x01)
#define POS_2                     (0x02)
#define POS_3                     (0x03)
#define POS_4                     (0x04)
#define ARRAY_LENGTH              (0x0B)

/* Global Variables */
char* display_1; 
char* display_2; 
char* display_3; 
char* display_4; 
char posL1; 
char posL2; 
char posL3; 
char posL4;

/* Function declarations */ 
//------------------------------------------------------------------------------
//   Name: LCD_Ready()
//   Description: Input new information prior to updating to LCD 
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
//void LCD_Ready(void);
/*
//------------------------------------------------------------------------------
//   Name: LCD_Update()
//   Description: Updates LCD with new information 
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void LCD_Update(void);

//------------------------------------------------------------------------------
//   Name: Init_LCD()
//   Description: Initializes LCD (most likely written by Carlson)
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_LCD(); 
*/
