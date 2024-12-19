#include "dcmotor.h"

void motor_init(){
//whel one
    gpio_init(MOTOR_DIR1_PIN1);
    gpio_set_dir(MOTOR_DIR1_PIN1, GPIO_OUT);
      gpio_init(MOTOR_DIR1_PIN2);
    gpio_set_dir(MOTOR_DIR1_PIN2, GPIO_OUT);
    gpio_set_function(MOTOR_PWM1_PIN ,GPIO_FUNC_PWM);
    uint slicenum = pwm_gpio_to_slice_num(MOTOR_PWM1_PIN);
    pwm_set_wrap(slicenum ,255);
    pwm_set_clkdiv(slicenum ,4.0f);
    pwm_set_enabled(slicenum,true);
//wheel 2
    gpio_init(MOTOR_DIR2_PIN1);
    gpio_set_dir(MOTOR_DIR2_PIN1, GPIO_OUT);
      gpio_init(MOTOR_DIR2_PIN2);
    gpio_set_dir(MOTOR_DIR2_PIN2, GPIO_OUT);
    gpio_set_function(MOTOR_PWM2_PIN ,GPIO_FUNC_PWM);
    uint slicenum2 = pwm_gpio_to_slice_num(MOTOR_PWM2_PIN);
    pwm_set_wrap(slicenum2 ,255);
    pwm_set_clkdiv(slicenum2 ,4.0f);
    pwm_set_enabled(slicenum2,true);
//wheel 3 
    gpio_init(MOTOR_DIR3_PIN1);
    gpio_set_dir(MOTOR_DIR3_PIN1, GPIO_OUT);
      gpio_init(MOTOR_DIR3_PIN2);
    gpio_set_dir(MOTOR_DIR3_PIN2, GPIO_OUT);
    gpio_set_function(MOTOR_PWM3_PIN ,GPIO_FUNC_PWM);
    uint slicenum3 = pwm_gpio_to_slice_num(MOTOR_PWM3_PIN);
    pwm_set_wrap(slicenum3 ,255);
    pwm_set_clkdiv(slicenum3 ,4.0f);
    pwm_set_enabled(slicenum3,true);
//wheel 4 
    gpio_init(MOTOR_DIR4_PIN1);
    gpio_set_dir(MOTOR_DIR4_PIN1, GPIO_OUT);
      gpio_init(MOTOR_DIR4_PIN2);
    gpio_set_dir(MOTOR_DIR4_PIN2, GPIO_OUT);
    gpio_set_function(MOTOR_PWM4_PIN ,GPIO_FUNC_PWM);
    uint slicenum4 = pwm_gpio_to_slice_num(MOTOR_PWM4_PIN);
    pwm_set_wrap(slicenum4 ,255);
    pwm_set_clkdiv(slicenum4 ,4.0f);
    pwm_set_enabled(slicenum4,true);

}

void motor_control_forward(uint16_t speed){
    if(speed>255) speed=255 ;
    
        //wheel one
        gpio_put(MOTOR_DIR1_PIN1 ,1);
         gpio_put(MOTOR_DIR1_PIN2 ,0);
        //wheel two fun
        gpio_put(MOTOR_DIR2_PIN1 ,0);
         gpio_put(MOTOR_DIR2_PIN2 ,1);
        //wheel three
        gpio_put(MOTOR_DIR3_PIN1 ,0);
         gpio_put(MOTOR_DIR3_PIN2 ,1);
         //wheel four
        gpio_put(MOTOR_DIR4_PIN1 ,1);
         gpio_put(MOTOR_DIR4_PIN2 ,0); 

    pwm_set_gpio_level(MOTOR_PWM1_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM2_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM3_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM4_PIN,speed);

}

void motor_control_backward(uint16_t speed){
    if(speed>255) speed=255 ;
    
        //wheel one
        gpio_put(MOTOR_DIR1_PIN1 ,0);
         gpio_put(MOTOR_DIR1_PIN2 ,1);
        //wheel two fun
        gpio_put(MOTOR_DIR2_PIN1 ,1);
         gpio_put(MOTOR_DIR2_PIN2 ,0);
        //wheel three
        gpio_put(MOTOR_DIR3_PIN1 ,1);
         gpio_put(MOTOR_DIR3_PIN2 ,0);
         //wheel four
        gpio_put(MOTOR_DIR4_PIN1 ,0);
         gpio_put(MOTOR_DIR4_PIN2 ,1); 

    pwm_set_gpio_level(MOTOR_PWM1_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM2_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM3_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM4_PIN,speed);

}


void motor_control_left(uint16_t speed){
    if(speed>255) speed=255 ;
    
        //wheel one
        gpio_put(MOTOR_DIR1_PIN1 ,0);
         gpio_put(MOTOR_DIR1_PIN2 ,1);
        //wheel two fun
        gpio_put(MOTOR_DIR2_PIN1 ,0);
         gpio_put(MOTOR_DIR2_PIN2 ,1);
        //wheel three
        gpio_put(MOTOR_DIR3_PIN1 ,1);
         gpio_put(MOTOR_DIR3_PIN2 ,0);
         //wheel four
        gpio_put(MOTOR_DIR4_PIN1 ,1);
         gpio_put(MOTOR_DIR4_PIN2 ,0); 
  
    pwm_set_gpio_level(MOTOR_PWM1_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM2_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM3_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM4_PIN,speed);

}

void motor_control_right(uint16_t speed){
    if(speed>255) speed=255 ;
  
        //wheel one
            gpio_put(MOTOR_DIR1_PIN1 ,1);
         gpio_put(MOTOR_DIR1_PIN2 ,0);
        //wheel two fun
        gpio_put(MOTOR_DIR2_PIN1 ,1);
         gpio_put(MOTOR_DIR2_PIN2 ,0);
        //wheel three
        gpio_put(MOTOR_DIR3_PIN1 ,0);
         gpio_put(MOTOR_DIR3_PIN2 ,1);
         //wheel four
        gpio_put(MOTOR_DIR4_PIN1 ,0);
         gpio_put(MOTOR_DIR4_PIN2 ,1); 

    pwm_set_gpio_level(MOTOR_PWM1_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM2_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM3_PIN,speed);
    pwm_set_gpio_level(MOTOR_PWM4_PIN,speed);
}

void motor_control_slight_left(uint16_t speed) {
    motor_control_left(speed);
    sleep_ms(500);
    motor_control_stop();
}

void motor_control_slight_right(uint16_t speed) {
    motor_control_right(speed);
    sleep_ms(500);
    motor_control_stop();
}


void motor_control_stop(){
   
        //wheel one
        gpio_put(MOTOR_DIR1_PIN1 ,0);
         gpio_put(MOTOR_DIR1_PIN2 ,0);
        //wheel two fun
        gpio_put(MOTOR_DIR2_PIN1 ,0);
         gpio_put(MOTOR_DIR2_PIN2 ,0);
        //wheel three
        gpio_put(MOTOR_DIR3_PIN1 ,0);
         gpio_put(MOTOR_DIR3_PIN2 ,0);
         //wheel four
        gpio_put(MOTOR_DIR4_PIN1 ,0);
         gpio_put(MOTOR_DIR4_PIN2 ,0);
}