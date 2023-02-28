/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 27 FEB 2023                   */
/********************************************/


#ifndef SPI_INT_H
#define SPI_INT_H


void SPI_vidMasterInit(void);
void SPI_vidSlaveInit(void);
u8   SPI_u8TransferByte(u8 Copy_u8Data);
u8 	 SPI_u8SlaveReceive(void);

#endif //SPI_INT_H
