/**
****************************************************************************************
*
* @file app_sample128.c
*
* @brief sample128 application.
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

/**
 ****************************************************************************************
 * @addtogroup APP
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwble_config.h"

#if (BLE_APP_PRESENT)
#if (BLE_SAMPLE128)

#include "app_api.h"            // application task definitions
#include "sample128_task.h"     // sample128 functions
#include "app_sample128.h"

/*
 * FUNCTION DEFINITIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * Sample128 Application Functions
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief enable sample128 profile.
 *
 * @return void.
 ****************************************************************************************
 */
void app_sample128_enable(void)
{
    // Allocate the message
    struct sample128_enable_req* req = KE_MSG_ALLOC(SAMPLE128_ENABLE_REQ, TASK_SAMPLE128, TASK_APP,
                                                 sample128_enable_req);

    req->conhdl = app_env.conhdl;
    req->sec_lvl = PERM(SVC, ENABLE);
    req->sample128_1_val = 0x01;    // dummy value
    req->sample128_2_val = 0xff;    // dummy value
    req->feature = 0x00; // Client Configuration, notifications and indications are both disabled

    // Send the message
    ke_msg_send(req);

}

/**
 ****************************************************************************************
 * @brief Create Sample128 profile database.
 *
 * @return void.
 ****************************************************************************************
 */
void app_sample128_create_db_send(void)
{
    struct sample128_create_db_req *req = KE_MSG_ALLOC(SAMPLE128_CREATE_DB_REQ,
                                                  TASK_SAMPLE128, TASK_APP,
                                                  sample128_create_db_req);

    req->features = 0; // DUMMY NOT USED

    ke_msg_send(req);
}

/**
 ****************************************************************************************
 * @brief Update sample128 2nd characteristic value.
 *
 * @return void.
 ****************************************************************************************
 */
void app_sample128_upd_char2(uint8_t val)
{
    struct sample128_upd_char2_req *req = KE_MSG_ALLOC(SAMPLE128_UPD_CHAR2_REQ,
                                                  TASK_SAMPLE128, TASK_APP,
                                                  sample128_upd_char2_req);

    req->val = val;
    req->conhdl = app_env.conhdl;

    ke_msg_send(req);
}

#endif //BLE_SAMPLE128
#endif //BLE_APP_PRESENT

/// @} APP
