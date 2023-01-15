/*
 * timer.h
 *
 * Created: 12/01/2023 12:12:39 ص
 *  Author: Ahmad
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "avr/io.h"
#include "../LED Driver/led.h"

void TIMER_INT(void);
void TIMER_START(uint8_t *normal);
void YELLOW_TIMER_START(uint8_t *normal, uint8_t *on);
void TIMER_BUTTON(void);


#endif /* TIMER_H_ */