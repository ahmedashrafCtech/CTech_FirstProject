
#ifndef DIO_REG_H
#define DIO_REG_H

/* DIO registers mapping */

/* Special function I/O register */
#define			DIO_SFIOR_REG		*((volatile u8*)(0x50))

/* setting registers of PORTA */
#define			DIO_PORTA_REG		*((volatile u8*)(0x3B))
#define			DIO_DDRA_REG		*((volatile u8*)(0x3A))
#define			DIO_PINA_REG		*((volatile u8*)(0x39))

/* setting registers of PORTB */
#define			DIO_PORTB_REG		*((volatile u8*)(0x38))
#define			DIO_DDRB_REG		*((volatile u8*)(0x37))
#define			DIO_PINB_REG		*((volatile u8*)(0x36))

/* setting registers of PORTC */
#define			DIO_PORTC_REG		*((volatile u8*)(0x35))
#define			DIO_DDRC_REG		*((volatile u8*)(0x34))
#define			DIO_PINC_REG		*((volatile u8*)(0x33))

/* setting registers of PORTD */
#define			DIO_PORTD_REG		*((volatile u8*)(0x32))
#define			DIO_DDRD_REG		*((volatile u8*)(0x31))
#define			DIO_PIND_REG		*((volatile u8*)(0x30))



/* Pins in Special function I/O register */
/* Pull up disable pin */
#define			DIO_SFIOR_PUD		0x02U
















#endif
