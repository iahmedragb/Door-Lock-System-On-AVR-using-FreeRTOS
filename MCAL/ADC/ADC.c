/*=======================================================================================
============================   - ADC.c				 ============================
============================   - Created: May 20, 2022			 ============================
============================   - Author: Ahmed Tiba			     ============================
============================   - Version : _1_				 ============================
============================   - Note :
									     *-
									     *-
=======================================================================================*/


/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Interrupt.h"
/*======================================*/

/*===========  INCLUDE MCAL  ===========*/
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "ADC.h"
/*======================================*/

/*===========  INCLUDE HAL   ===========*/

/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/
static volatile u8 *ADC_RequiredValue;
static volatile u8 *ADC_ReadValue;
static volatile u8 ADC_CurrentAppState;
static void (*ADC_pAppFunStart)(void);
static void (*ADC_pAppFunStop)(void);
/*====================================================   Start_FUNCTION   ====================================================*/

void ADC_Init(void)
{
	/*ADC Enable*/
	SET_BIT(ADCSRA,ADEN);
	SET_BIT(ADCSRA,REFS0);
	/*channel*/
	ADMUX = ADC_Channel0;
	/*Prescaler */
	ADCSRA |= (7U<<0);
	/*ADC Interrupt*/
	SET_BIT(ADCSRA,ADIE);
	/*ADC Auto trigger*/
	SET_BIT(ADCSRA,ADATE);

}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
@Brief	:

@param	:

@return	:

*/
void ADC_Start(void)
{
	/*Clear flag*/
	//SET_BIT(ADCSRA,ADIF);
	/*Start Conversion*/
	SET_BIT(ADCSRA,ADSC);
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
@Brief	:

@param	:

@return	:

*/
u16 ADC_Read(void)
{
	u16 L_u8read=0;
	while(!(GET_BIT(ADCSRA,ADIF)));
	L_u8read= ADC;
	return L_u8read;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
@Brief	:

@param	:

@return	:

*/
void ADC_AdjustValue(u8 *RequiredValue,u8 *pAppParamterRead,void(*pAppFunStart)(void),void(*pAppFunStop)(void))
{
	if((pAppFunStart!=NULL)&&(pAppFunStop!=NULL))
		{
			ADC_pAppFunStart=pAppFunStart;
			ADC_pAppFunStop=pAppFunStop;
			ADC_CurrentAppState=OFF_STATE;
			ADC_RequiredValue=RequiredValue;
			ADC_ReadValue=pAppParamterRead;
		}else
		{
			//error
		}

}
/*====================================================   END_ FUNCTION   ====================================================*/
ISR(ADC_vect_16)
{
	u8 read=((ADC*5*1000ul/1023)+5)/10;
	*ADC_ReadValue=read;
	u8 RequiredRegisterValue = (*ADC_RequiredValue);
	if((read >RequiredRegisterValue) &&(ADC_CurrentAppState == OFF_STATE))
	{
		ADC_pAppFunStart();
		ADC_CurrentAppState = ON_STATE;
	}else if((read <= RequiredRegisterValue)&&(ADC_CurrentAppState == ON_STATE))
	{
		ADC_pAppFunStop();
		ADC_CurrentAppState = OFF_STATE;
	}
	SET_BIT(ADCSRA,ADSC);


}
