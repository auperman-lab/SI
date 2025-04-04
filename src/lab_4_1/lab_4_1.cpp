#include "lab_4_1.h"
#include "srv/srv_relay/srv_relay.h"
#include "srv/srv_serial/srv_serial.h"

#include <Arduino_FreeRTOS.h>
#include <stdio.h>
#include <string.h>

Relay relay(3);

void serialReportTask(void* pvParameters) {
    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (1) {
        printf("System status: Relay is %s\n", relay.isOn() ? "ON" : "OFF");
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(256));
    }
}

void commandHandlerTask(void* pvParameters) {
    TickType_t xLastWakeTime = xTaskGetTickCount();
    char input[20];
    uint8_t index = 0;

    while (1) {
        printf("> ");

        while (1) {
            char c = getchar();  // directly from stdin
            printf("%c", c);     // echo back

            if (c == '\n' || c == '\r') {
                input[index] = '\0';
                break;
            } else if (index < sizeof(input) - 1) {
                input[index++] = c;
            }
        }

        if (strcmp(input, "relay on") == 0) {
            relay.on();
            printf("Relay turned ON\n");
        } else if (strcmp(input, "relay off") == 0) {
            relay.off();
            printf("Relay turned OFF\n");
        } else if (strlen(input) > 0) {
            printf("Unknown command. Use 'relay on' or 'relay off'\n");
        }

        index = 0;
        memset(input, 0, sizeof(input));

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(256));
    }
}

void lab_4_1_setup() {
    relay.init();
    srv_serial_setup();

    xTaskCreate(serialReportTask, "SerialReport", 256, NULL, 1, NULL);
    xTaskCreate(commandHandlerTask, "CommandHandler", 256, NULL, 1, NULL);
}

void lab_4_1_loop() {
    // Empty, tasks are scheduled by FreeRTOS
}
