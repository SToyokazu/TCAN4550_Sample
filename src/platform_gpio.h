#ifndef PLATFORM_GPIO_H
#define PLATFORM_GPIO_H

#include <stdint.h>
#include <stdbool.h>

void plat_gpio_config_output(uint8_t pin, bool initial_value);
void plat_gpio_config_input(uint8_t pin);
void plat_gpio_write(uint8_t pin, bool value);
bool plat_gpio_read(uint8_t pin);
void plat_gpio_attach_irq_fall(uint8_t pin, void (*isr)(void));

#endif

