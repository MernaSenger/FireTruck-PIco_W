#include "buzzer.h"

void buzzer_init(uint8_t buzzerPin) {
    gpio_init(buzzerPin);
    gpio_set_dir(buzzerPin, GPIO_OUT);
}

void buzzer_on(uint8_t buzzerPin) {
    gpio_put(buzzerPin, true);
}

void buzzer_off(uint8_t buzzerPin) {
    gpio_put(buzzerPin, false);
}

void buzzer_toggle(uint8_t buzzerPin) {
    gpio_put(buzzerPin, !gpio_get(buzzerPin));
}