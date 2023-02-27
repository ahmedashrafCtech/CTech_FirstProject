/*******************************************************************************
 *
 *  Coretech-Innovations Copyright (C) 2023
 *
 *  Project
 *		AVR-Kit-SelfTest
 *
 *   Description 
 *		source code file for UART module
 *
 ******************************************************************************/

/* --------------------------- INCLUDES ------------------------------------- */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_int.h"
#include "UART_cfg.h"
#include "UART_prv.h"

/* --------------------------- PRIVATE FUNCTION IMPLEMENTATION -------------- */

/* --------------------------- PUBLIC FUNCTION IMPLEMENTATION --------------- */

void M_UART_Init(void)
{
	u8 Local_u8UCSRC = 0;

#if (UART_U2X == UART_ENABLE)
	WRITE_BIT(UART_UCSRA_REG,UART_UCSRA_U2X,STD_HIGH);
#else
	WRITE_BIT(UART_UCSRA_REG,UART_UCSRA_U2X,STD_LOW);
#endif

	UART_UBRRL_REG = UART_UBRR;

	WRITE_BIT(UART_UCSRB_REG,UART_UCSRB_TXEN,STD_HIGH);
	WRITE_BIT(UART_UCSRB_REG,UART_UCSRB_RXEN,STD_HIGH);

	WRITE_BIT(Local_u8UCSRC,UART_UCSRC_URSEL,STD_HIGH);
	WRITE_BIT(Local_u8UCSRC,UART_UCSRC_UCSZ0,STD_HIGH);
	WRITE_BIT(Local_u8UCSRC,UART_UCSRC_UCSZ1,STD_HIGH);

	UART_UCSRC_REG = Local_u8UCSRC;
}

void M_UART_Transmit(u8 Copy_u8Data)
{
	while(!(GET_BIT(UART_UCSRA_REG, UART_UCSRA_UDRE)));

	UART_UDR_REG = Copy_u8Data;
}

u8 M_UART_Receive(void)
{
	while(!(GET_BIT(UART_UCSRA_REG, UART_UCSRA_RXC)));

	return UART_UDR_REG;
}










