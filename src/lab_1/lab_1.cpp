
#include "lab_1.h"
#include "srv/srv_serial/srv_serial.h"
#include "srv/srv_led/led.h"


void lab_1_setup(){

    led_init();
    srv_serial_setup();
    printf("Enter value (led on for on , led off for off): \n");  
}

void lab_1_loop(){
    char value[20];
    
    if (scanf("%19s", value) == 1) {
        if (strcmp(value, "led off") == 0) {
            printf("Turning LED off...\n");
            led_off();  
            printf("LED is off!\n");
        } else if (strcmp(value, "led on") == 0) {
            printf("Turning LED on...\n");
            led_on();
            printf("LED is on!\n");
        } else {
            printf("Unknown command: %s\n", value);
        }
    } else {
        printf("Unable to read the command\n");
    }

    delay(1000);
}