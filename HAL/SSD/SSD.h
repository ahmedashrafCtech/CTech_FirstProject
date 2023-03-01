/*
 * SSD.h
 *
 *  Created on: Feb 23, 2023
 *      Author: Osama.Mahmoud
 */

#ifndef SSD_H_
#define SSD_H_


#include "DIO.h"



#include "SSD_cfg.h"
#include "SSD_private.h"



#define COMMON_CATHODE     0
#define COMMON_ANODE       1

void SEG_voidInit(u8 Copy_u8DisplayID);
void SSD_voidDisplayNumber(u8 Copy_u8DisplayID , u8 Copy_u8DisplayNumber);


#endif /* SSD_H_ */
