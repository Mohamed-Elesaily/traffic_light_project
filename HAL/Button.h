#ifndef BUTTON_H
#define BUTTON_H
#include"../MCAL/GPIO.h"
typedef enum EN_BUTTON{
    Pressed, Not_Pressed
}EN_BUTTON;
void Button_init();

EN_BUTTON Button(); 


#endif