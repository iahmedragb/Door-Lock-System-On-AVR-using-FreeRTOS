/*
 * Buzzer_Interface.h
 *
 * Created: 3/23/2022 4:07:34 PM
 *  Author: Ahmed
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_
 


 ES_t Buzzer_enuInit(void);
 ES_t Buzzer_enuON(u8 Buzzerx);
 ES_t Buzzer_enuOFF(u8 Buzzerx);
 ES_t Buzzer_enuToggle(u8 Buzzerx);
 ES_t Buzzer_enuOnce(u8 Buzzerx);
 ES_t Buzzer_enuTwice(u8 Buzzerx);
 ES_t Buzzer_enuTriple(u8 Buzzerx);
 ES_t Buzzer_enuLong(u8 Buzzerx);
 




#endif /* BUZZER_INTERFACE_H_ */
