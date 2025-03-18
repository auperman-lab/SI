#ifndef SRV_HUMITURE_H
#define SRV_HUMITURE_H

#include <Arduino.h>
#include <DHT.h>

#define DHT_TYPE DHT11  


class Humiture {
    private:
        int pin;
        DHT dhtSensor;

    public:
    Humiture(int pin); 

    void humiture_setup();

    float getTemperature();

    float getHumidity();

};

#endif  
