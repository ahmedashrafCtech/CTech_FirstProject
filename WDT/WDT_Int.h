/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 27 FEB 2023                   */
/********************************************/

#ifndef WDT_INT_H
#define WDT_INT_H

#define WDT_TIME_16ms3      0
#define WDT_TIME_32ms5      1
#define WDT_TIME_65ms       2
#define WDT_TIME_130ms      3
#define WDT_TIME_260ms      4
#define WDT_TIME_520ms      5
#define WDT_TIME_1s         6
#define WDT_TIME_2s1        7

void WDT_vidStart( u8 );
void WDT_vidRefresh(void);
void WDT_vidStop(void);


#endif //WDT_INT_H
