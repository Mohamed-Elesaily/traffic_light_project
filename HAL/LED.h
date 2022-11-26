#ifndef LED_H
#define LED_H
#include"../STD/types.h"
#include"../MCAL/GPIO.h"
#include <util/delay.h>
typedef enum EN_LED{
G_t, Y_t, R_t, G_d, Y_d, R_d
}EN_LED;



void LED_init();

void LED_on(EN_LED LED);

void LED_off(EN_LED LED);

void LED_toggle(EN_LED LED);

void LED_Test();
#endif