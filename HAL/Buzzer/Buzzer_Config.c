/*
* Buzzer_Config.c
*
* Created: 3/23/2022 4:07:15 PM
*  Author: Ahmed
*/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"

#include "../../MCAL/DIO/DIO.h"
#include "Buzzer_Private.h"
#include "Buzzer_Config.h"

u8 Buzzer_u8BuzzerNum = BUZZER_NUM;

Buzzer_t Buzzer_BuzzerAstrConfig[BUZZER_NUM]=
{
	{DIO_PORTD,DIO_Pin2},
	{DIO_PORTC,DIO_Pin0},
	{DIO_PORTC,DIO_Pin1}
};
