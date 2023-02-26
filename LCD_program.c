
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "util/delay.h"

#include "DIO.h"

#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"

/*************************Functions' implementation*******************************/

void LCD_voidSendCmd(u8 Copy_u8Command)
{
	/*1)setting RS pin to be LOW*/
	DIO_WrtPin(CTRL_PORT , RS_PIN , Pin_Low);

	/*2)setting R/W pin to be low*/
	DIO_WrtPin(CTRL_PORT , RW_PIN , Pin_Low);

	/*3)sending command through data pins*/
	DIO_WRTPort(DATA_PORT , Copy_u8Command);

	/*4)setting enable pin to be high then delay*/
	DIO_WrtPin(CTRL_PORT , EN_PIN , Pin_High);
	_delay_ms(1);

	/*5)setting enable pin to be low then delay*/
	DIO_WrtPin(CTRL_PORT , EN_PIN , Pin_Low);
	_delay_ms(1);
}


void LCD_voidSendData(u8 Copy_u8Data)
{
	/*1)setting RS pin to be HIGH*/
	DIO_WrtPin(CTRL_PORT , RS_PIN , Pin_High);

	/*2)setting R/W pin to be low*/
	DIO_WrtPin(CTRL_PORT , RW_PIN , Pin_Low);

	/*3)sending data through data pins*/
	DIO_WRTPort(DATA_PORT , Copy_u8Data);

	/*4)setting enable pin to be high then delay*/
	DIO_WrtPin(CTRL_PORT , EN_PIN , Pin_High);
	_delay_ms(1);

	/*5)setting enable pin to be low then delay*/
	DIO_WrtPin(CTRL_PORT , EN_PIN , Pin_Low);
	_delay_ms(1);
}


void LCD_voidInit8Bit(void)
{
	/**initializing pins connected to [control and data pins] lcd to be output**/
	DIO_DIRPort(DATA_PORT,PORT_HIGH_VAL);
	DIO_SetDir(CTRL_PORT,RS_PIN,Pin_Output);
	DIO_SetDir(CTRL_PORT,RW_PIN,Pin_Output);
	DIO_SetDir(CTRL_PORT,EN_PIN,Pin_Output);

	/*1)delay for more than 30 ms*/
	_delay_ms(40);

	/*2)sending function set command*/
	LCD_voidSendCmd(FUNCTION_SET);

	/*3)delay for more than 30 us*/
	_delay_ms(1);

	/*4)sending display on/off command*/
	LCD_voidSendCmd(DISPLAY_ON_OFF_CTRL);

	/*5)delay for more than 30 us*/
	_delay_ms(1);

	/*6)sending display on/off command*/
	LCD_voidSendCmd(DISPLAY_CLEAR);

	/*7)delay for more than 1.53ms*/
	_delay_ms(2);



}
