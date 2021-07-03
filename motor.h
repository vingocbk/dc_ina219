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
    unsigned int on_motor_1;
    unsigned int stop_motor_1;
    unsigned int off_motor_1;

    unsigned int on_motor_2;
    unsigned int stop_motor_2;
    unsigned int off_motor_2;

    unsigned int on_motor_3;
    unsigned int stop_motor_3;
    unsigned int off_motor_3;

    unsigned int on_motor_4;
    unsigned int stop_motor_4;
    unsigned int off_motor_4;

    unsigned int on_motor_5;
    unsigned int stop_motor_5;
    unsigned int off_motor_5;

    unsigned int on_motor_6;
    unsigned int stop_motor_6;
    unsigned int off_motor_6;

    unsigned int convert_data_motor;
    char *data_send_motor;
    

    //-------------------------------
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
void stop_motor_1();
void stop_motor_2();
void stop_motor_3();
void stop_motor_4();
void stop_motor_5();
void stop_motor_6();

void open_motor_1();
void open_motor_2();
void open_motor_3();
void open_motor_4();
void open_motor_5();
void open_motor_6();

void close_motor_1();
void close_motor_2();
void close_motor_3();
void close_motor_4();
void close_motor_5();
void close_motor_6();

void on_led_motor_1();
void on_led_motor_2();
void on_led_motor_3();
void on_led_motor_4();
void on_led_motor_5();
void on_led_motor_6();

void off_led_motor_1();
void off_led_motor_2();
void off_led_motor_3();
void off_led_motor_4();
void off_led_motor_5();
void off_led_motor_6();

#endif
