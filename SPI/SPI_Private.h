/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 27 FEB 2023                   */
/********************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPCR_REG  (*((volatile u8 *)0x2D))  // control
#define SPSR_REG  (*((volatile u8 *)0x2E))  // status
#define SPDR_REG  (*((volatile u8 *)0x2F))  // data

//SPCR

#define SPIE_BIT  7   // Interrupt Enable
#define SPE_BIT   6   // SPI Enable
#define DORD_BIT  5   // data order
#define MSTR_BIT  4   // master or slave
#define CPOL_BIT  3   // clock polarity
#define CPHA_BIT  2   // clock phase
#define SPR1_BIT  1   // prescaler
#define SPR0_BIT  0   // prescaler

//SPSR
#define SPIF_BIT   7  // Interrupt flag
#define WCOL_BIT   6  // write colession
#define SPI2X_BIT  0   // double speed mode

// polarity
#define  SPI_CLK_POL_IDLE_HIGH   1
#define  SPI_CLK_POL_IDLE_LOW    0

//phase

#define SPI_CLK_PHASE_SAMPLE_FIRST   0
#define SPI_CLK_PHASE_SAMPLE_LAST    1

//data order
#define  SPI_DATA_ORDER_MSB_FIRST    0
#define  SPI_DATA_ORDER_LSB_FIRST    1

// prescaler
#define  SPI_PRESCALER_DOUBLE_2       0
#define  SPI_PRESCALER_DOUBLE_8       1
#define  SPI_PRESCALER_DOUBLE_32      2
#define  SPI_PRESCALER_DOUBLE_64      3

#define  SPI_PRESCALER_NORMAL_4       0
#define  SPI_PRESCALER_NORMAL_16      1
#define  SPI_PRESCALER_NORMAL_64      2
#define  SPI_PRESCALER_NORMAL_128     3

// speed mode
#define  SPI_SPEED_MODE_NORMAL       0
#define  SPI_SPEED_MODE_DOUBLE       1


#endif //SPI_PRIVATE_H