/*
 * button.h
 *
 * Created: 08/01/2023 01:20:45 م
 *  Author: Ahmad
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../DIO Driver/dio.h"

#define BUTTON_1_PORT PORT_B
#define BUTTON_1_PIN 0

#define LOW 0
#define HIGH 1


void BUTTON_INIT(uint8_t buttonPort, uint8_t ButtonPin);

void BUTTON_READ(uint8_t buttonPort, uint8_t ButtonPin, uint8_t *value);



#endif /* BUTTON_H_ */