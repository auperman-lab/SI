#include "lab_3_1.h"
#include "Arduino_FreeRTOS.h"
#include "srv/srv_lcd/srv_lcd.h"
#include "srv/srv_humiture/srv_humiture.h"

Humiture humiture(2);


void task_acquire_sensor(void* pvParameters) {
    while (1) {
        float temperature = humiture.getTemperature();
        float humidity = humiture.getHumidity();

        if (temperature != -1 && humidity != -1) {
            printf("Temp: %.1fC  Hum: %.1f%%\n", temperature, humidity);
        } else {
            printf("Sensor read error!\n");
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void task_display_status(void* pvParameters) {
    while (1) {
        lcd_clear();
        printf("System OK\n");
        vTaskDelay(pdMS_TO_TICKS(500)); 
    }
}

void lab_3_1_setup() {
    lcd_init();
    xTaskCreate(task_acquire_sensor, "Sensor", 1000, NULL, 1, NULL);
    xTaskCreate(task_display_status, "Display", 1000, NULL, 1, NULL);
    vTaskStartScheduler();
}

void lab_3_1_loop() {
    // Empty since FreeRTOS handles tasks
}