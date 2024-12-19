#ifndef WATERPUMP_H
#define WATERPUMP_H

#include "pico/stdlib.h"

#ifndef WATER_PUMP_PIN
#define WATER_PUMP_PIN 9
#endif

void water_pump_init(uint pump_pin);
void water_pump_on(void);
void water_pump_off(void);
bool water_pump_is_on(void);

#endif // WATERPUMP_H