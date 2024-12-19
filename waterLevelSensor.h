#ifndef WATER_LEVELSENSOR_SENSOR_H
#define WATER_LEVELSENSOR_SENSOR_H
#include "pico/stdlib.h"
#include "hardware/adc.h"

// Define the default pin for the WATER_LEVELSENSOR sensor
// #ifndef WATER_LEVELSENSOR_PIN
#define WATER_LEVELSENSOR_PIN 29
// #endif
#define WATER_LEVEL_THRESHOLD 1500

void Water_LevelSensor_init();
uint16_t Water_LevelSensor_read();
bool isLow();



#endif // WATER_LEVELSENSOR_SENSOR_H