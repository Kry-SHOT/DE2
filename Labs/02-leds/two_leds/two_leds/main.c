/*
 * two_leds.c
 *
 * Created: 30.09.2020 9:24:56
 * Author : krystof
 */

/***********************************************************************
 *
 * Alternately toggle two LEDs when a push button is pressed.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_GREEN   PB5     // AVR pin where green LED is connected
#define LED_GREEN_1	PC5
#define BUTTON		PD0
#define BLINK_DELAY 250
#ifndef F_CPU
#define F_CPU 16000000      // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions

/* Functions ---------------------------------------------------------*/
/**
 * Main function where the program execution begins. Toggle two LEDs
 * when a push button is pressed.
 */
int main(void)
{
	/* GREEN LED */
	// Set pin as output in Data Direction Register...
	DDRB = DDRB | (1<<LED_GREEN);
	// ...and turn LED off in Data Register
	PORTB = PORTB & ~(1<<LED_GREEN); //active when set to 1

	/* second LED */
	// WRITE YOUR CODE HERE
	
	DDRC = DDRC | (1<<LED_GREEN_1);
	
	PORTC = PORTC | (1<<LED_GREEN_1); //active when set to 0
	
	DDRD = DDRD & ~(1<<BUTTON); //set input
	PORTD = PORTD | (1<<BUTTON);//enable internal pull-up
	// Infinite loop
	while (1)
	{
		// Pause several milliseconds
		_delay_ms(BLINK_DELAY);

		// WRITE YOUR CODE HERE
		if(bit_is_set(PIND, BUTTON))
		{
			PORTB = PORTB ^ (1<<LED_GREEN);
			PORTC = PORTC ^ (1<<LED_GREEN_1);
		}
	}

    // Will never reach this
    return 0;
}
