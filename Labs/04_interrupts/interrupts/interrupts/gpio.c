/*
 * gpio.c
 *
 * Created: 13.10.2020 10:36:52
 *  Author: krystof michal
 */ 
#include "gpio.h"

/* Function definitions ----------------------------------------------*/
void GPIO_config_output(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name | (1<<pin_num); //set pin to 1
}
/*--------------------------------------------------------------------*/
void GPIO_config_input_nopull(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name & ~(1<<pin_num);  // Data Direction Register to 0
	*reg_name++;                    // Change pointer to Data Register
	*reg_name = *reg_name & ~(1<<pin_num);   // Data Register to 0
}
/*--------------------------------------------------------------------*/
void GPIO_config_input_pullup(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name & ~(1<<pin_num);  // Data Direction Register to 0
	*reg_name++;                    // Change pointer to Data Register
	*reg_name = *reg_name | (1<<pin_num);   // Data Register to 1
}

/*--------------------------------------------------------------------*/
void GPIO_write_low(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name & ~(1<<pin_num); //set pin to 0
}

/*--------------------------------------------------------------------*/
void GPIO_write_high(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name | (1<<pin_num); //set pin to 1
}
/*--------------------------------------------------------------------*/
void GPIO_toggle(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name ^ (1<<pin_num); //negate bit
}
/*--------------------------------------------------------------------*/
uint8_t GPIO_read(volatile uint8_t *reg_name, uint8_t pin_num)
{
	if (bit_is_clear(*reg_name, pin_num)) //check the value of the bit and return it
		return 0;
	else
		return 1;
}