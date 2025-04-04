#include "lab_3_1.h"
#include "Arduino_FreeRTOS.h"
#include "srv/srv_lcd/srv_lcd.h"
#include "srv/srv_potentiometer/srv_potentiometer.h"

Srv_Potentiometer pot(2);
int potValue = 0;        



void task_acquire_sensor(void* pvParameters) {
    char buffer[16]; 

    while (1) {
        int raw = pot.readRaw();
        potValue = raw;

        snprintf(buffer, sizeof(buffer), "Pot: %4d", potValue);
        lcd_clear();
        lcd_print(buffer, 0, 0);  
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


void task_display_status(void* pvParameters) {
    while (1) {
        lcd_clear();
        printf("\nSystem OK");
        vTaskDelay(pdMS_TO_TICKS(500)); 
    }
}

void lab_3_1_setup() {
    lcd_init();
    pot.begin();
    xTaskCreate(task_acquire_sensor, "Sensor", 1000, NULL, 1, NULL);
    xTaskCreate(task_display_status, "Display", 1000, NULL, 1, NULL);
    vTaskStartScheduler();
}

void lab_3_1_loop() {
    // Empty since FreeRTOS handles tasks
}