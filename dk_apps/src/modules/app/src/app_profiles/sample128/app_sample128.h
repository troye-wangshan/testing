/**
****************************************************************************************
*
* @file app_sample128.h
*
* @brief sample182 application.
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

#ifndef APP_SAMPLE128_H_
#define APP_SAMPLE128_H_

/**
 ****************************************************************************************
 * @addtogroup APP
 * @ingroup RICOW
 *
 * @brief Sample128 Application entry point.
 *
 * @{
 ****************************************************************************************
 */


/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwble_config.h"

#if BLE_SAMPLE128
#include "sample128.h"
#include "sample128_task.h"

/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */

/*
 * DEFINES
 ****************************************************************************************
 */

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */


/**
 ****************************************************************************************
 *
 * Sample128 Application Functions
 *
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Enable the sample128 profile
 *
 ****************************************************************************************
 */
void app_sample128_enable(void);

/**
 ****************************************************************************************
 * @brief Create Sample128 Database
 *
 ****************************************************************************************
 */
void app_sample128_create_db_send(void);

/**
 ****************************************************************************************
 * @brief Update sample128 2nd characteristic value.
 *
 * @return void.
 ****************************************************************************************
 */
void app_sample128_upd_char2(uint8_t val);


#endif // BLE_SAMPLE128

/// @} APP

#endif // APP_SAMPLE128_H_
