/**
 ****************************************************************************************
 *
 * @file periph_setup.h
 *
 * @brief Peripherals setup header file. 
 *
 * Copyright (C) 2012. Dialog Semiconductor Ltd, unpublished work. This computer 
 * program includes Confidential, Proprietary Information and is a Trade Secret of 
 * Dialog Semiconductor Ltd.  All use, disclosure, and/or reproduction is prohibited 
 * unless authorized in writing. All Rights Reserved.
 *
 * <bluetooth.support@diasemi.com> and contributors.
 *
 ****************************************************************************************
 */
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
 
#include "global_io.h"
#include "arch.h"
#include "temp.h"
/*
 * DEFINES
 ****************************************************************************************
 */

#ifdef CFG_WKUP_EXT_PROCESSOR
/****************************************************************************************/ 
/* external MCU wake-up pin configuration                                               */
/****************************************************************************************/ 
    #define EXT_WAKEUP_PORT GPIO_PORT_1
    #define EXT_WAKEUP_PIN  GPIO_PIN_2 

#endif // #ifdef CFG_WKUP_EXT_PROCESSOR

#if BLE_INTEGRATED_HOST_GTL
 
/****************************************************************************************/ 
/* uart pin configuration                                                               */
/****************************************************************************************/ 

    #define UART1_TX_GPIO_PORT  GPIO_PORT_0
    #define UART1_TX_GPIO_PIN   GPIO_PIN_4

    #define UART1_RX_GPIO_PORT  GPIO_PORT_0
    #define UART1_RX_GPIO_PIN   GPIO_PIN_5

#endif //#if BLE_INTEGRATED_HOST_GTL

        #define MY1605A_GPIO_PORT  GPIO_PORT_0
				#define MY1605A_PIN  GPIO_PIN_1 
		 



/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

void periph_init(void);

void GPIO_reservations(void);

