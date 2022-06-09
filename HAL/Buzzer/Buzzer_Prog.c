/*
* Buzzer_Prog.c
*
* Created: 3/23/2022 4:07:53 PM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO.h"

#include "Buzzer_Config.h"
#include "Buzzer_Private.h"

extern u8 Buzzer_u8BuzzerNum;
extern Buzzer_t Buzzer_BuzzerAstrConfig;
Buzzer_t* Buzzer_pAstr=&Buzzer_BuzzerAstrConfig;
ES_t Buzzer_enuInit(void)
{
	u8 Local_u8ErrorState =ES_NOK;
	if(Buzzer_pAstr !=NULL)
	{
		u8 Local_u8Iter=0;
		for(;Local_u8Iter<Buzzer_u8BuzzerNum; Local_u8Iter++)
		{

			M_DIO_enuSetPinDirection(Buzzer_pAstr[Local_u8Iter].Buzzer_Port,Buzzer_pAstr[Local_u8Iter].Buzzer_Pin,DIO_Direction_Output);
			M_DIO_enuSetPinValue(Buzzer_pAstr[Local_u8Iter].Buzzer_Port,Buzzer_pAstr[Local_u8Iter].Buzzer_Pin,DIO_State_Low);
		}
		Local_u8ErrorState = ES_OK;
	}else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	return Local_u8ErrorState;
}
ES_t Buzzer_enuON(u8 Buzzerx)
{
	M_DIO_enuSetPinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin,DIO_State_High);
	return ES_OK;
}
ES_t Buzzer_enuOFF(u8 Buzzerx)
{
	M_DIO_enuSetPinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin,DIO_State_Low);
	return ES_OK;
}
ES_t Buzzer_enuToggle(u8 Buzzerx)
{
	M_DIO_enuTogglePinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin);
	return ES_OK;
}
ES_t Buzzer_enuOnce(u8 Buzzerx)
{
	M_DIO_enuSetPinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin,DIO_State_High);
	_delay_ms(100);
	M_DIO_enuSetPinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin,DIO_State_Low);
	return ES_OK;
}
ES_t Buzzer_enuTwice(u8 Buzzerx)
{
	M_DIO_enuSetPinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin,DIO_State_High);
	_delay_ms(200);
	M_DIO_enuTogglePinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin);
	_delay_ms(200);
	M_DIO_enuTogglePinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin);
	_delay_ms(200);
	M_DIO_enuSetPinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin,DIO_State_Low);
	return ES_OK;
}
ES_t Buzzer_enuTriple(u8 Buzzerx)
{
	M_DIO_enuSetPinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin,DIO_State_High);
	_delay_ms(200);
	M_DIO_enuTogglePinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin);
	_delay_ms(200);
	M_DIO_enuTogglePinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin);
	_delay_ms(200);
	M_DIO_enuTogglePinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin);
	_delay_ms(200);
	M_DIO_enuTogglePinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin);
	_delay_ms(200);
	M_DIO_enuSetPinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin,DIO_State_Low);
	return ES_OK;
}
ES_t Buzzer_enuLong(u8 Buzzerx)
{
	M_DIO_enuSetPinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin,DIO_State_High);
	_delay_ms(1000);
	M_DIO_enuSetPinValue(Buzzer_pAstr[Buzzerx].Buzzer_Port,Buzzer_pAstr[Buzzerx].Buzzer_Pin,DIO_State_Low);
	return ES_OK;
}
