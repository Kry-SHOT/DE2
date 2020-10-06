/*
 * knight_rider.c
 *
 * Created: 06.10.2020 13:36:31
 * Author : krystof michal
 */ 

/* Defines -----------------------------------------------------------*/
#define LED_1	PC0
#define LED_2	PC1
#define LED_3	PC2
#define LED_4	PC3
#define LED_5	PC4
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
	//setup LEDs
	
	DDRC = DDRC | (1<<LED_1);
	PORTC = PORTC & ~(1<<LED_1); //active when set to 0
	DDRC = DDRC | (1<<LED_2);
	PORTC = PORTC & ~(1<<LED_2); //active when set to 0
	DDRC = DDRC | (1<<LED_3);
	PORTC = PORTC & ~(1<<LED_3); //active when set to 0
	DDRC = DDRC | (1<<LED_4);
	PORTC = PORTC & ~(1<<LED_4); //active when set to 0
	DDRC = DDRC | (1<<LED_5);
	PORTC = PORTC & ~(1<<LED_5); //active when set to 0
	
	DDRD = DDRD & ~(1<<BUTTON); //set input
	PORTD = PORTD | (1<<BUTTON);//enable internal pull-up
    // Infinite loop
    while (1)
    {
		if(bit_is_clear(PIND, BUTTON))
		{
		PORTC = PORTC ^ (1<<LED_1);
		_delay_ms(BLINK_DELAY);
		PORTC = PORTC ^ (1<<LED_1);
		PORTC = PORTC ^ (1<<LED_2);
		_delay_ms(BLINK_DELAY);
		PORTC = PORTC ^ (1<<LED_2);
		PORTC = PORTC ^ (1<<LED_3);
		_delay_ms(BLINK_DELAY);
		PORTC = PORTC ^ (1<<LED_3);
		PORTC = PORTC ^ (1<<LED_4);
		_delay_ms(BLINK_DELAY);
		PORTC = PORTC ^ (1<<LED_4);
		PORTC = PORTC ^ (1<<LED_5);
		_delay_ms(BLINK_DELAY);
		PORTC = PORTC ^ (1<<LED_5);
		PORTC = PORTC ^ (1<<LED_4);
		_delay_ms(BLINK_DELAY);
		PORTC = PORTC ^ (1<<LED_4);
		PORTC = PORTC ^ (1<<LED_3);
		_delay_ms(BLINK_DELAY);
		PORTC = PORTC ^ (1<<LED_3);
		PORTC = PORTC ^ (1<<LED_2);
		_delay_ms(BLINK_DELAY);
		PORTC = PORTC ^ (1<<LED_2);				
		}
    }

    // Will never reach this
    return 0;
}

