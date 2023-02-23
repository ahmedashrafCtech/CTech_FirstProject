/*
 * SSD_private.h
 *
 *  Created on: Feb 23, 2023
 *      Author: Osama.Mahmoud
 */

#ifndef SSD_PRIVATE_H_
#define SSD_PRIVATE_H_


typedef struct{

	u8 Mode;
	u8 SEGA_port;
	u8 SEGA_pin;
	u8 SEGB_port;
	u8 SEGB_pin;
	u8 SEGC_port;
	u8 SEGC_pin;
	u8 SEGD_port;
	u8 SEGD_pin;
	u8 SEGE_port;
	u8 SEGE_pin;
	u8 SEGF_port;
	u8 SEGF_pin;
	u8 SEGG_port;
	u8 SEGG_pin;

}SEG_PINMAP;

extern SEG_PINMAP    SEG_pinmap[Copy_u8SEGNumber];

#endif /* SSD_PRIVATE_H_ */
