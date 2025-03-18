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

int task_2_n_counter = 0;
QueueHandle_t xQueue = NULL;

void task_1(void *pvParameters){

    TickType_t xLastTimeAwake = xTaskGetTickCount();
    vTaskDelay(TASK_1_OFFSET);

    while (1){
        printf("task1\n");
        if (button.is_pressed() && task_1_led_counter <=0){
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

            task_2_n_counter++;
            for (int i=0; i<task_2_n_counter;i++){
                xQueueSend(xQueue, &i, portMAX_DELAY);
                vTaskDelay(50/portTICK_PERIOD_MS);
            }

            for (int i=0; i< task_2_n_counter;i++){
                led_2.on();
                vTaskDelay(300/portTICK_PERIOD_MS);
                led_2.off();
                vTaskDelay(500/portTICK_PERIOD_MS);
                printf("Led blitz\n");
            }

        }

        vTaskDelay(500/portTICK_PERIOD_MS);



    }

}

void task_3(void *pvParameters){
    while(1){
        vTaskDelay(200/portTICK_PERIOD_MS);
        int data;
        bool bufferNotEmpty = false;

        while (xQueueReceive(xQueue, &data, 200/portTICK_PERIOD_MS)==pdTRUE){
            if (data == 0){
                printf("Task 3: Buffer Content: ");
            }
            printf(" %d, ", data);
            bufferNotEmpty = true;
        }
        if (!bufferNotEmpty){
            printf("Task 3: Buffer Empty\n");

        }
    }

}



void lab_2_2_setup(){
    srv_serial_setup();
    xQueue = xQueueCreate(10, sizeof(int));
    xSemaphore = xSemaphoreCreateBinary();

    xTaskCreate(task_1, "task_1", 1000, NULL, 1, NULL);
    xTaskCreate(task_2, "task_2", 1000, NULL, 1, NULL);
    xTaskCreate(task_3, "task_3", 1000, NULL, 1, NULL);


    vTaskStartScheduler();

}

void lab_2_2_loop(){

}
