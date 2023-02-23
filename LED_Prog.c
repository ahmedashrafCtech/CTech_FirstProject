/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 21 FEB 2023                   */
/********************************************/

#include "STD.h"
#include "BitMath.h"
#include "DIO.h"
#include "LED_Private.h"
#include "LED_Config.h"
#include "LED_Int.h"


void HLED_vidLedInit(void)
{
	DIO_SetDir(LED_PORT,LED1_PIN,Pin_Output);
	DIO_SetDir(LED_PORT,LED2_PIN,Pin_Output);
	DIO_SetDir(LED_PORT,LED3_PIN,Pin_Output);
	DIO_SetDir(LED_PORT,LED4_PIN,Pin_Output);
}

void HLED_vidLedON(u8 LED_PORT,u8 LED_PIN)
{
	DIO_WrtPin(LED_PORT,LED_PIN,Pin_High);
}

void HLED_vidLedOFF(u8 LED_PORT,u8 LED_PIN)
{
	DIO_WrtPin(LED_PORT,LED_PIN,Pin_Low);
}

void HLED_vidLedTogg(u8 LED_PORT,u8 LED_PIN)
{
	DIO_TglPin(LED_PORT,LED_PIN);
}

void HLED_vidLedBlink(u8 LED_PORT,u8 LED_PIN)
{
	DIO_WrtPin(LED_PORT,LED_PIN,Pin_High);
	_delay_ms(ON_TIME);
	DIO_WrtPin(LED_PORT,LED_PIN,Pin_Low);
	_delay_ms(OFF_TIME);
	
}