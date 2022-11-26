#include"LED.h"

void LED_init(){
    DIO_direction(DDR_A,PIN0,OUT);
    DIO_direction(DDR_A,PIN1,OUT);
    DIO_direction(DDR_A,PIN2,OUT);

    DIO_direction(DDR_B,PIN0,OUT);
    DIO_direction(DDR_B,PIN1,OUT);
    DIO_direction(DDR_B,PIN2,OUT);
    
}

void LED_on(EN_LED LED){
    if(LED == G_t) DIO_write(PORT_A,PIN0,HIGH);
    else if(LED == Y_t) DIO_write(PORT_A,PIN1,HIGH);
    else if(LED == R_t) DIO_write(PORT_A,PIN2,HIGH);
    else if(LED == G_d) DIO_write(PORT_B,PIN0,HIGH);
    else if(LED == Y_d) DIO_write(PORT_B,PIN1,HIGH);
    else if(LED == R_d) DIO_write(PORT_B,PIN2,HIGH);
}

void LED_off(EN_LED LED){
    if(LED == G_t) DIO_write(PORT_A,PIN0,LOW);
    else if(LED == Y_t) DIO_write(PORT_A,PIN1,LOW);
    else if(LED == R_t) DIO_write(PORT_A,PIN2,LOW);
    else if(LED == G_d) DIO_write(PORT_B,PIN0,LOW);
    else if(LED == Y_d) DIO_write(PORT_B,PIN1,LOW);
    else if(LED == R_d) DIO_write(PORT_B,PIN2,LOW);
}

void LED_toggle(EN_LED LED){
    if(LED == G_t) DIO_toggle(PORT_A,PIN0);
    else if(LED == Y_t) DIO_toggle(PORT_A,PIN1);
    else if(LED == R_t) DIO_toggle(PORT_A,PIN2);
    else if(LED == G_d) DIO_toggle(PORT_B,PIN0);
    else if(LED == Y_d) DIO_toggle(PORT_B,PIN1);
    else if(LED == R_d) DIO_toggle(PORT_B,PIN2);
}


void LED_Test(){
    LED_init();
    LED_on(G_d);
    _delay_ms(1000);
    LED_off(G_d);
    _delay_ms(1000);
    LED_toggle(G_d);
    _delay_ms(1000);
    LED_toggle(G_d);
    _delay_ms(1000);
}