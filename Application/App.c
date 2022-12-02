#include"App.h"

EN_STATE next_state,prev_state;
EN_STATE state;
EN_BUTTON button_s = Not_Pressed;

EN_Super_State S_state,S_state_next;
void app_init(){
    LED_init();
    Button_init();
    INT_init();
    state = green;
    S_state = normal;

}

void app_start(){

switch (S_state)
{
case normal:
    normal_state();
    break;
case pedestrian:
    pedestrian_state();
    break;
default:
    break;
}

S_state = S_state_next;
}
void normal_state(){
     uint8_t count = 0;
    switch (state)
{
case green:
    traffic_light(green);
    _delay_ms(TIME);
    next_state = yellow; 
     prev_state = green;
    if(button_s == Pressed){
        _delay_ms(100);
        next_state = p_2;
        button_s = Not_Pressed;
        S_state_next = pedestrian;
    } 
    break;
case yellow:
    while(count <10){
   traffic_light(yellow);
    _delay_ms(TIME/10);
    count++;
    if(button_s == Pressed){
        count = 0;
        break;
    }
    }
 
    if(prev_state == red){
        next_state = green; 
     
    }
    else {
     next_state = red;   
     
    }
    prev_state = yellow;
    if(button_s == Pressed){
        _delay_ms(100);
        next_state = p_3;
        button_s = Not_Pressed;
        S_state_next = pedestrian;
    } 
    break;
case red:
    traffic_light(red);
    _delay_ms(TIME);
    next_state = yellow; 
    prev_state = red;
    if(button_s == Pressed){
         _delay_ms(100);  
        next_state = p_1;
        button_s = Not_Pressed;
        S_state_next = pedestrian;
    } 
    break;

default:
    break;
}
state = next_state;
}

void pedestrian_state(){
uint8_t count = 0;
switch (state)
{
case p_1: //car red one
    pedestrian_light(Green);
     _delay_ms(TIME);
     next_state = p_4;
    break;
case p_2: // car green on
    pedestrian_light(Red);
     _delay_ms(TIME);
    while(count <10){
    traffic_light(yellow);
    pedestrian_light(Yellow);
    _delay_ms(TIME/10);
    count++;
    
    }
    count = 0;
 
     pedestrian_light(Green);
     traffic_light(Red);
    _delay_ms(TIME);
    next_state = p_4;
    break;
case p_3: // car yellow on
  while(count <10){
    traffic_light(yellow);
    pedestrian_light(Yellow);
    _delay_ms(TIME/10);
    count++;
    
    }
    count = 0;
     pedestrian_light(Green);
     traffic_light(Red);
    _delay_ms(TIME);
    next_state = p_4;
    break;
case p_4: 
    traffic_start();
    next_state = green;
    S_state_next = normal;
break;
default:
    break;
}
S_state = S_state_next;
state = next_state;
}



void traffic_start(){
 
    LED_off(G_t);
    LED_off(Y_t);
    LED_off(R_t);

    LED_off(G_d);
    LED_off(Y_d);
    LED_off(R_d);
}

void traffic_light(EN_traffic light){
    if(light == Green){
        LED_on(G_t);
        LED_off(Y_t);
        LED_off(R_t);
    }else if(light == Yellow){
        LED_toggle(Y_t);
        LED_off(G_t);
        LED_off(R_t);
    }else if(light == Red){
        LED_on(R_t);
        LED_off(G_t);
        LED_off(Y_t);
    }
}

void pedestrian_light(EN_traffic light){
    if(light == Green){
        LED_on(G_d);
        LED_off(Y_d);
        LED_off(R_d);
    }else if(light == Yellow){
        LED_toggle(Y_d);
        LED_off(G_d);
        LED_off(R_d);
    }
    else if(light == Red){
        LED_on(R_d);
        LED_off(Y_d);
        LED_off(G_d);
    }
    else{

        traffic_start();
    
    }
}
