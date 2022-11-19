#ifndef GPIO_H
#define GPIO_H
#include "../STD/types.h"
#include "../STD/STD_lib.h"
// PORTA
#define PORT_A ((volatile uint8_t *)(0x3B))
#define DDR_A ((volatile uint8_t *)(0x3A))
#define PIN_A ((volatile uint8_t *)(0x39))
// PORTB
#define PORT_B ((volatile uint8_t *)(0x38))
#define DDR_B ((volatile uint8_t *)(0x37))
#define PIN_B ((volatile uint8_t *)(0x36))

// PORTD
#define PORT_D ((volatile uint8_t *)(0x32))
#define DDR_D ((volatile uint8_t *)(0x31))
#define PIN_D ((volatile uint8_t *)(0x30))

// PIN
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define HIGH 1
#define LOW 0

#define IN 0
#define OUT 1
uint8_t DIO_read(volatile uint8_t* PORT,uint8_t PIN);
void DIO_write(volatile uint8_t* PORT,uint8_t PIN, uint8_t value);
void DIO_toggle(volatile uint8_t* PORT,uint8_t PIN);
void DIO_direction(volatile uint8_t* DDR,uint8_t PIN, uint8_t value);
#endif