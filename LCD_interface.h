
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

/*this function is to clear the whole display and return DDRAM to H00*/
void LCD_voidClearDisplay(void);

/*this function is to send a full string*/
void LCD_voidSendString(char * Copy_ptrString);

/*this function is to start typing from a certain cell of the LCD*/
void LCD_voidGoTo(u8 Copy_u8Row , u8 Copy_u8Column);

/*this function is to display a certain number*/
void LCD_voidSendNumber(u32 Copy_u32DisplayedNumber);




#endif
