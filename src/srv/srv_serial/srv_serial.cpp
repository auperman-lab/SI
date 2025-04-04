#include "srv_serial.h"
#include <Arduino.h>
#include <stdio.h>

FILE serial_stream;  

int srv_serial_putchar(char c, FILE *stream) {
    if (c == '\n') {  
        Serial.write('\r');
    }
    Serial.write(c);
    return 0;
}
  
int srv_serial_getchar(FILE *stream) {
    while (!Serial.available()) {
        ; 
    }
    return Serial.read();
}

void srv_serial_setup() {
    Serial.begin(9600);

    serial_stream.flags  = _FDEV_SETUP_WRITE | _FDEV_SETUP_READ;
    serial_stream.put    = srv_serial_putchar;
    serial_stream.get    = srv_serial_getchar;
    
    stdout = &serial_stream;
    stdin  = &serial_stream;
}



