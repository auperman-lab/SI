#ifndef SRV_BUTTON_H
#define SRV_BUTTON_H

#include <Arduino.h>

class Button{
    private:
        int button_pin;
    
    public:
        Button(int button_pin);
        bool is_pressed();
};


#endif