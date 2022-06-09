/*
* LED_Config.c
*
* Created: 3/19/2022 1:38:11 AM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"

#include "../../MCAL/DIO/DIO.h"
#include "LED_Private.h"
#include "LED_Config.h"

u8 LED_u8LEDNum= LED_NUM;

LED_t LED_AstrLEDConfig[LED_NUM]=
{
	{DIO_PORTC,DIO_Pin2},
	{DIO_PORTC,DIO_Pin7},
	{DIO_PORTD,DIO_Pin3}
	//{DIO_PORTC,DIO_Pin3},
	//{DIO_PORTC,DIO_Pin4}
	
};
