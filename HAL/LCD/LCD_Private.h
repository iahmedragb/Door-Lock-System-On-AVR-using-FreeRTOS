/*
* LCD_Private.h
*
* Created: 3/19/2022 3:58:49 AM
*  Author: Ahmed
*/


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define FOUR_BIT_MODE			0
#define EIGHT_BIT_MODE			1

#define SINGLE_LINE_MODE		0
#define DOUBLE_LINE_MODE		1

#define FIVE_x7					0
#define FIVE_x11				1

#define DISPLAY_OFF				0
#define DISPLAY_ON				1

#define CURSOR_OFF				0
#define CURSOR_ON				1

#define BLINK_OFF				0
#define BLINK_ON				1

#define DECREMENT				0
#define INCREMENT				1

#define NO_DISPLAY_SHIFT		0
#define DISPLAY_SHIFT			1

#define PATTERN0		(*(volatile u8*)(0x40))
#define PATTERN1		(*(volatile u8*)(0x48))
#define PATTERN2		(*(volatile u8*)(0x50))
#define PATTERN3		(*(volatile u8*)(0x58))
#define PATTERN4		(*(volatile u8*)(0x60))
#define PATTERN5		(*(volatile u8*)(0x68))
#define PATTERN6		(*(volatile u8*)(0x70))
#define PATTERN7		(*(volatile u8*)(0x78))



static ES_t LCD_enuLatch(u8 Copy_u8Latch);
						
#endif /* LCD_PRIVATE_H_ */
