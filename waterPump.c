#include "waterPump.h"

static uint pumpPin;
static bool pumpState = false;

void water_pump_init(uint pump_pin) {
    pumpPin = pump_pin;
    gpio_init(pumpPin);
    gpio_set_dir(pumpPin, GPIO_OUT);
    water_pump_off();
}

void water_pump_on(void) {
    gpio_put(pumpPin, 1);
    pumpState = true;
}

void water_pump_off(void) {
    gpio_put(pumpPin, 0);
    pumpState = false;
}

bool water_pump_is_on(void) {
    return pumpState;
}
