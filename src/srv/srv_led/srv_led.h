#ifndef SRV_LED_H
#define SRV_LED_H

#include <Arduino.h>

void led_init();

void led_on();
void led_off();
bool led_is_on();

void led_on_green();
void led_off_green();
bool led_is_on_green();

void led_on_red();
void led_off_red();
bool led_is_on_red();

#endif