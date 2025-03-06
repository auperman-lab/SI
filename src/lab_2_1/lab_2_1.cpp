
#include "lab_2_1.h"
#include "srv/srv_button/srv_button.h"
#include "srv/srv_led/srv_led.h"
#include "srv/srv_serial/srv_serial.h"

Led led_green(10);
Led led_red(9);


Button button1(5);
Button button2(4);
Button button3(3);


int counter = 0;

void lab_2_1_setup(){
    srv_serial_setup();

    printf("Setup for lab 2.1 done\n");  
}

void lab_2_1_loop(){
    printf("Lab 2.1 loop is working");
    lab_2_1_task_1();
    delay(1000);
}

void lab_2_1_task_1(){
    printf("Lab 2.1 task1 loop is working");
    if(button1.is_pressed()){

        if(led_green.is_on()){
            led_green.off();
        }else{
            led_green.on();
        }
    };

    if(led_green.is_on()){
        led_red.off();
    };
}

void lab_2_1_task_2(){
    if(!led_green.is_on()){
        if(led_red.is_on()){
            led_red.on();
        }else{
            led_red.off();
        }

    }else{
        led_red.off();
    }

}

void lab_2_1_task_3(){
    static bool button_2_pressed = false; 
    static bool button_3_pressed = false; 

    if (button2.is_pressed())
    {
        if (!button_2_pressed)
        {                                   
            counter = min(counter+1, 10);
            button_2_pressed = true;         
            printf("Increment!");          
        }
    }
    else
    {
        button_2_pressed = false;
    }

    if (button3.is_pressed())
    { 
        if (!button_3_pressed)
        {                                  
            counter = min(counter-1, 1);
            button_3_pressed = true;        
            printf("Decrement!\n");        
        }
    }
    else
    {
        button_3_pressed = false; 
    }

    

}
