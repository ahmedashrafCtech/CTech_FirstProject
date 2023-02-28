/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 27 FEB 2023                   */
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "SPI_Private.h"
#include "SPI_Config.h"
#include "SPI_Int.h"

void SPI_vidMasterInit(void)
{
	DIO_SetDir(PortB,Pin5,Pin_Output);
	DIO_SetDir(PortB,Pin7,Pin_Output);
	DIO_SetDir(PortB,Pin4,Pin_Output);
	#if( SPI_DATA_ORDER  == SPI_DATA_ORDER_LSB_FIRST)
	WRITE_BIT(SPCR_REG, DORD_BIT,1);
	#else
	WRITE_BIT(SPCR_REG, DORD_BIT,0);
	#endif
	//clk polarity
	#if(SPI_CLK_POL  ==  SPI_CLK_POL_IDLE_LOW)
	WRITE_BIT(SPCR_REG,CPOL_BIT,0);
	#else
	WRITE_BIT(SPCR_REG,CPOL_BIT,1);
	#endif
	//clk phase
	#if(SPI_CLK_PHASE  ==  SPI_CLK_PHASE_SAMPLE_FIRST)
	WRITE_BIT(SPCR_REG, CPHA_BIT,0);
	#else
	WRITE_BIT(SPCR_REG, CPHA_BIT,1);
	#endif
	//speed mode
	#if(SPI_SPEED_MODE   == SPI_SPEED_MODE_NORMAL)
	WRITE_BIT(SPSR_REG , SPI2X_BIT,0);
	#else
	WRITE_BIT(SPSR_REG , SPI2X_BIT,1);
	#endif
	//prescaler
	SPCR_REG &= SPI_PRESCALER_MASK;
	SPCR_REG |= SPI_PRESCALER ;
	//enable SPI and enable Master mode
	SPCR_REG = (1<<SPE_BIT)|(1<<MSTR_BIT);
}

void SPI_vidSlaveInit(void)
{
	DIO_SetDir(PortB,Pin6,Pin_Output);
	//data order
	#if( SPI_DATA_ORDER  == SPI_DATA_ORDER_LSB_FIRST)
	WRITE_BIT(SPCR_REG, DORD_BIT,1);
	#else
	WRITE_BIT(SPCR_REG, DORD_BIT,0);
	#endif
	//clk polarity
	#if(SPI_CLK_POL  ==  SPI_CLK_POL_IDLE_LOW)
	WRITE_BIT(SPCR_REG,CPOL_BIT,0);
	#else
	WRITE_BIT(SPCR_REG,CPOL_BIT,1);
	#endif
	//clk phase
	#if(SPI_CLK_PHASE  ==  SPI_CLK_PHASE_SAMPLE_FIRST)
	WRITE_BIT(SPCR_REG, CPHA_BIT,0);
	#else
	WRITE_BIT(SPCR_REG, CPHA_BIT,1);
	#endif
	//enable SPI and enable slave mode
	SPCR_REG = (1<<SPE_BIT);
	WRITE_BIT(SPCR_REG , MSTR_BIT,0);
}
u8   SPI_u8TransferByte(u8 Copy_u8Data)
{
	/* Start transmission */
	SPDR_REG = Copy_u8Data;
	/* Wait for transmission complete */
	while(!(SPSR_REG & (1<<SPIF_BIT)));
	
	return SPDR_REG ;

}
u8 SPI_u8SlaveReceive(void)
{
	/* Wait for reception complete */
	while(!(SPSR_REG & (1<<SPIF_BIT)));
	
	/* Return data register */
	return SPDR_REG;
}
