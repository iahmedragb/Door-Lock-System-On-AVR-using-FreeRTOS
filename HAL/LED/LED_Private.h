/*
 * LED_Private.h
 *
 * Created: 3/19/2022 1:38:40 AM
 *  Author: Ahmed
 */ 


#ifndef LED_PRIVATE_H_
#define LED_PRIVATE_H_

#define LED_ON	DIO_State_High
#define LED_OFF	DIO_State_Low


typedef struct
{
	u8 LED_Port;
	u8 LED_Pin;
}LED_t;


#endif /* LED_PRIVATE_H_ */
