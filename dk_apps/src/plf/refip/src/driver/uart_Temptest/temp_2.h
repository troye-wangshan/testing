/*
**************************************************************************************
 *
 * @file temp.h
 *
 ****************************************************************************************
 */

#ifndef _TEMP_2_H_
#define _TEMP_2_H_

#include "periph_setup.h"
#include "gpio.h"
#include "temp.h"


void bsp_DelayUS(unsigned int us);
static uint8_t MY1605B_Read_Bit(void);
uint8_t MY1605B_Read_Byte(void);
static void MY1605B_Rst(void);
static uint8_t MY1605B_Presence(void);
void MY1605B_Write_Byte(uint8_t dat);
float MY1605B_Read_Temperaure(void) ;
void MY1605B_RECALL(void);
	




#endif // _TEMP_2_H_
