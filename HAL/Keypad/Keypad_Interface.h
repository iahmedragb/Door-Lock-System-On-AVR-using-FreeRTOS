/*
 * Keypad_Interface.h
 *
 * Created: 3/23/2022 7:47:46 PM
 *  Author: Ahmed
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
#define NOT_PRESSED	0xff

ES_t KEYPAD_enuInit(void);
ES_t KEYPAD_enuGetPressedKey(u8 * Copy_pu8KeyValue);



#endif /* KEYPAD_INTERFACE_H_ */
