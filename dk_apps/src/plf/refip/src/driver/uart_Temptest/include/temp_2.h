/*
**************************************************************************************
 *
 * @file temp.h
 *
 ****************************************************************************************
 */

#ifndef _TEMP_2_H_
#define _TEMP_2_H_

#include "user_periph_setup.h"
#include "gpio.h"
#include "common_uart.h"
#include "temp.h"


//typedef enum   
//{  
//    SETUP_ROM           =   0xa6,
//	  SEARCH_ROM          =   0xf0,     
//    READ_ROM            =   0x33,   
//    MATCH_ROM           =   0x55,   
//    SKIP_ROM            =   0xcc,   
//    ALARM_SEARCH        =   0xec,    
//    CONVERT_T           =   0x44,   
//    WRITE_SCRATCHPAD    =   0x4e,   
//    READ_SCRATCHPAD     =   0xbe,   
//    WRITE_SCRATCHPAD_EXT =   0x8a,   
//    READ_SCRATCHPAD_EXT  =   0xaa,
//	  WRITE_USER_EXT      =   0xa7,   
//    READ_USER_EXT       =   0x87,
//	  WRITE_PARAMETERS    =   0xab,   
//    READ_PARAMETERS     =   0x8b,
//		WRITE_USER          =   0xa8,
//		COPY_PAGE0          =   0x48,     
//    COPY_PAGE1          =   0x4d,
//		RECALL_E2           =   0xb8,
//    RECALL_PAGE0_RES    =   0xb6,
//    RECALL_PAGE1        =   0xba,	
//    READ_POWER_SUPPLY   =   0xb4,    
//} QIANTANG_CMD;		


void bsp_DelayUS(unsigned int us);
static uint8_t MY1605B_Read_Bit(void);
uint8_t MY1605B_Read_Byte(void);
static void MY1605B_Rst(void);
static uint8_t MY1605B_Presence(void);
void MY1605B_Write_Byte(uint8_t dat);
float MY1605B_Read_Temperaure(void) ;

	




#endif // _TEMP_2_H_
