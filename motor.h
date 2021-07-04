#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include "config.h"
#include "AppDebug.h"

extern bool motor_is_stop[MAX_NUMBER_MOTOR];
extern uint8_t statusCurrentMotor[MAX_NUMBER_MOTOR];
//----mode run for each motor in each step
enum
{
    RUN_OPEN,
    RUN_STOP,
    RUN_CLOSE
};


// extern int LED_R;
// extern int LED_G;   
// extern int LED_B;
// extern int LED_1;
// extern int LED_2;
// extern int LED_3;
// extern int LED_4;
// extern int LED_5;
// extern int LED_6;
// extern int LED_7;
// extern int LED_8;
// extern int LED_9;
// extern int LED_10; 
// extern int LED_11;
// extern int LED_12;

struct _controlStep
{
    /* data */
};
struct _stepMode
{
    /* data */
};



// //--------mode open for each motor----------
// uint8_t MODE_OPEN_STEP_1[MAX_NUMBER_MOTOR] = {RUN_OPEN, RUN_OPEN, RUN_OPEN, RUN_STOP, RUN_STOP, RUN_STOP};
// uint8_t MODE_OPEN_STEP_2[MAX_NUMBER_MOTOR] = {RUN_STOP, RUN_STOP, RUN_STOP, RUN_OPEN, RUN_OPEN, RUN_OPEN};
// uint8_t MODE_OPEN_STEP_3[MAX_NUMBER_MOTOR] = {RUN_CLOSE, RUN_CLOSE, RUN_STOP, RUN_STOP, RUN_STOP, RUN_STOP};
// //--------mode close for each motor----------
// uint8_t MODE_CLOSE_STEP_1[MAX_NUMBER_MOTOR] = {RUN_OPEN, RUN_OPEN, RUN_STOP, RUN_STOP, RUN_STOP, RUN_STOP};
// uint8_t MODE_CLOSE_STEP_2[MAX_NUMBER_MOTOR] = {RUN_STOP, RUN_STOP, RUN_STOP, RUN_CLOSE, RUN_CLOSE, RUN_CLOSE};
// uint8_t MODE_CLOSE_STEP_3[MAX_NUMBER_MOTOR] = {RUN_CLOSE, RUN_CLOSE, RUN_CLOSE, RUN_STOP, RUN_STOP, RUN_STOP};


struct motor
{
    // uint116_t 
    unsigned int open_motor[MAX_NUMBER_MOTOR];
    unsigned int stop_motor[MAX_NUMBER_MOTOR];
    unsigned int close_motor[MAX_NUMBER_MOTOR];

    unsigned int open_motor_1;
    unsigned int stop_motor_1;
    unsigned int close_motor_1;

    unsigned int open_motor_2;
    unsigned int stop_motor_2;
    unsigned int close_motor_2;

    unsigned int open_motor_3;
    unsigned int stop_motor_3;
    unsigned int close_motor_3;

    unsigned int open_motor_4;
    unsigned int stop_motor_4;
    unsigned int close_motor_4;

    unsigned int open_motor_5;
    unsigned int stop_motor_5;
    unsigned int close_motor_5;

    unsigned int open_motor_6;
    unsigned int stop_motor_6;
    unsigned int close_motor_6;

    unsigned int convert_data_motor;
    char *data_send_motor;
    

    //-------------------------------
    unsigned int on_led[MAX_NUMBER_LED];
    unsigned int off_led[MAX_NUMBER_LED];
    unsigned int on_led_r;
    unsigned int off_led_r;

    unsigned int on_led_g;
    unsigned int off_led_g;

    unsigned int on_led_b;
    unsigned int off_led_b;

    unsigned int on_led_1;
    unsigned int off_led_1;

    unsigned int on_led_2;
    unsigned int off_led_2;

    unsigned int on_led_3;
    unsigned int off_led_3;

    unsigned int on_led_4;
    unsigned int off_led_4;
    
    unsigned int on_led_5;
    unsigned int off_led_5;

    unsigned int on_led_6;
    unsigned int off_led_6;

    unsigned int on_led_7;
    unsigned int off_led_7;
    
    unsigned int on_led_8;
    unsigned int off_led_8;

    unsigned int convert_data_led;
    char *data_send_led;
};

void initMotor();
bool is_done_step();
void stop_motor(int number);

void open_motor(int number);

void close_motor(int number);

void on_led(int number);

void off_led(int number);

#endif
