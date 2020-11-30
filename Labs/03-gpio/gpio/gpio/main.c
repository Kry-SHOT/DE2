/*
 * main.c
 *
 * Created: 13.10.2020 10:31:21
 * Author : krystof michal
 */ 

/* Defines -----------------------------------------------------------*/
#define LED_GREEN_1   PB5     // AVR pin where green LED 1 is connected
#define LED_GREEN_2   PC5     // AVR pin where green LED 2 is connected
#define BUTTON		  PD0     // AVR pin where button is connected
#define BLINK_DELAY 500
#ifndef F_CPU
#define F_CPU 16000000      // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions
#include "gpio.h"           // GPIO library for AVR-GCC

/* Function definitions ----------------------------------------------*/
/**
 * Main function where the program execution begins. Toggle two LEDs 
 * when a push button is pressed. Functions from user-defined GPIO
 * library is used instead of low-level logic operations.
 */
int main(void)
{
    /* GREEN LED */
    GPIO_config_output(&DDRB, LED_GREEN_1); //set pin to output
    GPIO_write_low(&PORTB, LED_GREEN_1);	//set pin to 0

	/* second LED */
	GPIO_config_output(&DDRC, LED_GREEN_2); //set pin to output
	GPIO_write_high(&PORTC, LED_GREEN_2);	//set pin to 1
	
	/* button */
	GPIO_config_input_pullup(&DDRD, BUTTON); //set pin to input
 
	while (1) 
		{ 
		// Pause several milliseconds
		_delay_ms(BLINK_DELAY);
		// WRITE YOUR CODE HERE 
		if(!GPIO_read(&PORTD, BUTTON)) 
			{ 
				GPIO_toggle(&PORTB, LED_GREEN_1);
				GPIO_toggle(&PORTC, LED_GREEN_2);
			} 
		}
	// Will never reach this 
	return 0; 
}