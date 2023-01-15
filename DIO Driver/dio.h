/*
 * dio1.h
 *
 * Created: 07/01/2023 06:39:24 م
 *  Author: Ahmad
 */ 


#ifndef DIO1_H_
#define DIO1_H_

//#include "../Utilites/registers.h"
//#include "../Utilites/types.h"
#include "avr/io.h"

//all internal driver typedefs
//all driver macros
//all driver function prototypes

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define IN 0
#define OUT 1

#define LOW 0
#define HIGH 1

void DIO_INIT(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); //Initialize DIO direction
void DIO_WRITE(uint8_t portNumber, uint8_t pinNumber, uint8_t value);
void DIO_TOGGLE(uint8_t portNumber, uint8_t pinNumber);
void DIO_READ(uint8_t portNumber, uint8_t pinNumber, uint8_t *value);


#endif /* DIO1_H_ */