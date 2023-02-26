
/*preprocessor header file guard*/
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

/**************private macros*************/

/*data is sent in 8-bit mode , 2 lines are displayed*/
#define FUNCTION_SET                0b00111000

/*cursor displays , no blinking characters*/
#define DISPLAY_ON_OFF_CTRL         0b00001110

/*clear all display and sets DDRAM address to 00H*/
#define DISPLAY_CLEAR               0b00000001

/*cursor moves to the right and the display is fixed*/
#define ENTRY_SET_MODE              0b00000110
#endif
