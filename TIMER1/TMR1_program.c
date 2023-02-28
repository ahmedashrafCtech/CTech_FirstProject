#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TMR1_register.h"
#include "TMR1_config.h"
#include "TMR1_private.h"
#include "TMR1_interface.h"


void(*GlobalPtrOverFlow)(void) = NULL ;
void(*GlobalPtrCTC)(void)=NULL ;

/**************************************Functions' implementation**************************************/
void TMR1_voidNormalSync(u8  Copy_u8Prescaler)
{
	/*1)set mode to be normal mode*/
	WRITE_BIT(TCCR1A , TCCR1A_WGM10 , 0);
	WRITE_BIT(TCCR1A , TCCR1A_WGM11 , 0);
	WRITE_BIT(TCCR1B , TCCR1B_WGM12 , 0);
	WRITE_BIT(TCCR1B , TCCR1B_WGM13 , 0);

	/*2)disconnecting OC1A & OC1B*/
	WRITE_BIT(TCCR1A,TCCR1A_COM1A0,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1A1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B0,0);

	/*3)setting prescaler to run timer*/
	TCCR1B &= PRESCALER_MASK ;        //clearing bits to add new prescaler value
	TCCR1B |= Copy_u8Prescaler ;

	/*4)polling over flag until it's raised*/
	while((GET_BIT(TIFR, TIFR_TOV1))==0);

	/*5)clearing the flag*/
	WRITE_BIT(TIFR, TIFR_TOV1,1);

}

/*******************************************************************************************************/

void TMR1_voidNormalAsync(u8 Copy_u8Prescaler)
{
	/*1)set mode to be normal mode*/
	WRITE_BIT(TCCR1A , TCCR1A_WGM10 , 0);
	WRITE_BIT(TCCR1A , TCCR1A_WGM11 , 0);
	WRITE_BIT(TCCR1B , TCCR1B_WGM12 , 0);
	WRITE_BIT(TCCR1B , TCCR1B_WGM13 , 0);

	/*2)disconnecting OC1A & OC1B*/
	WRITE_BIT(TCCR1A,TCCR1A_COM1A0,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1A1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B0,0);

	/*3)enabling both global and peripheral interrupt*/
	WRITE_BIT(TIMSK , TIMSK_TOIE1 , 1);
	WRITE_BIT(SREG,7,1);

	/*4)setting prescaler to run timer*/
	TCCR1B &= PRESCALER_MASK ;        //clearing bits to add new prescaler value
	TCCR1B |= Copy_u8Prescaler ;
}

/*******************************************************************************************************/

void TMR1_voidComMatchSync()
{
	/*1)set mode to compare match mode*/
	WRITE_BIT(TCCR1A , TCCR1A_WGM10 , 0);
	WRITE_BIT(TCCR1A , TCCR1A_WGM11 , 0);
	WRITE_BIT(TCCR1B , TCCR1B_WGM12 , 1);
	WRITE_BIT(TCCR1B , TCCR1B_WGM13 , 0);

	/*2)disconnecting OC1A & OC1B*/
	WRITE_BIT(TCCR1A,TCCR1A_COM1A0,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1A1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B0,0);

	/*3)setting OCR value*/
	/*FOR 1SEC DELAY*/
	OCR1A = 31250 ;

	/*4)setting prescaler to run timer*/
	TCCR1B &= PRESCALER_MASK ;        //clearing bits to add new prescaler value
	TCCR1B |= PRESCALER_256 ;

	/*5)polling over flag then clearing it*/
	while((GET_BIT(TIFR, TIFR_OCF1A))==0);
	WRITE_BIT(TIFR, TIFR_OCF1A,1);

}


/*******************************************************************************************************/

void TMR1_voidComMatchAsync()
{
	/*1)set mode to compare match mode*/
	WRITE_BIT(TCCR1A , TCCR1A_WGM10 , 0);
	WRITE_BIT(TCCR1A , TCCR1A_WGM11 , 0);
	WRITE_BIT(TCCR1B , TCCR1B_WGM12 , 1);
	WRITE_BIT(TCCR1B , TCCR1B_WGM13 , 0);

	/*2)disconnecting OC1A & OC1B*/
	WRITE_BIT(TCCR1A,TCCR1A_COM1A0,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1A1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B0,0);

	/*3)setting OCR value*/
	/*FOR 1SEC DELAY*/
	OCR1A = 31250 ;

	/*4)enabling both global and peripheral interrupt*/
	WRITE_BIT(TIMSK , TIMSK_OCIE1A , 1);
	WRITE_BIT(SREG,7,1);

	/*5)setting prescaler and running timer1*/
	TCCR1B &= PRESCALER_MASK ;        //clearing bits to add new prescaler value
	TCCR1B |= PRESCALER_1024 ;
}

/*******************************************************************************************************/

void TMR1_voidSetCallBack(u8 Copy_u8SrcID,void(*PtrToFunc)(void))
{
	switch(Copy_u8SrcID)
	{

		case NORMAL :
			if(PtrToFunc != NULL)
				GlobalPtrOverFlow = PtrToFunc ;
		break ;

		case CTC :
			if(PtrToFunc != NULL)
					GlobalPtrCTC = PtrToFunc ;
			break ;

	}
}

