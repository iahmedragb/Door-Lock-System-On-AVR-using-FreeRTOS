/*=======================================================================================
============================   - main.c				 ============================
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


/*===========  INCLUDEAPP   ===========*/
#include "main.h"
/*=====================================*/

/*Initialization of variable of type System_t represents a Smart Home System*/
System_t Smart_home={NOT_PRESSED,NOT_PRESSED,(u8*)ADMIN_PASSWORD};

/*====================================================   Start_FUNCTION   ====================================================*/

int main (void)
{


	/*Initialize HAL layer*/
	Buzzer_enuInit();
	LCD_enuInit();
	KEYPAD_enuInit();
	LED_enuInit();

	/*AC Initialization*/
	AC=DEFAULT_AC_TEMP;
	AC_AdjustValue(&AC,&Temp);
	AC_Init();

	/*Create Tasks*/
	xTaskCreate(Login			,NULL,100	,NULL	,3	,&Login_Handler);
	xTaskCreate(Control_System	,NULL,300	,NULL	,2	,&Control_Handler);
	xTaskCreate(LCD_Print		,NULL,300	,NULL	,1	,&LCD_Handler);

	/*Create Semaphore*/
	vSemaphoreCreateBinary(Controlsem);

	/*Start Scheduler*/
	vTaskStartScheduler();
	while(1)
	{

	}
}
void Control_System(void*pv)
{
	u8 Control_state;
	while(1)
	{
		/*Take Semaphore*/
		Control_state= xSemaphoreTake(Controlsem,50);

		/*If Semaphore is available*/
		if(Control_state == pdPASS)
		{
			/*Read User Input*/
			KEYPAD_enuGetPressedKey(&Smart_home.key);
			/*Check User Input*/
			if(Smart_home.key != NOT_PRESSED)
			{
				/*Store User input in LCD data space*/
				Smart_home.LCD_Char = Smart_home.key;
				/*Take Action Based on User Inputs*/
				switch(Smart_home.key)
				{

				/*Toggle Door State*/
				case DOOR	:	LED_enuToggle(1);break;
				/*Toggle Window State*/
				case WINDOW	:	LED_enuToggle(0);break;
				/*Increase AC Required Temperature*/
				case AC_DEGREE_UP	:	if(AC<32)AC++;break;
				/*Decrease AC Required Temperature*/
				case AC_DEGREE_DOWN	:	if(AC>16)AC--;break;
				/*Call Security*/
				case CALL_SECURITY	:	Buzzer_enuTwice(1);break;
				/*Log Out*/
				case LOG_OUT	:	LED_enuToggle(2);
								vTaskResume(Login_Handler);break;
				//default
				}
				Smart_home.key= NOT_PRESSED;
			}
			xSemaphoreGive(Controlsem);
		}
		vTaskDelay(10);
	}

}
static u8 LCD_flag=OFF;

