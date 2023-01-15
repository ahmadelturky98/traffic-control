/*
 * led.c
 *
 * Created: 08/01/2023 10:54:58 ص
 *  Author: Ahmad
 */ 
#include "led.h"

void LED_INIT(uint8_t ledPort, uint8_t ledPin)
{
	DIO_INIT(ledPort, ledPin,  OUT);
}

void LED_ON(uint8_t ledPort, uint8_t ledPin)
{
	DIO_WRITE(ledPort, ledPin, HIGH);
}

void LED_OFF(uint8_t ledPort, uint8_t ledPin)
{
	DIO_WRITE(ledPort, ledPin, LOW);
}

void LED_TOGGLE(uint8_t ledPort, uint8_t ledPin)
{
	DIO_TOGGLE(ledPort, ledPin);
}