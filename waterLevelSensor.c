#include "waterLevelSensor.h"

// Variable to store the water level reading

void Water_LevelSensor_init(){
        adc_init();
        adc_gpio_init(WATER_LEVELSENSOR_PIN);
        adc_select_input(3); 
}

// Function to read the water level sensor
uint16_t Water_LevelSensor_read(){
   adc_select_input(3); 
   uint16_t adc_value = adc_read();

   //law akber mn value ben za3a2
   return adc_value;
}

bool isLow(){
    uint16_t water_level = Water_LevelSensor_read();
    if(water_level <WATER_LEVEL_THRESHOLD){         
        return true;
    }
    else{
       return false;
    }
}