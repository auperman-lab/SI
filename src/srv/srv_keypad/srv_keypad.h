
#ifndef SRV_KEYPAD_H
#define SRV_KEYPAD_H

#include <Arduino.h>
#include <Keypad.h>

void keypad_init();
char keypad_get_key();
int keypad_getchar(FILE* stream);

#endif 
