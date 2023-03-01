/*
 * SSD.c
 *
 *  Created on: Feb 23, 2023
 *      Author: Osama.Mahmoud
 */


#include "SSD.h"

void SEG_voidInit(u8 Copy_u8DisplayID)
{
	DIO_SetDir(SEG_pinmap[Copy_u8DisplayID].SEGA_port, SEG_pinmap[Copy_u8DisplayID].SEGA_pin, Pin_Output);
	DIO_SetDir(SEG_pinmap[Copy_u8DisplayID].SEGB_port, SEG_pinmap[Copy_u8DisplayID].SEGB_pin, Pin_Output);
	DIO_SetDir(SEG_pinmap[Copy_u8DisplayID].SEGC_port, SEG_pinmap[Copy_u8DisplayID].SEGC_pin, Pin_Output);
	DIO_SetDir(SEG_pinmap[Copy_u8DisplayID].SEGD_port, SEG_pinmap[Copy_u8DisplayID].SEGD_pin, Pin_Output);
	DIO_SetDir(SEG_pinmap[Copy_u8DisplayID].SEGE_port, SEG_pinmap[Copy_u8DisplayID].SEGE_pin, Pin_Output);
	DIO_SetDir(SEG_pinmap[Copy_u8DisplayID].SEGF_port, SEG_pinmap[Copy_u8DisplayID].SEGF_pin, Pin_Output);
	DIO_SetDir(SEG_pinmap[Copy_u8DisplayID].SEGG_port, SEG_pinmap[Copy_u8DisplayID].SEGG_pin, Pin_Output);
}

void SSD_voidDisplayNumber(u8 Copy_u8DisplayID , u8 Copy_u8DisplayNumber)
{
	static u8 SEG_DataNumber[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

	if (SEG_pinmap[Copy_u8DisplayID].Mode == COMMON_CATHODE)
	{
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGA_port , SEG_pinmap[Copy_u8DisplayID].SEGA_pin , GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 0));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGB_port , SEG_pinmap[Copy_u8DisplayID].SEGB_pin , GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 1));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGC_port , SEG_pinmap[Copy_u8DisplayID].SEGC_pin , GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 2));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGD_port , SEG_pinmap[Copy_u8DisplayID].SEGD_pin , GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 3));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGE_port , SEG_pinmap[Copy_u8DisplayID].SEGE_pin , GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 4));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGF_port , SEG_pinmap[Copy_u8DisplayID].SEGF_pin , GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 5));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGG_port , SEG_pinmap[Copy_u8DisplayID].SEGG_pin , GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 6));
	}
	else if (SEG_pinmap[Copy_u8DisplayID].Mode == COMMON_ANODE)
	{
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGA_port , SEG_pinmap[Copy_u8DisplayID].SEGA_pin , ~GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 0));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGB_port , SEG_pinmap[Copy_u8DisplayID].SEGB_pin , ~GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 1));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGC_port , SEG_pinmap[Copy_u8DisplayID].SEGC_pin , ~GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 2));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGD_port , SEG_pinmap[Copy_u8DisplayID].SEGD_pin , ~GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 3));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGE_port , SEG_pinmap[Copy_u8DisplayID].SEGE_pin , ~GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 4));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGF_port , SEG_pinmap[Copy_u8DisplayID].SEGF_pin , ~GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 5));
		DIO_WrtPin(SEG_pinmap[Copy_u8DisplayID].SEGG_port , SEG_pinmap[Copy_u8DisplayID].SEGG_pin , ~GET_BIT(SEG_DataNumber[Copy_u8DisplayNumber] , 6));

	}
}
