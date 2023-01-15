/*
 * app.c
 *
 * Created: 08/01/2023 12:20:26 م
 *  Author: Ahmad
 */ 
#include "app.h"
#include <avr/interrupt.h>
#define F_CPU 1000000
#include <util/delay.h>


uint8_t car_state = 0;
uint8_t normal_mode = 1;
uint8_t pedestrian_yellow = 0;
uint8_t stop_press = 0;
void APP_INIT(void)
{
	//Three LEDs for cars - Green, Yellow, and Red, connected on port A, pins 0, 1, and 2	BUTTON_INIT(PORT_D, 2);		//INITLIAZE CAR LIGHTS	LED_INIT(PORT_A, 0);	LED_INIT(PORT_A, 1);	LED_INIT(PORT_A, 2);		//INITLIAZE PED. LIGHTS	LED_INIT(PORT_B, 0);	LED_INIT(PORT_B, 1);	LED_INIT(PORT_B, 2);		TIMER_INT();
	
	//INITLIAZE INTERRUPTS
	sei();
	MCUCR |= (1<<ISC00) | (1<<ISC01);
	GICR |= (1<<INT0);
}

void APP_START(void)
{		
	if(normal_mode == 1) //CAR MODE
	{
		switch (car_state)
		{
			case 0:	//CAR GREEN LIGHT
				LED_ON(PORT_B, 2); //PED. RED ON
				LED_ON(PORT_A, 0); //CAR GREEN ON
				TIMER_START(&normal_mode); //FIVE SEC TIMER
				car_state = 1; //YELLOW STATE
			break;
			/****************************************************************************************/
			
			case 1: //CAR YELLOW LIGHT
				LED_OFF(PORT_A, 0); //CAR GREEN OFF
				LED_OFF(PORT_B, 2); //PED. RED OFF
				pedestrian_yellow = 1; //ENABLE PED. YELLOW
				YELLOW_TIMER_START(&normal_mode, &pedestrian_yellow); //FIVE SEC TIMER & YELLOW BLINK
				LED_OFF(PORT_A, 1); //CAR YELLOW OFF
				LED_OFF(PORT_B, 1); //PED. YELLOW OFF
				car_state = 2; //RED STATE
			break;
			/****************************************************************************************/
			
			case 2: //CAR RED LIGHT
				LED_ON(PORT_A, 2); //CAR RED ON
				
				LED_OFF(PORT_B, 2); //PED. RED OFF
				LED_ON(PORT_B, 0); //PED. GREEN ON
				
				TIMER_START(&normal_mode); //FIVE SEC TIMER
				stop_press = 0; //ENABLE INT
				car_state = 3; //YELLOW STATE
			break;
			/****************************************************************************************/
			
			case 3: //CAR YELLOW LIGHT
				LED_OFF(PORT_A, 2); //CAR RED OFF
				pedestrian_yellow = 1; //ENABLE PED. YELLOW
				YELLOW_TIMER_START(&normal_mode, &pedestrian_yellow); //FIVE SEC TIMER & YELLOW BLINK
				LED_OFF(PORT_A, 1); //CAR YELLOW OFF
				LED_OFF(PORT_B, 1); //PED. YELLOW OFF
				LED_OFF(PORT_B, 0); //PED. GREEN OFF
				LED_ON(PORT_B, 2); //PED. RED ON
				car_state = 0; //GREEN STATE
			break;
			/****************************************************************************************/
			
			default:
			break;
		}
	}
	
	else if(normal_mode == 0) //PED. MODE
	{
		switch(car_state)
		{
			case 0: //CAR YELLOW TO GREEN STATE
				LED_OFF(PORT_B, 2); //PED. RED OFF
				pedestrian_yellow = 1; //ENABLE PED. YELLOW
				normal_mode = 1; //ENABLE TIMER
				YELLOW_TIMER_START(&normal_mode, &pedestrian_yellow); //FIVE SEC TIMER & YELLOW BLINK
			
				LED_OFF(PORT_A, 1); //CAR YELLOW OFF
				LED_OFF(PORT_B, 1); //PED. YELLOW OFF
			
				LED_ON(PORT_A, 2); //CAR RED ON
				LED_ON(PORT_B, 0); //PED. GREEN ON
				TIMER_START(&normal_mode); ////FIVE SEC TIMER
			
				
				pedestrian_yellow = 1; //ENABLE PED. YELLOW
				car_state = 3; //YELLOW STATE
				stop_press = 0; //ENABLE INT
			break;
			/****************************************************************************************/
			
			case 1: //CAR YELLOW TO RED STATE
				LED_OFF(PORT_A, 0); //CAR GREEN OFF
				LED_OFF(PORT_B, 2); //PED. RED OFF
			
				pedestrian_yellow = 1; //ENABLE PED. YELLOW
				normal_mode = 1; //ENABLE TIMER
				YELLOW_TIMER_START(&normal_mode, &pedestrian_yellow); //FIVE SEC TIMER & YELLOW BLINK
			
				LED_OFF(PORT_A, 1); //CAR YELLOW OFF
				LED_OFF(PORT_B, 1); //PED. YELLOW OFF
			
				LED_ON(PORT_A, 2); //CAR RED ON
				LED_ON(PORT_B, 0); //PED. GREEN ON
				
				TIMER_START(&normal_mode); //FIVE SEC TIMER
				
				
				pedestrian_yellow = 1; //ENABLE PED. YELLOW
				car_state = 3; //YELLOW STATE
				stop_press = 0; //ENABLE INT
			break;
			/****************************************************************************************/
			
			case 2: //CAR GREEN ON
				LED_OFF(PORT_B, 2); //PED. RED OFF
				pedestrian_yellow = 1; //ENABLE PED. YELLOW
				
				normal_mode = 1; //ENABLE TIMER
				YELLOW_TIMER_START(&normal_mode, &pedestrian_yellow); //FIVE SEC TIMER & YELLOW BLINK
			
				LED_OFF(PORT_A, 1); //CAR YELLOW OFF
				LED_OFF(PORT_B, 1); //PED. YELLOW OFF
			
				LED_ON(PORT_A, 2); //CAR RED ON
				LED_ON(PORT_B, 0); //PED. GREEN ON
				
				TIMER_START(&normal_mode); ////FIVE SEC TIMER
				
				
				pedestrian_yellow = 1; //ENABLE PED. YELLOW
				car_state = 3; //YELLOW STATE
				stop_press = 0; //ENABLE INT
			break;
			/****************************************************************************************/
			
			case 3: //CAR RED ON
				normal_mode = 1; //ENABLE TIMER
				car_state = 2;
			break;
			/****************************************************************************************/
			
			default:
			break;
		}
		
	}		
	
}

ISR(INT0_vect)
{
	if(stop_press == 0)
	{
		normal_mode = 0; //PED. MODE
		stop_press = 1; //NO INT
		_delay_ms(500);
	}
}		
