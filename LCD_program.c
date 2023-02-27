
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

/**************************************************************************************/

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

/**************************************************************************************/

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

/**************************************************************************************/

void LCD_voidClearDisplay(void)
{
	/*sending clear display command*/
	LCD_voidSendCmd(DISPLAY_CLEAR);
}

/**************************************************************************************/

void LCD_voidSendString(char * Copy_ptrString)
{
	/*local variable to iterate over strings' characters*/
	u8 Local_u8Iterator = 0 ;

	/*sending characters until it gets to  null characters*/
	while(Copy_ptrString[Local_u8Iterator] != '\0')
	{
		LCD_voidSendData(Copy_ptrString[Local_u8Iterator]);
		Local_u8Iterator ++ ;
	}
}

/**************************************************************************************/

void LCD_voidGoTo(u8 Copy_u8Row , u8 Copy_u8Column)
{
	/*local variable to assign address counter value*/
	u8 Local_u8Position ;

	/*in case of writing in the first row*/
	if(Copy_u8Row == 1)
		Local_u8Position = Copy_u8Column ;

	/*in case of writing in the second row*/
	else if(Copy_u8Row == 2)
		Local_u8Position = Copy_u8Column + 0x40 ;

	/*setting the command to contain 1 in MSB and address in remaining bits*/
	Local_u8Position |= (1<<7);

	LCD_voidSendCmd(Local_u8Position);
}

/**************************************************************************************/

void CLCD_voidDisplayNumber(u32 Copy_u32DisplayedNumber)
 {
         u32 Local_u32Reserved = 1 ;

         while(Copy_u32DisplayedNumber != 0)
         {
                 Local_u32Reserved=Local_u32Reserved*10 + Copy_u32DisplayedNumber%10 ;
                 Copy_u32DisplayedNumber/=10;
         }
         do
         {
                 LCD_voidSendData((Local_u32Reserved%10)+'0');
                 Local_u32Reserved/=10;
         }
         while(Local_u32Reserved!=1);
 }
