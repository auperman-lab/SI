#include "timer.h"
#include <Arduino.h>

// Define the task counters
int buttonLedTaskCounter = BUTTON_LED_TASK_REC;
int blinkingLedTaskCounter = BLINKING_LED_TASK_REC;
int counterButtonsTaskCounter = COUNTER_BUTTONS_TASK_REC;
int idleTaskCounter = IDLE_TASK_REC;

void setupTimer()
{
    noInterrupts(); // Disable interrupts during setup

    // Reset Timer1 control registers
    TCCR1A = 0;
    TCCR1B = 0;

    // Set CTC mode (Clear Timer on Compare Match)
    TCCR1B |= (1 << WGM12);

    // Set prescaler to 64
    TCCR1B |= (1 << CS11) | (1 << CS10);

    // Set compare match value for 1ms interval
    OCR1A = 249;
    
    // Enable Timer1 compare match interrupt
    TIMSK1 |= (1 << OCIE1A);

    interrupts(); // Re-enable interrupts
}

// Timer1 ISR for system tick
ISR(TIMER1_COMPA_vect)
{
    timeScheduler(); // Increment the system tick counter
}