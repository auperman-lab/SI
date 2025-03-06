#ifndef SRV_LCD_H
#define SRV_LCD_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


void lcd_init();
void lcd_print(const char* message, uint8_t col, uint8_t row);
void lcd_clear();
void lcd_backlight_on();
void lcd_backlight_off();
int lcd_putchar(char c, FILE* stream);


#endif 