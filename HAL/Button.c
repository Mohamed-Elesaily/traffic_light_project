#include"Button.h"

void Button_init(){
    DIO_direction(DDR_D,PIN2,IN);
}

EN_BUTTON Button(){
    return DIO_read(PIN_D,PIN2);
}

