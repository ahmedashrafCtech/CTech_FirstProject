#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TMR1_register.h"
#include "TMR1_config.h"
#include "TMR1_private.h"
#include "TMR1_interface.h"


void(*GlobalPtrOverFlow)(void) = NULL ;

/**************************************Functions' implementation**************************************/
void TMR1_voidNormalSync(u8  Copy_u8Prescaler)
{
	/*1)set mode to be normal mode*/
	WRITE_BIT(TCCR1A , TCCR1A_WGM10 , 0);
	WRITE_BIT(TCCR1A , TCCR1A_WGM11 , 0);
	WRITE_BIT(TCCR1B , TCCR1B_WGM12 , 0);
	WRITE_BIT(TCCR1A , TCCR1B_WGM13 , 0);

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
	WRITE_BIT(TCCR1A , TCCR1B_WGM13 , 0);

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
	WRITE_BIT(TCCR1A , TCCR1B_WGM13 , 0);

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

void TMR1_voidSetCallBack(void(*PtrToFunc)(void))
{
	if(PtrToFunc != NULL)
		GlobalPtrOverFlow = PtrToFunc ;
}

/*******************************************************************************************************/

void TMR1_voidStopTimer1(void)
{
	TCCR1B &= PRESCALER_MASK ;        //clearing bits to add new prescaler value
	TCCR1B |= NO_PRESCALSER ;

}

/*******************************************************************************************************/

void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	GlobalPtrOverFlow();
}
