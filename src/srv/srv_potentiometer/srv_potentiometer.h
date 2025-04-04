#ifndef SRV_POTENTIOMETER_H
#define SRV_POTENTIOMETER_H

#include <stdint.h>
#include <Arduino.h>  


class Srv_Potentiometer {
public:
    Srv_Potentiometer(int analogPin);

    void begin();

    int readRaw() const;

    int readMapped(int minVal = 0, int maxVal = 100) const;

private:
    int analogPin;
};

#endif 
