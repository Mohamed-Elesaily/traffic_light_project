#include"GPIO.h"
#include"STD_lib.h"
#include <util/delay.h>
int main(){
    DIO_direction(DDRA,PIN0,OUT);
    while(1){
        DIO_toggle(PORTA,PIN0);
        _delay_ms(100000);
        
    }
return 0;
}