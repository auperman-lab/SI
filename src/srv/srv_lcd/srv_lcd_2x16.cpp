#include "srv_lcd.h"

#define LCD_ADDRESS 0x27  
#define LCD_COLS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);
FILE lcd_output = {0};

// Move col and row to global scope
uint8_t col = 0, row = 0;

int lcd_putchar(char c, FILE* stream) {
    if (c == '\n') {
        // Clear the current row before moving to the next row
        lcd.setCursor(0, row);
        for (uint8_t i = 0; i < LCD_COLS; i++) {
            lcd.print(' ');  // Overwrite the row with spaces
        }

        row = (row + 1) % LCD_ROWS;
        col = 0;
        lcd.setCursor(col, row);
    } else {
        lcd.setCursor(col, row);
        lcd.print(c);
        col++;

        // If col exceeds LCD_COLS, move to next row
        if (col >= LCD_COLS) {
            row = (row + 1) % LCD_ROWS;
            col = 0;
            lcd.setCursor(col, row);
        }
    }

    return 0;
}

void lcd_init() {
    lcd.init();
    lcd_backlight_on();

    fdev_setup_stream(&lcd_output, lcd_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &lcd_output;
}

void lcd_print(const char* message, uint8_t col, uint8_t row) {
    lcd.setCursor(col, row);
    lcd.print(message);
}

void lcd_clear() {
    lcd.clear();  // Clear the entire screen
    col = 0;
    row = 0;  // Reset position variables
    lcd.setCursor(0, 0);
}

void lcd_backlight_on() {
    lcd.backlight();
}

void lcd_backlight_off() {
    lcd.noBacklight();
}
