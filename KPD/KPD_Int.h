/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 26 FEB 2023                   */
/********************************************/


#ifndef KPD_INT_H
#define KPD_INT_H

#define NOT_PRESSED   255
#define PRESSED       0

void HKPD_vidKpdInit(void);
u8   HKPD_vidKpdRead(void);

#endif //KPD_INT_H
