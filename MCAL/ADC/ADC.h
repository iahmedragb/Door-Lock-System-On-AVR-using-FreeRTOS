/*======================================================================================
========================    - ADC.h					 ===========================
========================    - Created: May 20, 2022			     ===========================
========================    - Author: Ahmed Tiba   			 ===========================
========================    - Version : _1_				     ===========================
========================    - Note :
									*-
									*-
=======================================================================================*/

/*=====================================================================================
		* What i sell To Customer
		*  The Architect Give The API
						- The Name Of Function
						- What is The Input
						- What Is The Output
						- Macro

======================================================================================*/
#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
/*
@Brief	:	

@param	:

@return	:

*/

#define OFF_STATE			55
#define ON_STATE			66
void ADC_Init(void);
void ADC_Start(void);
u16 ADC_Read(void);
void ADC_AdjustValue(u8 *RequiredValue,u8 *pAppParamterRead,void(*pAppFunStart)(void),void(*pAppFunStop)(void));
#endif /* MCAL_ADC_ADC_H_ */
