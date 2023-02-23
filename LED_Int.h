/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 21 FEB 2023                   */
/********************************************/


#ifndef LED_INT_H
#define LED_INT_H

#define ON_TIME    1000
#define OFF_TIME   1000

void HLED_vidLedInit(void);
void HLED_vidLedON(u8 LED_PORT,u8 LED_PIN);
void HLED_vidLedOFF(u8 LED_PORT,u8 LED_PIN);
void HLED_vidLedTogg(u8 LED_PORT,u8 LED_PIN);
void HLED_vidLedBlink(u8 LED_PORT,u8 LED_PIN);

#endif //LED_INT_H