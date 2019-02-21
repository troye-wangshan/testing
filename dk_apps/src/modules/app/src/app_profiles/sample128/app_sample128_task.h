/**
****************************************************************************************
*
* @file app_sample128_task.h
*
* @brief sample28 task header. Sample128 Handlers declaration.
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

#include "rwip_config.h"

#ifndef APP_SAMPLE128_TASK_H_
#define APP_SAMPLE128_TASK_H_

/**
 ****************************************************************************************
 * @addtogroup APP
 * @ingroup RICOW
 *
 * @brief 
 *
 * @{
 ****************************************************************************************
 */


/*
 * INCLUDE FILES
 ****************************************************************************************
 */


#if BLE_SAMPLE128

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
 * @brief Handles sample128 profile database creation confirmation.
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
int app_sample128_create_db_cfm_handler(ke_msg_id_t const msgid,
                                        struct sample128_create_db_cfm const *param,
                                        ke_task_id_t const dest_id,
                                        ke_task_id_t const src_id);

/**
 ****************************************************************************************
 * @brief Handles disable indication from the sample128 profile.
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
int app_sample128_disable_ind_handler(ke_msg_id_t const msgid,
                                      struct sample128_disable_ind const *param,
                                      ke_task_id_t const dest_id,
                                      ke_task_id_t const src_id);

/**
 ****************************************************************************************
 * @brief Handles write of 1st characteristic event indication from sample128 profile
 * @return If the message was consumed or not.
 ****************************************************************************************
 */
int app_sample128_val_ind_handler(ke_msg_id_t const msgid,
                                  struct sample128_val_ind const *param,
                                  ke_task_id_t const dest_id,
                                  ke_task_id_t const src_id);


#endif //BLE_SAMPLE128

/// @} APP

#endif // APP_SAMPLE128_TASK_H_
