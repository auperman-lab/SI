#include "lab_2_2.h"
#include "srv/srv_button/srv_button.h"
#include "srv/srv_led/srv_led.h"
#include "srv/srv_serial/srv_serial.h"
#include "Arduino_FreeRTOS.h"
#include "semphr.h"


Led led_1(11);
Led led_2(12);

Button button(5);


int task_1_led_counter  = 0;
SemaphoreHandle_t xSemaphore = NULL;

void task_1(void *pvParameters){

    TickType_t xLastTimeAwake = xTaskGetTickCount();
    vTaskDelay(TASK_1_OFFSET);

    while (1){
        printf("task1\n");
        if (button.is_pressed() && task_1_led_counter <0){
            task_1_led_counter = 1000/ TASK_1_REC;
            led_1.on();
            printf("button press detected\n");
        }       
        
        if (task_1_led_counter > 0){
            task_1_led_counter--;
            led_1.on();
            printf("led1 is on\n");

        }else if(task_1_led_counter == 0 ){
            led_1.off();
            xSemaphoreGive(xSemaphore);
            printf("led1 is off\n");
            printf("Semaphore given\n");
            task_1_led_counter--;
        }


        vTaskDelayUntil(&xLastTimeAwake,  TASK_1_REC);
    };
    
}


void task_2(void *pvParameters){

    while(1){
        if(xSemaphoreTake(xSemaphore, portMAX_DELAY)==pdTRUE){
            
        }
    }

}


void lab_2_2_setup(){
    srv_serial_setup();
    xTaskCreate(task_1, "task_1", 1000, NULL, 1, NULL);
    xTaskCreate(task_2, "task_2", 1000, NULL, 1, NULL);

    vTaskStartScheduler();

}

void lab_2_2_loop(){

}
