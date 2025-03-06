#include "srv_button.h"

#define BUTTON_PIN 10

void button_init(){
    pinMode(BUTTON_PIN, INPUT_PULLUP);
};
int button_is_pressed(){
    return digitalRead(BUTTON_PIN) == LOW;
};