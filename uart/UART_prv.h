/*******************************************************************************
 *
 *  Coretech-Innovations Copyright (C) 2023
 *
 *  Project
 *		AVR-Kit-SelfTest
 *
 *   Description 
 *		Private header file for UART module
 *
 ******************************************************************************/

#ifndef UART_PRV_H
#define	UART_PRV_H

/* --------------------------- PRIVATE DATA TYPES --------------------------- */


/* --------------------------- PRIVATE DATA --------------------------------- */
/*
 * Data Description: Baud rate depends on U2X for 9600 bps
 */
#if	(UART_U2X == UART_ENABLE)

#define		UART_UBRR		103

#else

#define		UART_UBRR		53

#endif
 
/* --------------------------- PRIVATE PROTOTYPES --------------------------- */ 
/*
 * Function Description
 *
 * Parameter Name	Parameter Description
 *
 * Return Type	    Return Decription
 */

 
/* --------------------------- CONFIGURATION OPTIONS ------------------------ */ 


/* --------------------------- REGISTERS ------------------------------------ */
/*
 * Register Description: USART I/O data register
 */
#define		UART_UDR_REG		*((volatile u8*)(0x2C))

/*
 * Register Description: USART Control and status register A
 */
#define		UART_UCSRA_REG		*((volatile u8*)(0x2B))

#define		UART_UCSRA_MPCM		0x00
#define		UART_UCSRA_U2X		0x01
#define		UART_UCSRA_PE		0x02
#define		UART_UCSRA_DOR		0x03
#define		UART_UCSRA_FE		0x04
#define		UART_UCSRA_UDRE		0x05
#define		UART_UCSRA_TXC		0x06
#define		UART_UCSRA_RXC		0x07

/*
 * Register Description: USART Control and status register B
 */
#define		UART_UCSRB_REG		*((volatile u8*)(0x2A))

#define		UART_UCSRB_TXB8		0x00
#define		UART_UCSRB_RXB8		0x01
#define		UART_UCSRB_UCSZ2	0x02
#define		UART_UCSRB_TXEN		0x03
#define		UART_UCSRB_RXEN		0x04
#define		UART_UCSRB_UDRIE	0x05
#define		UART_UCSRB_TXCIE	0x06
#define		UART_UCSRB_RXCIE	0x07

/*
 * Register Description: USART Control and status register C
 */
#define		UART_UCSRC_REG		*((volatile u8*)(0x40))

#define		UART_UCSRC_UCPOL	0x00
#define		UART_UCSRC_UCSZ0	0x01
#define		UART_UCSRC_UCSZ1	0x02
#define		UART_UCSRC_USBS		0x03
#define		UART_UCSRC_UPM0		0x04
#define		UART_UCSRC_UPM1		0x05
#define		UART_UCSRC_UMSEL	0x06
#define		UART_UCSRC_URSEL	0x07


/*
 * Register Description: USART Baud Rate register UBRRH
 */
#define		UART_UBRRH_REG		*((volatile u8*)(0x40))

#define		UART_UBRRH_UBRR		0x00
#define		UART_UBRRH_URSEL	0x01

/*
 * Register Description: USART Baud Rate register UBRRL
 */
#define		UART_UBRRL_REG		*((volatile u8*)(0x29))




#endif
