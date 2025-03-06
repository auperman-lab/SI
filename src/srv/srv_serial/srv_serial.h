#ifndef SRV_SERIAL_H
#define SRV_SERIAL_H
#include <stdio.h>

extern FILE serial_stream;  

int srv_serial_getchar(FILE *stream);
int srv_serial_putchar(char c, FILE *stream);

void srv_serial_setup();

#endif 