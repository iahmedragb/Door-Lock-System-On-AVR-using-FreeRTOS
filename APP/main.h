/*======================================================================================
========================    - main.h					 ===========================
========================    - Created: May 20, 2022			     ===========================
========================    - Author: Ahmed Tiba   			 ===========================
========================    - Version : _1_				     ===========================
========================    - Note :
									*-
									*-
=======================================================================================*/
/*====================================================================================
	- The Optiones Which Developer Choose From Which What Is Appropriate To App
=====================================================================================*/

#ifndef APP_MAIN_H_
#define APP_MAIN_H_

/*===========   INCLUDE LIB   ===========*/
#include "../LIB/Bit_Math.h"
#include "../LIB/Std_Types.h"
#include "../LIB/Error_State.h"
#include <util/delay.h>

/*======================================*/

/*===========  INCLUDE SERVICES  ===========*/
#include "../SERVICE/FreeRTOS/FreeRTOS.h"
#include "../SERVICE/FreeRTOS/task.h"
#include "../SERVICE/FreeRTOS/semphr.h"
/*======================================*/

/*===========  INCLUDE MCAL  ===========*/
/*======================================*/

/*===========  INCLUDE HAL   ===========*/
#include "../HAL/Buzzer/Buzzer_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/Keypad/Keypad_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/AC/AC.h"
/*======================================*/

/*Configurable Macros */
#define ADMIN_PASSWORD				"1234"
#define DEFAULT_AC_TEMP				25
#define MAX_SYSTEM_COMPONENTS		4
#define MAX_PASS_LEN				15

/*Private Macros*/
#define ON							77
#define OFF							88

#define DOOR						'1'
#define WINDOW						'2'
#define AC_DEGREE_UP				'3'
#define AC_DEGREE_DOWN				'4'
#define CALL_SECURITY				'5'
#define LOG_OUT						'7'

#define EMERGENCY_LED				8
#define BUZZER						9
#define LOG_OUT						10

/*User-defined datatypes*/
typedef struct System
{
	u8 key;
	u8 LCD_Char;
	u8 *password;
}System_t;

/*
 * void Login(void*pv);
 *
 * @Brief	:	This Task Suspends All System tasks until valid password is entered to log into system
 *
 * @param	:	pv is a pointer to void
 *
 * @return	:	None
 *
*/
void Login(void*pv);

/*
 * void Control_System(void*pv);
 *
 * @Brief	:	This task controls system functionality based on user inputs
 *
 * @param	:	pv is a pointer to void
 *
 * @return	:	None
 *
*/
void Control_System(void*pv);

/*
 * void LCD_Print(void*pv);
 *
 * @Brief	:	This task display system components status on LCD
 *
 * @param	:	pv is a pointer to void
 *
 * @return	:	None
 *
*/
void LCD_Print(void*pv);

/*TaskHandlers Declaration*/
xTaskHandle Login_Handler;
xTaskHandle Control_Handler;
xTaskHandle LCD_Handler;

/*Semaphores Declaration*/
xSemaphoreHandle Controlsem;

/*Global Variable Declaration*/
/*AC Required value*/
u8 AC;
/*Temperature sensor read*/
u8 Temp;
#endif /* APP_MAIN_H_ */
