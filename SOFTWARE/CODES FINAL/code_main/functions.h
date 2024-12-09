#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BUTTON1    2 //stop
#define BUTTON2    3 //start
#define BUTTON3    4 //enter
#define BUTTON4    5 //up
#define BUTTON5    7 //down
#define LED       13
#define UV         6

#define I2C_DIR 0x27
#define ROWS       2
#define COLUMNS   16


#define WAIT1       500
#define WAIT_BLINK   50
#define DB          185
extern int pos;
extern int level;
extern int light;
extern LiquidCrystal_I2C lcd;
extern byte arrow_char[8];
extern uint8_t intensity;
extern uint8_t time_h;
extern uint8_t time_m;
extern uint8_t time_s;
extern unsigned int last_time;

void initializeComponents();
void initState();
void select();

void timeSet();
void intensitySet();
void counting();
bool up();
bool down();
bool enter();
void stop();
bool start();
#endif