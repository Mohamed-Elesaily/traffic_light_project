#include"GPIO.h"
uint8_t DIO_read(volatile uint8_t* PORT,uint8_t PIN){
    return READ_PIN(*PORT,PIN);  
}
void DIO_write(volatile uint8_t* PORT,uint8_t PIN, uint8_t value){
    if(value == HIGH){
        SET_PIN(*PORT,PIN);
    }else{
        CLR_PIN(*PORT,PIN);
    }
}
void DIO_toggle(volatile uint8_t* PORT,uint8_t PIN){
    TOGGLE_PIN(*PORT,PIN);
}
void DIO_direction(volatile uint8_t* DDR,uint8_t PIN, uint8_t value){
    if(value == OUT){
        SET_PIN(*DDR,PIN);
    }else{
        CLR_PIN(*DDR,PIN);
    }
}