#ifndef STD_H
#define STD_H

#define SET_PIN(PORT,PIN) (PORT |= 1<<PIN)
#define CLR_PIN(PORT,PIN) (PORT &= ~(1<<PIN))
#define READ_PIN(PORT,PIN) ((PORT&(1<<PIN))>>PIN)
#define TOGGLE_PIN(PORT,PIN) ((PORT ^= (1<<PIN)))

#endif