/*
 * $safeprojectname$.c
 *
 * Created: 07/01/2023 03:35:14 م
 * Author : Ahmad
 */ 

//#include <avr/io.h>
//#define F_CPU 1000000U //to use delay function
//#include <util/delay.h>
//#include "registers.h"
//#include "DIO Driver/dio.h"

//#include "LED Driver/led.h"
#include "Application/app.h"


int main(void)
{
	APP_INIT();
	
	while(1)
	{
		APP_START();
	}
}