void LCD_Print(void*pv)
{
	u8 flag[MAX_SYSTEM_COMPONENTS]={1,1,1};
	u8 LCD_state;
	u8 first_time=0;
	while(1)
	{
		/*Take Semaphore*/
		LCD_state= xSemaphoreTake(Controlsem,50);
		/*If Semaphore is available*/
		if(LCD_state == pdPASS)
		{
			/*Display in case of first time*/
			if(LCD_flag == OFF && first_time==0 )
				{
					LCD_flag=ON;
					first_time=1;
					LCD_enuWriteCommand(COMMAND_CLEAR_DISPLAY);
					LCD_enuWriteString((u8*)"Door = OFF|WinD = OFF");
					LCD_enuGoToPosition(2,1);
					LCD_enuWriteString((u8*)"Temp = OFF|AC = OFF");
					LCD_enuGoToPosition(3,1);
					LCD_enuWriteString((u8*)"Call = None");
					LCD_enuGoToPosition(4,1);
					LCD_enuWriteString((u8*)"System On");
				}
			/*Continue Display of System Status in case of login after a log out */
			else if(LCD_flag == OFF && first_time==1 )
			{
				LCD_flag=ON;
				LCD_enuWriteCommand(COMMAND_CLEAR_DISPLAY);
				LCD_enuWriteString((u8*)"Door =    |WinD =    ");
				LCD_enuGoToPosition(2,1);
				LCD_enuWriteString((u8*)"Temp =    |AC =    ");
				LCD_enuGoToPosition(3,1);
				LCD_enuWriteString((u8*)"Call =    ");
				LCD_enuGoToPosition(4,1);
				LCD_enuWriteString((u8*)"System On");
				/*Door*/
				LCD_enuGoToPosition(1,8);
				if(flag[0] == 0)
				{
					LCD_enuWriteString((u8*)"OFF");
				}else
				{
					LCD_enuWriteString((u8*)"ON ");

				}
				/*Window*/
				LCD_enuGoToPosition(1,17);
				if(flag[1] == 0)
				{
					LCD_enuWriteString((u8*)"OFF");
				}else
				{
					LCD_enuWriteString((u8*)"ON ");

				}
				/*Temp*/
				LCD_enuGoToPosition(2,8);
				LCD_enuWriteIntegerNum(Temp);
				/*AC*/
				LCD_enuGoToPosition(2,16);
				LCD_enuWriteIntegerNum(AC);
				/*Caller*/
				LCD_enuGoToPosition(3,8);
				if(flag[2] == 0)
				{
					LCD_enuWriteString((u8*)"None     ");
				}else
				{
					flag[2]=0;
					LCD_enuWriteString((u8*)"Security");

				}

			}

			/*Normal Operation Display*/
			if(Smart_home.LCD_Char != NOT_PRESSED)
			{
				LCD_enuGoToPosition(2,8);
				LCD_enuWriteIntegerNum(Temp);
				LCD_enuWriteString((u8*)" C");
				switch(Smart_home.LCD_Char)
				{
				/*Display Door State*/
				case DOOR			:		LCD_enuGoToPosition(1,8);
											if(flag[0] == 0)
											{
												flag[0]=1;
												LCD_enuWriteString((u8*)"OFF");
											}else
											{
												flag[0]=0;
												LCD_enuWriteString((u8*)"ON ");

											}
											break;
				/*Display Window State*/
				case WINDOW			:		LCD_enuGoToPosition(1,18);
											if(flag[1] == 0)
											{
												flag[1]=1;
												LCD_enuWriteString((u8*)"OFF");
											}else
											{
												flag[1]=0;
												LCD_enuWriteString((u8*)"ON ");

											}
											break;
				/*Display AC Required Temperature*/
			case AC_DEGREE_UP...AC_DEGREE_DOWN		:	LCD_enuGoToPosition(2,16);
											LCD_enuWriteIntegerNum(AC);
											LCD_enuWriteString((u8*)" C");
											break;
			/*Display Call Status*/
			case CALL_SECURITY			:	LCD_enuGoToPosition(3,8);
										if(flag[2] == 0)
										{
											flag[2]=1;
											LCD_enuWriteString((u8*)"None     ");
										}else
										{
											flag[2]=0;
											LCD_enuWriteString((u8*)"Security");

										}
										break;
				}
				Smart_home.LCD_Char=NOT_PRESSED;
			}
			/*Semaphore Give*/
			xSemaphoreGive(Controlsem);
		}
		vTaskDelay(100);
	}
}
void Login(void*pv)
{
	u8 flag;
	u8 L_PasswordIter;
	u8 trial=0;
	while(1)
	{
		/*Suspend All Tasks*/
		vTaskSuspend(Control_Handler);
		vTaskSuspend(LCD_Handler);

		/*Initialize  Variables*/
		flag=pdPASS;
		L_PasswordIter=0;
		trial=0;
		LCD_flag=OFF;

		/*User Message*/
		LCD_enuWriteCommand(COMMAND_CLEAR_DISPLAY);
		LCD_enuGoToPosition(1,1);
		LCD_enuWriteString((u8*)"Enter Password");
		LCD_enuGoToPosition(4,1);
		LCD_enuWriteString((u8*)"System Login");
		LCD_enuGoToPosition(2,1);

		/*System LED is OFF*/
		LED_enuOff(2);

		/*Read Password from User*/
		while(L_PasswordIter <MAX_PASS_LEN)
		{
			KEYPAD_enuGetPressedKey(&Smart_home.key);
			if(Smart_home.key != NOT_PRESSED)
			{
				if((Smart_home.password[L_PasswordIter] != '\0') && (flag == pdPASS))
				{
					if(Smart_home.password[L_PasswordIter] == Smart_home.key)
					{
						L_PasswordIter++;
					}else
					{
						flag=pdFAIL;
					}
				}else if(Smart_home.key == '=' && flag== pdPASS)
				{
					break;
				}
				else if(Smart_home.key != '=' && flag == pdPASS)
				{
					flag=pdFAIL;
				}else if (Smart_home.key == '=')
				{
					break;
				}
				LCD_enuWriteData('*');

			}
		}
		/*Clear key*/
		Smart_home.key=NOT_PRESSED;

		/*Check User Inputs*/
		if(flag == pdPASS)
			{
				LCD_enuWriteCommand(COMMAND_CLEAR_DISPLAY);
				LCD_enuWriteString((u8*)"    Welcome !");
				vTaskDelay(1000);

				/*Resume tasks*/
				vTaskResume(Control_Handler);
				vTaskResume(LCD_Handler);
				/*System LED is ON*/
				LED_enuOn(2);

				/*Suspend Login Task*/
				vTaskSuspend(Login_Handler);
			}else
			{
				trial++;
				LCD_enuWriteCommand(COMMAND_CLEAR_DISPLAY);
				LCD_enuWriteString((u8*)"     Wrong !");
				LCD_enuGoToPosition(2,1);
				LCD_enuWriteString((u8*)"Trial  ");
				LCD_enuWriteData(trial+'0');
				if(trial%3 == 0 )
				{
					Buzzer_enuON(0);
					vTaskDelay(1000);
					Buzzer_enuOFF(0);
				}else
				{
					vTaskDelay(1000);
				}
			}
	}
}
