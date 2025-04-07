#include "srv_led.h"


Led::Led(int led_pin): led_pin(led_pin == 0 ? LED_BUILTIN : led_pin) {
    pinMode(led_pin, OUTPUT);
}

void Led::on() {
    return digitalWrite(led_pin, HIGH);
}

void Led::off() {
    return digitalWrite(led_pin, LOW);
}

bool Led::is_on() {
    return digitalRead(led_pin);
}