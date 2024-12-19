#include "flamesensor.h"
#define FLAME_THRESHOLD 2500 //neb2a nghayaro based on the flame sensor's sensitivity

static uint8_t adc_channel1 = 0;
static uint8_t adc_channel2 = 1;
static uint8_t adc_channel3 = 2;


void flameSensorInit(uint8_t adc_pin,uint8_t adc_channel) {
    adc_init();
    adc_gpio_init(adc_pin);
    // adc_channel = 0;    //GPIO 26 = ADC 0
    adc_channel = adc_pin - 26;
    adc_select_input(adc_channel);
}

uint16_t readRawFlame(uint8_t adc_channel) {
    adc_select_input(adc_channel);
    return adc_read();    //return the ADC value (range of 0 – 4095 ((2^12)-1). (12 bit resolution))
}

bool isFlameDetected(uint8_t adc_channel) {
    uint16_t flameValue = readRawFlame( adc_channel);
    if (flameValue < FLAME_THRESHOLD){
        return true;
    }
    return false;
}