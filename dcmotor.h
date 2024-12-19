#ifndef MOTOR_CONTROL_H 
#define MOTOR_CONTROL_H
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#define MOTOR_PWM1_PIN 2
#define MOTOR_DIR1_PIN1 3
#define MOTOR_DIR1_PIN2 4

#define MOTOR_PWM2_PIN 7
#define MOTOR_DIR2_PIN1 5
#define MOTOR_DIR2_PIN2 6

#define MOTOR_PWM3_PIN  17
#define MOTOR_DIR3_PIN1 18
#define MOTOR_DIR3_PIN2  19


 #define MOTOR_PWM4_PIN 22
#define MOTOR_DIR4_PIN1 20
#define MOTOR_DIR4_PIN2 21
void motor_init(void);
void motor_control_forward(uint16_t speed);
void motor_control_left(uint16_t speed);
void motor_control_right(uint16_t speed);
void motor_control_slight_left(uint16_t speed);
void motor_control_slight_right(uint16_t speed);
void motor_control_stop();
void motor_control_backward(uint16_t speed);
#endif