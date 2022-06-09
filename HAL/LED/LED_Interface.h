/*
 * LED_Interface.h
 *
 * Created: 3/19/2022 1:38:48 AM
 *  Author: Ahmed
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


ES_t LED_enuInit(void);
ES_t LED_enuOffAll(void);
ES_t LED_enuOnAll(void);
ES_t LED_enuOn(u8 LEDx);
ES_t LED_enuOff(u8 LEDx);
ES_t LED_enuToggle(u8 LEDx);

ES_t LED_enuState(u8 LEDx , u8 *Copy_StateGetStateValue);



#endif /* LED_INTERFACE_H_ */
