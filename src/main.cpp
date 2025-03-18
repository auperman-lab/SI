#include <Arduino.h>
#include <lab_1/lab_1.h>
#include <lab_1_1/lab_1_1.h>
#include <lab_1_2/lab_1_2.h>
#include <lab_2_1/lab_2_1.h>
#include <lab_2_2/lab_2_2.h>



// #define APP_NAME LAB_1
// #define APP_NAME LAB_1_1
// #define APP_NAME LAB_1_2
// #define APP_NAME LAB_2_1
#define APP_NAME LAB_2_2



void setup() {
  // #if APP_NAME == LAB_1
  //   lab_1_setup();
  // #endif
  // #if APP_NAME == LAB_1_1
  //   lab_1_1_setup();
  // #endif
  // #if APP_NAME == LAB_1_2
  //   lab_1_2_setup();
  // #endif
  // #if APP_NAME == LAB_2_1
  //   lab_2_1_setup();
  // #endif
  #if APP_NAME == LAB_2_2
    lab_2_2_setup();
  #endif
};

void loop() {
  // #if APP_NAME == LAB_1
  // lab_1_loop();
  // #endif
  // #if APP_NAME == LAB_1_1
  //   lab_1_1_loop();
  // #endif
  // #if APP_NAME == LAB_2_1
  //   lab_2_1_loop();
  // #endif
  #if APP_NAME == LAB_2_2 
  lab_2_2_loop();
  #endif
};


