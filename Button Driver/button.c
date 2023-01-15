/*
 * button.c
 *
 * Created: 08/01/2023 01:20:24 م
 *  Author: Ahmad
 */ 
#include "button.h"

void BUTTON_INIT(uint8_t buttonPort, uint8_t ButtonPin)
{
	DIO_INIT(buttonPort, ButtonPin, IN);
}

void BUTTON_READ(uint8_t buttonPort, uint8_t ButtonPin, uint8_t *value)
{
	DIO_READ(buttonPort, ButtonPin, value);
}