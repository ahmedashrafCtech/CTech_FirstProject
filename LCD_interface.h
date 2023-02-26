
/*preprocessor header file guard*/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


/*************************interfacing macros******************************/


/*************************Functions' prototypes*******************************/


/*this function is to send a command to us of lcd*/
void LCD_voidSendCmd(u8 Copy_u8Command);

/*this function is to send data to get displayed over lcd*/
void LCD_voidSendData(u8 Copy_u8Data);

/*this function is to initialize the LCD*/
void LCD_voidInit8Bit(void);





#endif
