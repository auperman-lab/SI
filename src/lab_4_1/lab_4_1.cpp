#include "lab_4_1.h"
#include "srv/srv_relay/srv_relay.h"
#include "srv/srv_serial/srv_serial.h"
#include "srv/srv_lcd/srv_lcd.h"


Relay relay(3);
void lab_4_1_setup() {
    relay.init();
    srv_serial_setup();
    lcd_init();
}

void lab_4_1_loop() {
    char cmd[16], arg[16];

    scanf("%15s %15s", cmd, arg);  

    if (strcmp(cmd, "relay") == 0) {
        if (strcmp(arg, "on") == 0) {
            relay.on();
            printf("Relay activat\n");
        } else if (strcmp(arg, "off") == 0) {
            relay.off();
            printf("Relay dezactivat\n");
        } else {
            printf("Argument invalid\n");
        }
    } else {
        printf("Comanda necunoscuta\n");
    }
}