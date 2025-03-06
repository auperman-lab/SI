
#include "lab_1_1.h"
#include "srv/srv_serial/srv_serial.h"
#include <Arduino.h>
#include "srv/srv_led/led.h"


void lab_1_1_setup(){

    led_init();
    srv_serial_setup();
    printf("Enter value (1 for on , 0 for off): \n");
}

void lab_1_1_loop(){

    char value[20];
    if (scanf("%19s", value) == 1){
        if(strcmp(value, "led off") == 0){
            printf("%s\n", value);
            led_off_red();
            printf("led is off !!");
        }else if(strcmp(value, "led on") == 0){
            printf("%s\n", value);
            led_on_red();
            printf("led is on !!");
        }else{
            printf("unknown command , %s\n", value);
        }
    }else{
        printf("Unable to read the command");
    }

    delay(1000);
}