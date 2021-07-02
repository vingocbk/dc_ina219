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
    byte high_stop_motor_1;
    byte high_open_motor_1;
    byte high_close_motor_1;
    byte low_stop_motor_1;
    byte low_open_motor_1;
    byte low_close_motor_1;

    byte high_stop_motor_2;
    byte high_open_motor_2;
    byte high_close_motor_2;
    byte low_stop_motor_2;
    byte low_open_motor_2;
    byte low_close_motor_2;

    byte high_stop_motor_3;
    byte high_open_motor_3;
    byte high_close_motor_3;
    byte low_stop_motor_3;
    byte low_open_motor_3;
    byte low_close_motor_3;

    byte high_stop_motor_4;
    byte high_open_motor_4;
    byte high_close_motor_4;
    byte low_stop_motor_4;
    byte low_open_motor_4;
    byte low_close_motor_4;

    byte high_stop_motor_5;
    byte high_open_motor_5;
    byte high_close_motor_5;
    byte low_stop_motor_5;
    byte low_open_motor_5;
    byte low_close_motor_5;

    byte high_stop_motor_6;
    byte high_open_motor_6;
    byte high_close_motor_6;
    byte low_stop_motor_6;
    byte low_open_motor_6;
    byte low_close_motor_6;

    byte data_send_motor;
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

#endif
