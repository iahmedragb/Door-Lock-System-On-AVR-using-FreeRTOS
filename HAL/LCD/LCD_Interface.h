/*
 * LCD_Interface.h
 *
 * Created: 3/19/2022 3:58:58 AM
 *  Author: Ahmed
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



/*Commands List*/
#define COMMAND_CLEAR_DISPLAY				0x01
#define COMMAND_RETURN_HOME					0x02
#define COMMAND_DECREMENT_CURSOR			0x04
#define COMMAND_INCREMENT_CURSOR			0x06
#define COMMAND_SHIFT_DISPLAY_RIGHT			0x05
#define COMMAND_SHIFT_DISPLAY_LEFT			0x07
#define COMMAND_DISPLAY_OFF_CURSOR_OFF		0x08
#define COMMAND_DISPLAY_OFF_CURSOR_ON		0x0A
#define COMMAND_DISPLAY_ON_CURSOR_OFF		0x0C
#define COMMAND_DISPLAY_ON_CURSOR_BLINK		0x0E
#define COMMAND_DISPLAY_ON_CURSOR_BLINK2	0x0F
#define COMMAND_SHIFT_CURSOR_LEFT			0x10
#define COMMAND_SHIFT_CURSOR_RIGHT			0x14
#define COMMAND_SHIFT_ENTIRE_DISPLAY_RIGHT	0x1C
#define COMMAND_SHIFT_ENTIRE_DISPLAY_LEFT	0x18
#define COMMAND_FORCE_CURSOR_1ST_LINE_1ST_POSITION	0x80
#define COMMAND_FORCE_CURSOR_2ND_LINE_1ST_POSITION	0xC0
#define COMMADN_2LINES_FIVE_X_7_4BIT		0x28
#define COMMADN_2LINES_FIVE_X_7_8BIT		0x38


ES_t LCD_enuInit(void);
ES_t LCD_enuWriteCommand(u8 Copy_u8Command);
ES_t LCD_enuWriteData(u8 Copy_u8Data);
ES_t LCD_enuWriteString(const u8 *Copy_pu8String);
ES_t LCD_enuWriteIntegerNum(s32 Copy_s32IntegerNum);
ES_t LCD_enuWriteFloatNum(f32 Copy_f32FloatNum);
ES_t LCD_enuGoToPosition(u8 Copy_u8Row, u8 Copy_u8Column);
ES_t LCD_enuCharacterGenerator(u8 Pattern, const u8 *Copy_u8CustomCharacter);


ES_t LCD_enuStopWatch(u8 Seconds,u8  Minutes,u8  Hours);


#endif /* LCD_INTERFACE_H_ */
