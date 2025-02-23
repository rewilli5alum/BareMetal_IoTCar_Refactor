//******************************************************************************
//   Name: System_Ports.h
//   Author: Rachel E. Williams
//   Date Created: February 23, 2025
//   Last Updated: 2/22/2025
//   Description: This is the header file for System_Ports.c, containing 
//                function declarations and relevant macros 
//   Built with IAR Embedded Workbench IDE - MSP430 V8.10.3 
//******************************************************************************  

/* Macros */ 
#define RESET_REGISTER                   (0x00u) 

// Port 1 
#define V_DETECT_R                       (0x01u) // P1.0 
#define V_DETECT_L                       (0x02u) // P1.1 
#define IR_LED                           (0x04u) // P1.2 
#define V_THUMB                          (0x08u) // P1.3
#define SPI_CS_LCD                       (0x10u) // P1.4 
#define RS_LCD                           (0x20u) // P1.5
#define SPI_SIMO_B                       (0x40u) // P1.6 
#define SPI_SOMI_B                       (0x80u) // P1.7 

// Port 2 
#define USB_TXD                          (0x01u) // P2.0 
#define USB_RXD                          (0x02u) // P2.1 
#define SPI_SCK                          (0x04u) // P2.2 
#define P23_UNK                          (0x08u) // P2.3
#define P24_UNK                          (0x10u) // P2.4 
#define CPU_TXD                          (0x20u) // P2.5
#define CPU_RXD                          (0x40u) // P2.6 
#define P27_UNK                          (0x80u) // P2.7 

// Port 3 
#define P30_X                            (0x01u) // P3.0 
#define P31_Y                            (0x02u) // P3.1 
#define P32_Z                            (0x04u) // P3.2 
#define LCD_BACKLITE                     (0x08u) // P3.3
#define RIGHT_FWD                        (0x10u) // P3.4 
#define RIGHT_REV                        (0x20u) // P3.5
#define LEFT_FWD                         (0x40u) // P3.6 
#define LEFT_REV                         (0x80u) // P3.7 

// Port 4 
#define SW1                              (0x01u) // P4.0 
#define SW2                              (0x02u) // P4.1

// Port J 
#define IOT_FACTORY                      (0x01u) // PJ.0 
#define IOT_WAKEUP                       (0x02u) // PJ.1 
#define IOT_STA_MINIAP                   (0x04u) // PJ.2 
#define RESET                            (0x08u) // PJ.3 
#define XINR                             (0x10u) // XINR
#define XOUTR                            (0x20u) // XOUTR

/* Function declarations */ 
//------------------------------------------------------------------------------
//   Name: Init_AllPorts()
//   Description: Runs configuration and initialization of all ports within the 
//                system 
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_AllPorts(void);

//------------------------------------------------------------------------------
//   Name: Init_Port1()
//   Description: Performs configuration and initialization of Port 1  
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_Port1(void);

//------------------------------------------------------------------------------
//   Name: Init_Port2()
//   Description: Performs configuration and initialization of Port 2
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_Port2(void); 

//------------------------------------------------------------------------------
//   Name: Init_Port3()
//   Description: Performs configuration and initialization of Port 3 
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_Port3(void); 

//------------------------------------------------------------------------------
//   Name: Init_Port4()
//   Description: Performs configuration and initialization of Port 4   
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_Port4(void); 

//------------------------------------------------------------------------------
//   Name: Init_PortJ()
//   Description: Performs configuration and initialization of Port J    
//   Global variables: N/A
//   Input parameters: N/A
//   Return: N/A
//------------------------------------------------------------------------------
void Init_PortJ(void); 

