#include "lab_3_2.h"
#include "srv/srv_lcd/srv_lcd.h"
#include "srv/srv_serial/srv_serial.h"
#include "srv/srv_humiture/srv_humiture.h"
#include "srv/srv_filter/salt_pepper_filter.h"
#include "srv/srv_filter/weighted_moving_average_filter.h"

#include <Arduino_FreeRTOS.h>
#include <task.h>
#include <semphr.h>

// Components
Humiture hum(5);
SaltPepperFilter temp_filter;
WeightedMovingAverageFilter temp_filter_second_stage;

float temperature = 0.0;
float humidity = 0.0;

SemaphoreHandle_t xSensorMutex;

TaskHandle_t TaskSensorHandle = NULL;
TaskHandle_t TaskDisplayHandle = NULL;

void TaskSensor(void *pvParameters) {
    while (1) {
        float rawTemp = hum.getTemperature();
        float rawHumidity = hum.getHumidity();

        float filteredTemp = temp_filter.apply(rawTemp);
        filteredTemp = temp_filter_second_stage.apply(filteredTemp);

        if (xSemaphoreTake(xSensorMutex, (TickType_t)10) == pdTRUE) {
            temperature = filteredTemp;
            humidity = rawHumidity;
            xSemaphoreGive(xSensorMutex);
        }

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void TaskDisplay(void *pvParameters) {
    char buffer[32];
    while (1) {
        float tempCopy = 0.0;
        float humidityCopy = 0.0;

        if (xSemaphoreTake(xSensorMutex, (TickType_t)10) == pdTRUE) {
            tempCopy = temperature;
            humidityCopy = humidity;
            xSemaphoreGive(xSensorMutex);
        }

        printf("Humidity: %.2f %%\nTemp: %.2f °C\n", humidityCopy, tempCopy);
        lcd_clear();
        snprintf(buffer, sizeof(buffer), "H:%.1f%% T:%.1fC", humidityCopy, tempCopy);
        lcd_print(buffer, 0, 0);

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void lab_3_1_setup() {
    srv_serial_setup();
    lcd_init();
    hum.humiture_setup();

    xSensorMutex = xSemaphoreCreateMutex();

    // Create tasks
    xTaskCreate(TaskSensor, "SensorTask", 128, NULL, 1, &TaskSensorHandle);
    xTaskCreate(TaskDisplay, "DisplayTask", 128, NULL, 1, &TaskDisplayHandle);
}

void lab_3_1_loop() {
    // Do nothing – FreeRTOS handles everything
}
