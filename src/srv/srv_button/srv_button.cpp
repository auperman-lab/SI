#include "srv_button.h"

Button::Button(int buttonPin): button_pin(buttonPin) {
    pinMode(buttonPin, INPUT_PULLUP);
}

bool Button::is_pressed() {
    return digitalRead(button_pin) == LOW;
}