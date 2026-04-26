//delayのHAL

#include "platform_delay.h"

#include <Arduino.h>

void platform_delay_ms(uint32_t ms)
{
    delay(ms);
}
