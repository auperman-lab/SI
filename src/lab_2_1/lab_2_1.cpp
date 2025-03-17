
#include "lab_2_1.h"
#include "srv/srv_button/srv_button.h"
#include "srv/srv_led/srv_led.h"
#include "srv/srv_serial/srv_serial.h"
#include "timer.h"

Led led_green(12);
Led led_red(11);


Button button1(5);
Button button2(7);
Button button3(6);


int counter = 0;

void lab_2_1_setup(){
    setupTimer();
    srv_serial_setup();

    printf("Setup for lab 2.1 done\n");  
}


void lab_2_1_task_1(){
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
            led_red.off();
        }else{
            led_red.on();
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

void lab_2_1_idle(){
    printf("Green LED: ");
    printf(led_green.is_on() ? "ON\n" : "OFF\n");
    printf("Red LED2: ");
    printf(led_red.is_on() ? "ON\n" : "OFF\n");
    printf("Counter: ");
    printf("%d\n", counter);
    printf("------------------\n");

}

void lab_2_1_loop(){
    timeScheduler();
    lab_2_1_idle();
    delay(SYS_TICK*1000);
}




void timeScheduler(){
    int dynamicBlinkingLedTaskRec = BLINKING_LED_TASK_REC + (counter * 100);

    if (--buttonLedTaskCounter <= 0)
    {
        buttonLedTaskCounter = BUTTON_LED_TASK_REC;
        lab_2_1_task_1();
    }

    if (--blinkingLedTaskCounter <= 0)
    {
        blinkingLedTaskCounter = dynamicBlinkingLedTaskRec;
        lab_2_1_task_2();
    }

    if (--counterButtonsTaskCounter <= 0)
    {
        counterButtonsTaskCounter = COUNTER_BUTTONS_TASK_REC;
        lab_2_1_task_3();
    }
}