/*
 * gpio.h
 *
 * Created: 13.10.2020 10:36:38
 *  Author: krystof michal
 */ 


#ifndef GPIO_H_
#define GPIO_H_
void GPIO_config_output(volatile uint8_t *reg_name, uint8_t pin_num);
void GPIO_config_input_nopull(volatile uint8_t *reg_name, uint8_t pin_num);
void GPIO_config_input_pullup(volatile uint8_t *reg_name, uint8_t pin_num);
void GPIO_write_low(volatile uint8_t *reg_name, uint8_t pin_num);
void GPIO_write_high(volatile uint8_t *reg_name, uint8_t pin_num);
void GPIO_toggle(volatile uint8_t *reg_name, uint8_t pin_num);
uint8_t GPIO_read(volatile uint8_t *reg_name, uint8_t pin_num);

#endif /* GPIO_H_ */