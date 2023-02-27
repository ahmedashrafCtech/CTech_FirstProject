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
	
	#if( SPI_DATA_ORDER  == SPI_DATA_ORDER_LSB_FIRST)
	SET_BIT(SPCR_REG, DORD_BIT);
	#else
	CLR_BIT(SPCR_REG, DORD_BIT);
	#endif
	//clk polarity
	#if(SPI_CLK_POL  ==  SPI_CLK_POL_IDLE_LOW)
	CLR_BIT(SPCR_REG,CPOL_BIT);
	#else
	SET_BIT(SPCR_REG,CPOL_BIT);
	#endif
	//clk phase
	#if(SPI_CLK_PHASE  ==  SPI_CLK_PHASE_SAMPLE_FIRST)
	CLR_BIT(SPCR_REG, CPHA_BIT);
	#else
	SET_BIT(SPCR_REG, CPHA_BIT);
	#endif
	//speed mode
	#if(SPI_SPEED_MODE   == SPI_SPEED_MODE_NORMAL)
	CLR_BIT(SPSR_REG , SPI2X_BIT);
	#else
	SET_BIT(SPSR_REG , SPI2X_BIT);
	#endif
	//prescaler
	SPCR_REG &= SPI_PRESCALER_MASK;
	SPCR_REG |= SPI_PRESCALER ;
	//enable SPI and enable Master mode
	SPCR_REG = (1<<SPE_BIT)|(1<<MSTR_BIT);
}

void SPI_vidSlaveInit(void)
{
	
	//data order
	#if( SPI_DATA_ORDER  == SPI_DATA_ORDER_LSB_FIRST)
		SET_BIT(SPCR_REG, DORD_BIT);
	#else
		CLR_BIT(SPCR_REG, DORD_BIT);
	#endif
	//clk polarity
	#if(SPI_CLK_POL  ==  SPI_CLK_POL_IDLE_LOW)
		CLR_BIT(SPCR_REG,CPOL_BIT);
	#else
		SET_BIT(SPCR_REG,CPOL_BIT);
	#endif
	//clk phase
	#if(SPI_CLK_PHASE  ==  SPI_CLK_PHASE_SAMPLE_FIRST)
		CLR_BIT(SPCR_REG, CPHA_BIT);
	#else
		SET_BIT(SPCR_REG, CPHA_BIT);
	#endif
	//enable SPI and enable slave mode
	SPCR_REG = (1<<SPE_BIT);
	CLR_BIT(SPCR_REG , MSTR_BIT);
}
u8   SPI_u8TransferByte(u8 Copy_u8Data)
{
	/* Start transmission */
	SPDR_REG = Copy_u8Data;
	/* Wait for transmission complete */
	while(!(SPSR_REG & (1<<SPIF_BIT)));
	
}
u8 SPI_u8SlaveReceive(void)
{
	/* Wait for reception complete */
	while(!(SPSR_REG & (1<<SPIF_BIT)));
	
	/* Return data register */
	return SPDR_REG;
}
