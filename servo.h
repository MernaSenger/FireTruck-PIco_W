#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#define SERVO_PWM_PIN 15



void servo_init(void);
void servo_set_angle(float angle);

 #endif

// #ifndef SERVO_H
// #define SERVO_H

// #ifndef PICO_STDLIB_H
// #define PICO_STDLIB_H
// #include "pico/stdlib.h"
// #endif

// #ifndef PWM_MODULE
// #define PWM_MODULe
// #include "hardware/pwm.h"
// #endif

// #define ROTATE_0 1000
// #define ROTATE_180 2000
// #define SERVO_PIN 26

// void servo_init();
// int goDegree(float degree);


// #endif