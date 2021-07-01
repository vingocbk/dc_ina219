#include "motor.h"

uint16_t on_motor_1     = 0b1000000000000000;
// uint16_t 
uint16_t off_motor_1    = 0b0100000000000000;
uint16_t on_motor_2     = 0b0010000000000000;
uint16_t off_motor_2    = 0b0001000000000000;
uint16_t on_motor_3     = 0b0000100000000000;
uint16_t off_motor_3    = 0b0000010000000000;
uint16_t on_motor_4     = 0b0000001000000000;
uint16_t off_motor_4    = 0b0000000100000000;
uint16_t on_motor_5     = 0b0000000010000000;
uint16_t off_motor_5    = 0b0000000001000000;
uint16_t on_motor_6     = 0b0000000000100000;
uint16_t off_motor_6    = 0b0000000000010000;
void initMotor()
{
    pinMode(DATA_PIN_LED, OUTPUT);
    pinMode(LATCH_PIN_LED, OUTPUT);
    pinMode(CLOCK_PIN_LED, OUTPUT);
    pinMode(DATA_PIN_MOTOR, OUTPUT);
    pinMode(LATCH_PIN_MOTOR, OUTPUT);
    pinMode(CLOCK_PIN_MOTOR, OUTPUT);
}
