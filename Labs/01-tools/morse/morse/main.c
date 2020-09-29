/*
 * morse.c
 *
 * Created: 29.09.2020 15:36:34
 * Author : krystof michal (xmicha64)
 */ 

/* Defines -----------------------------------------------------------*/
#define LED_GREEN   PB5     // AVR pin where green LED is connected
#define DOT			250		//pulse length of a dot
#define DASH		500		//pulse length of a dash
#define SHORT_PAUSE	200		//pulse length of a pause between dots and dashes
#define MID_PAUSE	400		//pulse length of a pause between letters
#define LONG_PAUSE	1000	//pulse length of a pause between words
#ifndef F_CPU
#define F_CPU 16000000      // CPU frequency in Hz required for delay func
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions

/* Variables ---------------------------------------------------------*/

/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/**
 * Toggle one LED and use the function from the delay library.
 */
int main(void)
{
    // Set pin as output in Data Direction Register
    // DDRB = DDRB or 0010 0000
    DDRB = DDRB | (1<<LED_GREEN);

    // Set pin LOW in Data Register (LED off)
    // PORTB = PORTB and 1101 1111
    PORTB = PORTB & ~(1<<LED_GREEN);

    /* Morse code translated into delays; pauses between dots and dashes are 100ms, dots and pauses between
    letters are 250ms, dashes are 500 ms and final pause (between words) is 1000ms*/
    int code[]={DASH, SHORT_PAUSE, DOT, SHORT_PAUSE, DOT, MID_PAUSE, DOT, MID_PAUSE, DOT, SHORT_PAUSE, DOT, SHORT_PAUSE, DASH, SHORT_PAUSE, DASH, SHORT_PAUSE, DASH, LONG_PAUSE};

    // Infinite loop
    while (1)
    {
        PORTB = PORTB ^ (1<<LED_GREEN);
        _delay_ms(DASH);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_PAUSE);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(DOT);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_PAUSE);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(DOT);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(MID_PAUSE);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(DOT);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(MID_PAUSE);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(DOT);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_PAUSE);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(DOT);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_PAUSE);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(DASH);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_PAUSE);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(DASH);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(SHORT_PAUSE);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(DASH);
		
		PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(LONG_PAUSE);
    }

    // Will never reach this
}
