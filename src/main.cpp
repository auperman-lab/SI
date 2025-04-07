#include <Arduino.h>
#include <lab_1/lab_1.h>
#include <lab_1_1/lab_1_1.h>
#include <lab_1_2/lab_1_2.h>
#include <lab_2_1/lab_2_1.h>
#include <lab_2_2/lab_2_2.h>
#include <lab_3_1/lab_3_1.h>




#define APP_NAME LAB_2_2



void setup() {
  #if APP_NAME == LAB_2_2
    lab_2_2_setup();
  #endif
};

void loop() {
  #if APP_NAME == LAB_2_2
  lab_2_2_loop();
  #endif
};


