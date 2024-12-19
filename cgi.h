#include "lwip/apps/httpd.h"
#include "pico/cyw43_arch.h"
#include "dcmotor.c"  // Changed from .c to .h

// LED CGI handler with improved safety
const char * cgi_led_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    //   gpio_init(1);
    //   gpio_set_dir(1, GPIO_OUT);
    // Check if an request for LED has been made (/led.cgi?led=x)
    if (strcmp(pcParam[0] , "led") == 0){
        // Look at the argument to check if LED is to be turned on (x=1) or off (x=0)
        if(strcmp(pcValue[0], "0") == 0)
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);

            // To set the pin low
            // gpio_put(1, 0);

        else if(strcmp(pcValue[0], "1") == 0)
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            

            // To set the pin high
            // gpio_put(1, 1);

    }
    
    // Send the index page back to the user
    return "/index.shtml";
}


// Motor control CGI handler with improved parameter validation
const char* cgi_wheel_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]) {
    // Define a default speed
    motor_init();
    const uint8_t DEFAULT_SPEED = 249;

    // Validate parameters before accessing
    if (strcmp(pcParam[0], "motor") == 0  ) {
        
        // Use a switch statement for more readable motor control
        if (strcmp(pcValue[0], "forward") == 0) {
            motor_control_forward(255);
        } else if (strcmp(pcValue[0], "left") == 0) {
            motor_control_slight_left(DEFAULT_SPEED);
        } else if (strcmp(pcValue[0], "right") == 0) {
            motor_control_slight_right(DEFAULT_SPEED);
        }
        else if (strcmp(pcValue[0], "backward") == 0) {
            motor_control_backward (DEFAULT_SPEED);
        } else if (strcmp(pcValue[0], "stop") == 0) {
            motor_control_stop();
        }
    }
    
    return "/index.shtml";
}

// CGI Handlers array
static const tCGI cgi_handlers[] = {
    {
        "/led.cgi", cgi_led_handler
    },
    {
        "/motor.cgi", cgi_wheel_handler
    }
};

// Initialize CGI handlers
void cgi_init(void) {
    // Correctly pass the number of handlers
    http_set_cgi_handlers(cgi_handlers, sizeof(cgi_handlers) / sizeof(tCGI));
}