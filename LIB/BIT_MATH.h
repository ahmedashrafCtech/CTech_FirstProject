//Header File Guard 
#ifndef BIT_MATH_H_ 
#define BIT_MATH_H_ 
  
#define WRITE_BIT(VAR,BIT,VALUE)		(VAR = (VALUE<<BIT) | (VAR&~(1<<BIT)))
 
#define TOGGLE_BIT(VAR,BIT_NUM)       (VAR^=(1<<BIT_NUM)) 
  
#define GET_BIT(VAR,BIT_NUM)            ((VAR>>BIT_NUM)&1) 
  
#endif
