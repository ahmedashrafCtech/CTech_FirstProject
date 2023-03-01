/*******************************************************************************
 *
 *  Coretech-Innovations Copyright (C) 2023
 *
 *  Project
 *		AVR-Kit-SelfTest
 *
 *   Description 
 *		interface header file for UART module
 *
 ******************************************************************************/
 
/* --------------------------- PUBLIC MACROS -------------------------------- */

#define		UART_ENABLE			0x01
#define		UART_DISABLE		0x00

																			  
/* --------------------------- PUBLIC DATA TYPE ----------------------------- */																		  
																			  
/* --------------------------- PUBLIC PROTOTYPES ---------------------------- */
/*
 * Function Description
 *
 * Parameter Name	Parameter Description
 *
 * Return Type	    Return Decription
 */
void M_UART_Init(void);

void M_UART_Transmit(u8 Copy_u8Data);

u8 M_UART_Receive(void);
