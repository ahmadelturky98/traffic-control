/*
 * timer.c
 *
 * Created: 12/01/2023 12:12:29 ص
 *  Author: Ahmad
 */ 

#include "timer.h"
#define NUMBER_OF_OVERFLOWS 350
unsigned int overflowCounter = 0;

void TIMER_INT(void)
{
	TCCR0 = 0x00; //Normal mode
	TCNT0 = 0x00; //Time set initial value
}

void TIMER_START(uint8_t *normal)
{
	overflowCounter = 0;
	TCCR0 = (1<<CS02) | (1<<CS00);
	
	while(overflowCounter < NUMBER_OF_OVERFLOWS)
	{
		while((TIFR & (1<<0)) == 0);
		TIFR |= (1<<0);
		overflowCounter++;
		if(*normal == 0)
		{
			break;
		}
	}
	TCCR0 = 0x00;
	
}

void YELLOW_TIMER_START(uint8_t *normal, uint8_t *on)
{
	overflowCounter = 0;
	TCCR0 = (1<<CS02) | (1<<CS00);
	while(overflowCounter < NUMBER_OF_OVERFLOWS)
	{
		if(overflowCounter % 70 == 0)
		{
			LED_TOGGLE(PORT_A, 1);
			if(*on == 1)
			{
				LED_TOGGLE(PORT_B, 1);
			}
			//
		}
		
		while((TIFR & (1<<0)) == 0);
		TIFR |= (1<<0);
		overflowCounter++;
		if(*normal == 0)
		{
			break;
		}
	}
	*on = 0;
	TCCR0 = 0x00;
}

void TIMER_BUTTON(void)
{
	overflowCounter = 0;
	TCCR0 = (1<<CS02) | (1<<CS00);
	
	while(overflowCounter < 40)
	{
		while((TIFR & (1<<0)) == 0);
		TIFR |= (1<<0);
		overflowCounter++;
		
	}
	TCCR0 = 0x00;	
}