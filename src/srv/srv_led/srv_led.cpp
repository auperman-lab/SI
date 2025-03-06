#include "srv_led.h"

#define LED_PIN LED_BUILTIN
#define GREEN_LED_PIN 12  
#define RED_LED_PIN 13   

void led_init() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);  
    pinMode(RED_LED_PIN, OUTPUT);
    led_off();
    led_off_green();
    led_off_red();
}

void led_on() {
    digitalWrite(LED_PIN, HIGH);
}


void led_off() {
    digitalWrite(LED_PIN, LOW);
}

bool led_is_on(){
    return digitalRead(LED_PIN);
}

void led_on_green() {
    digitalWrite(GREEN_LED_PIN, HIGH);  
}

void led_off_green() {
    digitalWrite(GREEN_LED_PIN, LOW);   
}

bool led_is_on_green(){
    return digitalRead(GREEN_LED_PIN);
}

void led_on_red() {
    digitalWrite(RED_LED_PIN, HIGH);    
}

void led_off_red() {
    digitalWrite(RED_LED_PIN, LOW);     
}

bool led_is_on_red(){
    return digitalRead(RED_LED_PIN);
}