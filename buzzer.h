#include <stdint.h>
#include "pico/stdlib.h"

#define WATER_LEVEL_BUZZER_PIN 12
#define FIRETRUCK_BUZZER_PIN 13

void buzzer_init(uint8_t buzzerPin);

void buzzer_on(uint8_t buzzerPin);

void buzzer_off(uint8_t buzzerPin);

void buzzer_toggle(uint8_t buzzerPin);