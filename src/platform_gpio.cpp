//GPIOアクセスと割り込みのHAL

#include "platform_gpio.h"

#include <Arduino.h>

void plat_gpio_config_output(uint8_t pin, , uint8_t mode, bool initial_value)
{
    pinMode(pin, OUTPUT);
    digitalWrite(pin, initial_value ? HIGH : LOW);
}

void plat_gpio_config_input(uint8_t pin)
{
    pinMode(pin, INPUT);
}

void plat_gpio_write(uint8_t pin, bool value)
{
    digitalWrite(pin, value ? HIGH : LOW);
}

bool plat_gpio_read(uint8_t pin)
{
    return digitalRead(pin) == HIGH;
}

void plat_gpio_attach_interrupt_fall(uint8_t pin, void (*isr)(void))
{
    attachInterrupt(digitalPinToInterrupt(pin), isr, FALLING);
}
