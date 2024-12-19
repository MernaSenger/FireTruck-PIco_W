#include "lwip/apps/httpd.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "lwipopts.h"
#include "lwip/netif.h"
#include "lwip/ip_addr.h"
#include "cgi.h"
#include "dcmotor.h"
#include "flamesensor.c"
#include "waterLevelSensor.c"
#include "servo.c"
#include "waterPump.c"
#include "buzzer.c"

// WIFI Credentials
const char WIFI_SSID[] = "Merna";
const char WIFI_PASSWORD[] = "merna123";

// Embedded HTML
const char index_html[] = "<!DOCTYPE html>"
"<html>"
"<head><title>Pico W Web Server</title></head>"
"<body><h1>Hello from Raspberry Pi Pico W!</h1></body>"
"</html>";

// CGI Handler
static int cgi_empty_page_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[], char *pcResponse, uint16_t response_len) {
    snprintf(pcResponse, response_len, "%s", index_html);
    return 1;
}

int main() {

    // return 0;
    stdio_init_all();

    // Initialize hardware components
    gpio_init(0);
    gpio_set_dir(0, GPIO_OUT);
    // motor_init();
    // servo_init();

    // Initialize Wi-Fi
    if (cyw43_arch_init()) {
        printf("CYW43 init failed\n");
        return -1;
    }

    cyw43_arch_enable_sta_mode();
    printf("Connecting to WiFi...\n");
    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("WiFi connection failed\n");
        return -1;
    }

    printf("WiFi connected\n");

    // Start HTTP server
    httpd_init();
    cgi_init();

      flameSensorInit(FLAME_SENSOR_PIN1,adc_channel1); //26 adc channel 0
     flameSensorInit(FLAME_SENSOR_PIN2,adc_channel2); //adc channel 1
     flameSensorInit(FLAME_SENSOR_PIN3,adc_channel3);
     Water_LevelSensor_init();
     buzzer_init(WATER_LEVEL_BUZZER_PIN);
     buzzer_init(FIRETRUCK_BUZZER_PIN);
     servo_init();
    // gpio_init(LED_PIN);
    // gpio_set_dir(LED_PIN, GPIO_OUT);
     motor_init();
     water_pump_init(WATER_PUMP_PIN);
     int count=0;

    // Main loop
    while (1) {
        cyw43_arch_poll();
        sleep_ms(1);
      
      count++ ;
      uint16_t left= readRawFlame(adc_channel1) ;
      uint16_t middle= readRawFlame(adc_channel2) ;
      uint16_t right= readRawFlame(adc_channel3) ;
      uint16_t f= Water_LevelSensor_read();
     
      if(count==10){
      printf("%i %i %i\n", left, middle, right);
      count =0;
      }
      if ((left<=3000 || middle<=3000 || right<=3000) && !(left <= 150  ||  middle<=150 || right<=150)){
        printf("batta\n");
        if (left<right && left<=middle){
          motor_control_left(200);
          sleep_ms(100);
          printf("abouElsaadat");
        }
        else if (middle<=left && middle<=right){
          motor_control_forward(249);
          sleep_ms(100);
          printf("haytham");
        }
        else if(right<middle && right<left){
          motor_control_right(200);
          sleep_ms(100);
          printf("mervat");
        }
         water_pump_off() ;
      }

    else if(left <= 150 || middle <= 150 || right <= 150 ) {
      printf("servoo");
        motor_control_stop();
      servo_set_angle(100);
          sleep_ms(1000);
          servo_set_angle(600);
          sleep_ms(1000);
         water_pump_on() ;
      }
      else {
        motor_control_stop();
        water_pump_off() ;
      }

    
          
       
 }
    return 0;
}