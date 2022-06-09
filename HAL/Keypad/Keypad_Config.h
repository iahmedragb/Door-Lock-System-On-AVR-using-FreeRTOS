/*
 * Keypad_Config.h
 *
 * Created: 3/23/2022 7:47:38 PM
 *  Author: Ahmed
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define Col					4
#define Row					4

#define R1_PRT			DIO_PORTB
#define R1_PIN			DIO_Pin4

#define R2_PRT			DIO_PORTB
#define R2_PIN			DIO_Pin5

#define R3_PRT			DIO_PORTB
#define R3_PIN			DIO_Pin6

#define R4_PRT			DIO_PORTB
#define R4_PIN			DIO_Pin7

#define C1_PRT			DIO_PORTC
#define C1_PIN			DIO_Pin3

#define C2_PRT			DIO_PORTC
#define C2_PIN			DIO_Pin4

#define C3_PRT			DIO_PORTC
#define C3_PIN			DIO_Pin5

#define C4_PRT			DIO_PORTC
#define C4_PIN			DIO_Pin6

#define KEYS_VALUES			{				\
							{'7','8','9','/'},\
							{'4','5','6','x'},\
							{'1','2','3','-'},\
							{'C','0','=','+'}\
}
#endif /* KEYPAD_CONFIG_H_ */
