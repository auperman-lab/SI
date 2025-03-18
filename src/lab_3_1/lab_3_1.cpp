#include "lab_3_1.h"
#include "Arduino_FreeRTOS.h"





void lab_3_1_setup(){

    // xTaskCreate(task_1, "task_1", 1000, NULL, 1, NULL);
    // xTaskCreate(task_2, "task_2", 1000, NULL, 1, NULL);
    // xTaskCreate(task_3, "task_3", 1000, NULL, 1, NULL);


    vTaskStartScheduler();

}

void lab_3_1_loop(){

}
