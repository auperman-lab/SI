
#include "lab_1_2.h"
#include <Arduino.h>
#include "srv/srv_lcd/srv_lcd.h"
#include "srv/srv_keypad/srv_keypad.h"
#include "srv/srv_led/srv_led.h" 


#define MAX_CODE_LENGTH 5
#define CORRECT_CODE "1234"  


char entered_code[MAX_CODE_LENGTH];  
uint8_t code_index = 0;
Led led1(1);



void lab_1_2_setup(){
    lcd_init();
    keypad_init();
    
    lcd_init();
    printf("Enter Code!");
}

void lab_1_2_loop(){

    char key ;
    scanf("%c", &key);
    if (key) {
        if (key == '#') {
            if (strcmp(entered_code, CORRECT_CODE) == 0) {
                // Correct code
                printf("\nCorrect Code!");
                led1.on();  
          
            } else {
                // Incorrect code
                printf("\nIncorrect Code");
            }
        } 
        else if (key == '*') {
            reset_code();
            lcd_clear();
            printf("Code Cleared");
        }
        else {
            if (code_index < MAX_CODE_LENGTH) {
                entered_code[code_index] = key;
                code_index++;
                lcd_clear();
                printf("Code: ");
                for (uint8_t i = 0; i < code_index; i++) {
                    printf("*");  // Print * for each entered digit
                }
            }
        }
    }

    delay(1000);
}

void reset_code() {
    entered_code[0] = '\0'; 
    code_index = 0;  
}