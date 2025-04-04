#include "srv_potentiometer.h"

// Constructor
Srv_Potentiometer::Srv_Potentiometer(int analogPin) : analogPin(analogPin) {}

void Srv_Potentiometer::begin() {
    pinMode(analogPin, INPUT);
}

int Srv_Potentiometer::readRaw() const {
    return analogRead(analogPin);
}

int Srv_Potentiometer::readMapped(int minVal, int maxVal) const {
    int raw = readRaw();
    return map(raw, 0, 1023, minVal, maxVal);
}
