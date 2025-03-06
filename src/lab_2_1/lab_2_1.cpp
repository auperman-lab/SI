
#include "lab_2_1.h"
#include "srv/srv_button/srv_button.h"
#include "srv/srv_led/srv_led.h"


void lab_2_1_setup(){

    led_init();
    button_init();

    printf("Setup for lab 2.1 done\n");  
}

void lab_2_1_loop(){

    printf("Lab 2.1 loop is working");
    lab_2_1_task_1();
    delay(1000);
}

void lab_2_1_task_1(){
    while(!button_is_pressed){

        if(led_is_on()){
            led_off();
        }else{
            led_on();
        }

    };

    while(button_is_pressed){};
    delay(300);

}