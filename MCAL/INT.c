#include"INT.h"
void INT_init(){
    	
	GICR = 1<<INT0;		
	MCUCR = 1<<ISC01 | 1<<ISC00; 
	sei();	
}