/*******************************************************************************************************/

void TMR1_voidFastPwm(u8 Copy_u8Channel , u16 Copy_u16Frequency , u8 Copy_u8DutyCycle)
{
	/*Setting running mode to be mode no.14 (fast PWM)*/
	WRITE_BIT(TCCR1A , TCCR1A_WGM10 , 0);
	WRITE_BIT(TCCR1A , TCCR1A_WGM11 , 1);
	WRITE_BIT(TCCR1B , TCCR1B_WGM12 , 1);
	WRITE_BIT(TCCR1B , TCCR1B_WGM13 , 1);

	/*2)Setting non inverted mode*/
	/*switching over channels*/
	switch(Copy_u8Channel)
	{
		case CHANNEL_A :
			WRITE_BIT(TCCR1A , TCCR1A_COM1A0 , 0);
			WRITE_BIT(TCCR1A , TCCR1A_COM1A1 , 1);
			break ;

		case CHANNEL_B :
			WRITE_BIT(TCCR1A , TCCR1A_COM1B0 , 0);
			WRITE_BIT(TCCR1A , TCCR1A_COM1B1 , 1);
			break ;
	}

	/*3)Setting ICR1 value that indicates frequency*/
	ICR1 = Copy_u16Frequency ;

	/*4)Setting value of OCR1x register that controls duty cycle*/
	/*switching over channels*/
	switch(Copy_u8Channel)
	{
		case CHANNEL_A :
			OCR1A = ((u32)Copy_u8DutyCycle * ICR1) / 100;  //mapping values
			break ;

		case CHANNEL_B :
			OCR1B = ((u32)Copy_u8DutyCycle * ICR1) / 100;  //mapping values
			break ;
	}

	/*5)Running timer tp generate pwm signal*/
	TCCR1B &= PRESCALER_MASK ;        //clearing bits to add new prescaler value
	TCCR1B |= PRESCALER_8 ;
}

/*******************************************************************************************************/

void TMR1_voidDelaySync(u16 Copy_u16TimeIn_ms)
{
	/*1)set mode to compare match mode*/
	WRITE_BIT(TCCR1A , TCCR1A_WGM10 , 0);
	WRITE_BIT(TCCR1A , TCCR1A_WGM11 , 0);
	WRITE_BIT(TCCR1B , TCCR1B_WGM12 , 1);
	WRITE_BIT(TCCR1B , TCCR1B_WGM13 , 0);

	/*2)disconnecting OC1A & OC1B*/
	WRITE_BIT(TCCR1A,TCCR1A_COM1A0,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1A1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B0,0);

	/*3)Converting target time to a value fits in OCR1A register*/
	OCR1A = ((u32)Copy_u16TimeIn_ms * 1000) / 125 ;

	/*4)Setting prescaler and running timer*/
	TCCR1B &= PRESCALER_MASK ;        //clearing bits to add new prescaler value
	TCCR1B |= PRESCALER_1024 ;

	/*5)Polling over flag until it rises then clearing it*/
	while((GET_BIT(TIFR, TIFR_OCF1A))==0);
	WRITE_BIT(TIFR, TIFR_OCF1A,1);

}

/*******************************************************************************************************/

void TMR1_voidDelayAsync(u16 Copy_u16TimeIn_ms)
{
	/*1)set mode to compare match mode*/
	WRITE_BIT(TCCR1A , TCCR1A_WGM10 , 0);
	WRITE_BIT(TCCR1A , TCCR1A_WGM11 , 0);
	WRITE_BIT(TCCR1B , TCCR1B_WGM12 , 1);
	WRITE_BIT(TCCR1B , TCCR1B_WGM13 , 0);

	/*2)disconnecting OC1A & OC1B*/
	WRITE_BIT(TCCR1A,TCCR1A_COM1A0,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1A1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B1,0);
	WRITE_BIT(TCCR1A,TCCR1A_COM1B0,0);

	/*3)Converting target time to a value fits in OCR1A register*/
	OCR1A = ((u32)Copy_u16TimeIn_ms * 1000) / 125 ;

	/*4)enabling both global and peripheral interrupt*/
	WRITE_BIT(TIMSK , TIMSK_OCIE1A , 1);
	WRITE_BIT(SREG,7,1);

	/*5)setting prescaler and running timer1*/
	TCCR1B &= PRESCALER_MASK ;        //clearing bits to add new prescaler value
	TCCR1B |= PRESCALER_1024 ;

}

/*******************************************************************************************************/

void TMR1_voidStopTimer1(void)
{
	TCCR1B &= PRESCALER_MASK ;        //clearing bits to add new prescaler value
	TCCR1B |= NO_PRESCALSER ;

}

/*******************************************************************************************************/

/*isr for CTC on channel A*/
void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	GlobalPtrCTC();
}

/*isr for normal over flow*/
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	GlobalPtrOverFlow();
}
