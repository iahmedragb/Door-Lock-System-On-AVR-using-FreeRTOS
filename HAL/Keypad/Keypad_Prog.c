/*
 * Keypad_Prog.c
 *
 * Created: 3/23/2022 7:47:26 PM
 *  Author: Ahmed
 */ 
#include "../../LIB/Std_Types.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Bit_Math.h"

#include <util/delay.h>


#include "../../MCAL/DIO/DIO.h"
#include "Keypad_Private.h"
#include "Keypad_Config.h"
#include "Keypad_Interface.h"
ES_t KEYPAD_enuInit(void)
{
	
	M_DIO_enuSetPinDirection(C1_PRT,C1_PIN, DIO_Direction_Output);
	M_DIO_enuSetPinDirection(C2_PRT,C2_PIN, DIO_Direction_Output);
	M_DIO_enuSetPinDirection(C3_PRT,C3_PIN, DIO_Direction_Output);
	M_DIO_enuSetPinDirection(C4_PRT,C4_PIN, DIO_Direction_Output);

	M_DIO_enuSetPinValue(C1_PRT,C1_PIN, DIO_State_High);
	M_DIO_enuSetPinValue(C2_PRT,C2_PIN, DIO_State_High);
	M_DIO_enuSetPinValue(C3_PRT,C3_PIN, DIO_State_High);
	M_DIO_enuSetPinValue(C4_PRT,C4_PIN, DIO_State_High);

	M_DIO_enuSetPinDirection(R1_PRT,R1_PIN, DIO_Direction_Input);
	M_DIO_enuSetPinDirection(R2_PRT,R2_PIN, DIO_Direction_Input);
	M_DIO_enuSetPinDirection(R3_PRT,R3_PIN, DIO_Direction_Input);
	M_DIO_enuSetPinDirection(R4_PRT,R4_PIN, DIO_Direction_Input);
	M_DIO_enuSetPinValue(R1_PRT,R1_PIN, DIO_State_High);
	M_DIO_enuSetPinValue(R2_PRT,R2_PIN, DIO_State_High);
	M_DIO_enuSetPinValue(R3_PRT,R3_PIN, DIO_State_High);
	M_DIO_enuSetPinValue(R4_PRT,R4_PIN, DIO_State_High);
	return ES_OK;
	
}
ES_t KEYPAD_enuGetPressedKey(u8 * Copy_pu8KeyValue)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_pu8KeyValue != NULL)
	{
		u8 Local_u8RowIter=0;
		u8 Local_u8ColIter=0;
		
		u8 Local_Au8RowPort[Row] = {R1_PRT,R2_PRT,R3_PRT,R4_PRT};
		u8 Local_Au8RowPin[Row] = {R1_PIN,R2_PIN,R3_PIN,R4_PIN};
		
		u8 Local_Au8ColPort[Col] = {C1_PRT,C2_PRT,C3_PRT,C4_PRT};
		u8 Local_Au8ColPin[Col] = {C1_PIN,C2_PIN,C3_PIN,C4_PIN};
			
		u8 Local_u8RowVal = NOT_PRESSED,Local_u8Flag=0;
		for(; Local_u8ColIter<Col ; Local_u8ColIter++)
		{
			M_DIO_enuSetPinValue(Local_Au8ColPort[Local_u8ColIter],Local_Au8ColPin[Local_u8ColIter],DIO_State_Low);
			for(Local_u8RowIter=0;Local_u8RowIter<Row; Local_u8RowIter++)
			{

				M_DIO_enuGetPinValue(Local_Au8RowPort[Local_u8RowIter],Local_Au8RowPin[Local_u8RowIter],&Local_u8RowVal);
				if(Local_u8RowVal == DIO_State_Low)
				{
					_delay_ms(10);
					M_DIO_enuGetPinValue(Local_Au8RowPort[Local_u8RowIter],Local_Au8RowPin[Local_u8RowIter],&Local_u8RowVal);
					if(Local_u8RowVal == DIO_State_Low)
					{
						while(Local_u8RowVal == DIO_State_Low)
											{
												M_DIO_enuGetPinValue(Local_Au8RowPort[Local_u8RowIter],Local_Au8RowPin[Local_u8RowIter],&Local_u8RowVal);
											}
											u8 Local_Au8KeyValues[Row][Col]=KEYS_VALUES;
											*Copy_pu8KeyValue = Local_Au8KeyValues[Local_u8RowIter][Local_u8ColIter];
											Local_u8Flag =1;
					}

				}
				
			}
			M_DIO_enuSetPinValue(Local_Au8ColPort[Local_u8ColIter],Local_Au8ColPin[Local_u8ColIter],DIO_State_High);
		}
		if(!Local_u8Flag)
		{
			*Copy_pu8KeyValue = NOT_PRESSED;
		}		
	}else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	
	
	
	return Local_u8ErrorState;
}
