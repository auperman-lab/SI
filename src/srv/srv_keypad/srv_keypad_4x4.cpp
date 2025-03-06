#include "srv_keypad.h"

const byte ROWS = 4;
const byte COLS = 4;

// Keypad layout
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};  
byte colPins[COLS] = {5, 4, 3, 2};  

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

FILE keypad_input = {0};

int keypad_getchar(FILE* stream) {
    char key;
    while((key = keypad_get_key()) == 0){
        delay(10);

    }
    return  key;
}


void keypad_init() {
    fdev_setup_stream(&keypad_input, NULL, keypad_getchar, _FDEV_SETUP_READ);
    stdin = &keypad_input;

}

char keypad_get_key() {
    return keypad.getKey();
}


