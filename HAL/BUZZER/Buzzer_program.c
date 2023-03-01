#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "DIO.h"
#include  "BUZZER_interface.h"


/*********************Functions' implementation***********************/

void BUZZER_voidInit(u8 Copy_u8BuzzerPort , u8 Copy_u8BuzzerPin)
{
	/*setting pin of buzzer to be output*/
	DIO_SetDir(Copy_u8BuzzerPort , Copy_u8BuzzerPin , Pin_Output);
}

/*********************************************************************/

void BUZZER_voidSetBuzzerOn(u8 Copy_u8BuzzerPort , u8 Copy_u8BuzzerPin)
{
	/*setting output pin to be high to fire the buzzer*/
	DIO_WrtPin(Copy_u8BuzzerPort , Copy_u8BuzzerPin , Pin_High);
}

/*********************************************************************/

void BUZZER_voidSetBuzzerOff(u8 Copy_u8BuzzerPort , u8 Copy_u8BuzzerPin)
{
	/*setting output pin to be low to stop the buzzer*/
	DIO_WrtPin(Copy_u8BuzzerPort , Copy_u8BuzzerPin , Pin_Low);
}

/*********************************************************************/
