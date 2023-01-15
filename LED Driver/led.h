/*
 * led.h
 *
 * Created: 08/01/2023 10:55:13 ص
 *  Author: Ahmad
 */ 


#ifndef LED_H_
#define LED_H_

#include "../DIO Driver/dio.h"

void LED_INIT(uint8_t ledPort, uint8_t ledPin); 
void LED_ON(uint8_t ledPort, uint8_t ledPin);
void LED_OFF(uint8_t ledPort, uint8_t ledPin);
void LED_TOGGLE(uint8_t ledPort, uint8_t ledPin);



#endif /* LED_H_ */