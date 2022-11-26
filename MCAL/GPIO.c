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

void DIO_OUT_UT(){
    DIO_direction(DDR_A,PIN0,OUT);
    DIO_write(PORT_A,PIN0,HIGH);

    _delay_ms(1000);

    DIO_write(PORT_A,PIN0,LOW);
   _delay_ms(2000);
    while(1){
        DIO_toggle(PORT_A,PIN0);
          _delay_ms(500);
    }
    
}

void DIO_IN_UT(){
    DIO_direction(DDR_A,PIN0,OUT);
    
    DIO_direction(DDR_D,PIN2,IN);

    while(1){
          _delay_ms(500);
        if(READ_PIN(*PIN_D,PIN2) == 0) DIO_write(PORT_A,PIN0,HIGH);
    }
}