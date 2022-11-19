#ifndef APP_H
#define APP_H
#include <avr/interrupt.h>
#include <util/delay.h>
#include"../HAL/LED.h"
#include"../HAL/Button.h"
#include"../MCAL/INT.h"
typedef enum EN_STATE{
 green,yellow,red,p_1,p_2,p_3,p_4
}EN_STATE;
typedef enum EN_Super_State{
normal,pedestrian
}EN_Super_State;

typedef enum EN_traffic{
    Green, Yellow, Red, Start
}EN_traffic;
typedef enum EN_light{
ON,OFF,TOG
}EN_light;

extern EN_STATE next_state,prev_state;
extern EN_STATE state;
extern EN_Super_State S_state,S_state_next;
extern EN_BUTTON button_s;
void traffic_start();
void traffic_light(EN_traffic light);
void pedestrian_light(EN_traffic light);
void pedestrian_state();
void normal_state();
void app_init();
void app_start();

#endif