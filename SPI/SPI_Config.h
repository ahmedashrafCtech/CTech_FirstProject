/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 27 FEB 2023                   */
/********************************************/


#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define SPI_SPEED_MODE   SPI_SPEED_MODE_NORMAL

#define SPI_PRESCALER   SPI_PRESCALER_NORMAL_16

#define SPI_CLK_POL    SPI_CLK_POL_IDLE_LOW

#define SPI_CLK_PHASE   SPI_CLK_PHASE_SAMPLE_FIRST

#define SPI_DATA_ORDER   SPI_DATA_ORDER_LSB_FIRST

#define SPI_PRESCALER_MASK    0b11111100

#endif //SPI_CONFIG_H 
