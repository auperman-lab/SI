#ifndef SRV_LED_H
#define SRV_LED_H

#include <Arduino.h>

class Led {
    private:
        int led_pin;
    
    public:
        Led(int led_pin);
        void on();
        void off();
        bool is_on();
    };
    

#endif