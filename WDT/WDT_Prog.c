/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 27 FEB 2023                   */
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WDT_Private.h"
#include "WDT_Config.h"
#include "WDT_Int.h"


void WDT_vidStart(u8 Time )
{
	WDTCR_REG &= WDT_PRESCALER_MASK  ;
	WDTCR_REG |= Time ;
	
	//enable WDT
	WDTCR_REG |= (1<<WDE_BIT) ;
	
}

void WDT_vidRefresh(void)
{
	asm("WDR");
}

void WDT_vidStop(void)
{
	WDTCR_REG |= (1<<WDTOE_BIT) | (1<<WDE_BIT);
	/* Turn off WDT */
	WDTCR_REG = 0x00;
}
