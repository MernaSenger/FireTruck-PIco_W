#include <stdbool.h>
#include <stdint.h>
#include "hardware/adc.h"
#include "pico/stdlib.h"

#define FLAME_SENSOR_PIN1 26
#define FLAME_SENSOR_PIN2 27
#define FLAME_SENSOR_PIN3 28

void flameSensorInit(uint8_t adc_pin,uint8_t adc_channel);

uint16_t readRawFlame(uint8_t adc_channel);

bool isFlameDetected(uint8_t adc_channel);