/* 
 * File:   application.h
 * Author: Marwa Abdelrahman
 *
 * Created on August 1, 2024, 1:08 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H
#include "ECU_Layer/LED/ecu_led.h"
#include "ECU_Layer/BUTTON/ecu_button.h"
#include "ECU_Layer/RELAY/ecu_relay.h"
#include "ECU_Layer/DC_Motor/ecu_dc_motor.h"
#include"ECU_Layer/7_Segment_Display/ecu_seven_seg.h"
/*.....................................Includes.....................................*/


/*.....................................Macros Declarations.....................................*/

#define _XTAL_FREQ   8000000

/*.....................................Macros Functions Declarations.....................................*/



/*.....................................Data Types Declarations.....................................*/
/*.....................................Functions Declarations.....................................*/
/**
 * 
 */
void app_init(void);
#endif	/* APPLICATION_H */

