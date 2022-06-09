/*
* LED_Prog.c
*
* Created: 3/19/2022 1:38:27 AM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"

#include "../../MCAL/DIO/DIO.h"
#include "LED_Private.h"
#include "LED_Config.h"

extern u8 LED_u8LEDNum;
extern LED_t LED_AstrLEDConfig;
LED_t *LED_AstrLEDLink=&LED_AstrLEDConfig;

ES_t LED_enuInit(void)
{
	u8 Local_u8ErrorState = ES_NOK;
		u8 Local_u8Iter = 0;
		for(;Local_u8Iter < LED_u8LEDNum ; Local_u8Iter++)
		{
			M_DIO_enuSetPinDirection(LED_AstrLEDLink[Local_u8Iter].LED_Port , LED_AstrLEDLink[Local_u8Iter].LED_Pin, DIO_Direction_Output);
			M_DIO_enuSetPinValue(LED_AstrLEDLink[Local_u8Iter].LED_Port , LED_AstrLEDLink[Local_u8Iter].LED_Pin, LED_OFF);
		}
		Local_u8ErrorState = ES_OK;
	return Local_u8ErrorState;
}
ES_t LED_enuOffAll(void)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(LED_AstrLEDLink != NULL)
	{
		u8 Local_u8Iter = 0;
		for(;Local_u8Iter < LED_u8LEDNum ; Local_u8Iter++)
		{
			M_DIO_enuSetPinValue(LED_AstrLEDLink[Local_u8Iter].LED_Port , LED_AstrLEDLink[Local_u8Iter].LED_Pin, LED_OFF);
		}
		Local_u8ErrorState = ES_OK;
	}else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	return Local_u8ErrorState;
}
ES_t LED_enuOnAll(void)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(LED_AstrLEDLink != NULL)
	{
		u8 Local_u8Iter = 0;
		for(;Local_u8Iter < LED_u8LEDNum ; Local_u8Iter++)
		{
			M_DIO_enuSetPinValue(LED_AstrLEDLink[Local_u8Iter].LED_Port , LED_AstrLEDLink[Local_u8Iter].LED_Pin, LED_ON);
		}
		Local_u8ErrorState = ES_OK;
	}else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	return Local_u8ErrorState;
}
ES_t LED_enuOn(u8 LEDx)
{
	if(LEDx <LED_u8LEDNum)
	M_DIO_enuSetPinValue(LED_AstrLEDLink[LEDx].LED_Port , LED_AstrLEDLink[LEDx].LED_Pin, LED_ON);
	return ES_OK;
}
ES_t LED_enuOff(u8 LEDx)
{
	if(LEDx <LED_u8LEDNum)
	M_DIO_enuSetPinValue(LED_AstrLEDLink[LEDx].LED_Port , LED_AstrLEDLink[LEDx].LED_Pin, LED_OFF);
	return ES_OK;
}
ES_t LED_enuToggle(u8 LEDx)
{
	if(LEDx <LED_u8LEDNum)
	M_DIO_enuTogglePinValue(LED_AstrLEDLink[LEDx].LED_Port , LED_AstrLEDLink[LEDx].LED_Pin);
	return ES_OK;
}

ES_t LED_enuState(u8 LEDx , u8 *Copy_StateGetStateValue)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_StateGetStateValue!=NULL)
	{
		if(LEDx <LED_u8LEDNum)
		M_DIO_enuGetPinValue(LED_AstrLEDLink[LEDx].LED_Port , LED_AstrLEDLink[LEDx].LED_Pin, Copy_StateGetStateValue);
		Local_u8ErrorState = ES_OK;
	}else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	return Local_u8ErrorState;
}
