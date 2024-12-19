// #include "servo.h"


// void servo_init(){
//     gpio_set_function(SERVO_PWM_PIN,GPIO_FUNC_PWM);
//     uint servoSliceNum= pwm_gpio_to_slice_num(SERVO_PWM_PIN);
//     //pwm_config config = pwm_get_default_config();
//     pwm_set_wrap(servoSliceNum, 41561); //39062 ticks per clk cycle 

//     pwm_set_clkdiv(servoSliceNum, 64.0f); //frequency =122 kHz , period=
//     //pwm_init (servoSliceNum, &config, true);
//     //For example, a 1ms pulse within a 20ms period corresponds to a 5% duty cycle, and a 2ms pulse corresponds to a 10% duty cycle.
//     pwm_set_enabled(servoSliceNum, true);

// }

// void servo_set_angle(int angle) {
//     pwm_set_gpio_level(SERVO_PWM_PIN, angle);
// }

///////////////////////////////////////////////////////////////////////////////////////////

// void set_servo_angle(int angle) {
//     if (angle < 0) angle = 0;       // Clamp angle to 0 degrees minimum
//     if (angle > 180) angle = 180;   // Clamp angle to 180 degrees maximum

//     uint16_t pulse_width_us = (angle * (2000 - 1000) / 180) + 1000;  // Convert angle to microseconds
//     uint16_t pulse_width_ticks = (pulse_width_us * 24999) / 20000;   // Scale to PWM wrap value (20 ms period)

//     uint slice_num = pwm_gpio_to_slice_num(SERVO_PWM_PIN);
//     pwm_set_chan_level(slice_num, PWM_CHAN_A, pulse_width_ticks);    // Set duty cycle
// }


// void servo_init() {
//     gpio_set_function(SERVO_PWM_PIN, GPIO_FUNC_PWM);
//     uint servoSliceNum = pwm_gpio_to_slice_num(SERVO_PWM_PIN);

//     // Set PWM wrap to a suitable value for 50Hz frequency (e.g., 20ms period)
//     pwm_set_wrap(servoSliceNum, 24999); // Assuming a 1ms tick period with clkdiv of 4
//     pwm_set_clkdiv(servoSliceNum, 64.0f); // clkdiv = 64 for a 50Hz PWM frequency
//     pwm_set_enabled(servoSliceNum, true);
// }

// void set_servo_angle(int angle) {
//     // Ensure the angle is clamped within 0-180 degrees
//     if (angle < 0) angle = 0;
//     if (angle > 180) angle = 180;

//     uint16_t sliceNum = pwm_gpio_to_slice_num(SERVO_PWM_PIN);

//     // Map the angle to a corresponding pulse width in ticks
//     // 1ms pulse -> duty cycle = (1ms / 20ms) * pwm_wrap = 1250 ticks
//     // 2ms pulse -> duty cycle = (2ms / 20ms) * pwm_wrap = 2500 ticks
//     uint16_t pulseWidthTicks = 1250 + (angle * (2500 - 1250) / 180);

//     // Set the PWM pulse width
//     pwm_set_gpio_level(SERVO_PWM_PIN, pulseWidthTicks);
// }


////////////////////////////////////////////
// HANA SEIF

// #include "servo.h"
// #include "hardware/clocks.h"

// void servo_init()
// {
//     gpio_init(SERVO_PIN);

//     // Setup up PWM t
//     gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
//     pwm_set_gpio_level(SERVO_PIN, 0);
//     uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

//     // Get clock speed and compute divider for 50 hz
//     uint32_t clk = clock_get_hz(clk_sys);
//     uint32_t div = clk / (20000 * 50);

//     pwm_config config = pwm_get_default_config();
//     pwm_config_set_clkdiv(&config, (float)div);

//     // Set wrap so the period is 20 ms
//     pwm_config_set_wrap(&config, 20000);

//     // Load the configuration
//     pwm_init(slice_num, &config, false);

//     pwm_set_enabled(slice_num, true);
// }

// int goDegree(float degree)
// {
//     // if (degree > 180.0)
//     // {
//     //     return;
//     // }
//     // if (degree < 0)
//     // {
//     //     return;
//     // }

//     int duty = (((float)(ROTATE_180 - ROTATE_0) / 180.0) * degree) + ROTATE_0;
//     pwm_set_gpio_level(SERVO_PIN, duty);

//     return 0;
// }
#include "servo.h"

void servo_init() {
    gpio_set_function(SERVO_PWM_PIN, GPIO_FUNC_PWM);
    uint servoSliceNum = pwm_gpio_to_slice_num(SERVO_PWM_PIN);

    // Set the PWM wrap value for a 50Hz signal
    pwm_set_wrap(servoSliceNum, 20000);

    // Set clock divider to achieve 50Hz
    pwm_set_clkdiv(servoSliceNum, 64.0f);

    // Enable PWM
    pwm_set_enabled(servoSliceNum, true);
}

void servo_set_angle(float angle) {
    // Map angle (0° to 180°) to pulse width (1ms to 2ms)
    int pulse_width_ticks = 1000 + (angle / 180.0f) * 1000; // 1ms + scaled value
    pwm_set_gpio_level(SERVO_PWM_PIN, pulse_width_ticks);
}