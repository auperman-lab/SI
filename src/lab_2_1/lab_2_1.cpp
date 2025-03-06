
#include "lab_2_1.h"
#include "srv/srv_button/srv_button.h"
#include "srv/srv_led/srv_led.h"
#include "srv/srv_serial/srv_serial.h"

Led led_green(10);


void lab_2_1_setup(){
    button_init();
    srv_serial_setup();

    printf("Setup for lab 2.1 done\n");  
}

void lab_2_1_loop(){
    printf("Lab 2.1 loop is working");
    lab_2_1_task_1();
    delay(1000);
}

void lab_2_1_task_1(){
    printf("Lab 2.1 task loop is working");
    if(button_is_pressed()){

        if(led_green.is_on()){
            led_green.off();
        }else{
            led_green.on();
        }

    };
}

void lab_2_1_task_2(){

}