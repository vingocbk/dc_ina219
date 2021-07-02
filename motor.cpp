#include "motor.h"


struct motor Set_Motor;


void initMotor()
{
    pinMode(DATA_PIN_LED, OUTPUT);
    pinMode(LATCH_PIN_LED, OUTPUT);
    pinMode(CLOCK_PIN_LED, OUTPUT);
    pinMode(DATA_PIN_MOTOR, OUTPUT);
    pinMode(LATCH_PIN_MOTOR, OUTPUT);
    pinMode(CLOCK_PIN_MOTOR, OUTPUT);

    Set_Motor.high_stop_motor_1      = 0b00111111;
    Set_Motor.high_open_motor_1      = 0b10000000;
    Set_Motor.high_close_motor_1     = 0b01000000;
    Set_Motor.low_stop_motor_1       = 0b11111111;
    Set_Motor.low_open_motor_1       = 0b00000000;
    Set_Motor.low_close_motor_1      = 0b00000000;

    Set_Motor.high_stop_motor_2      = 0b11001111;
    Set_Motor.high_open_motor_2      = 0b00100000;
    Set_Motor.high_close_motor_2     = 0b00010000;
    Set_Motor.low_stop_motor_2       = 0b11111111;
    Set_Motor.low_open_motor_2       = 0b00000000;
    Set_Motor.low_close_motor_2      = 0b00000000;

    Set_Motor.high_stop_motor_3      = 0b11110011;
    Set_Motor.high_open_motor_3      = 0b00001000;
    Set_Motor.high_close_motor_3     = 0b00000100;
    Set_Motor.low_stop_motor_3       = 0b11111111;
    Set_Motor.low_open_motor_3       = 0b00000000;
    Set_Motor.low_close_motor_3      = 0b00000000;

    Set_Motor.high_stop_motor_4      = 0b11111100;
    Set_Motor.high_open_motor_4      = 0b00000010;
    Set_Motor.high_close_motor_4     = 0b00000001;
    Set_Motor.low_stop_motor_4       = 0b11111111;
    Set_Motor.low_open_motor_4       = 0b00000000;
    Set_Motor.low_close_motor_4      = 0b00000000;

    Set_Motor.high_stop_motor_5      = 0b11111111;
    Set_Motor.high_open_motor_5      = 0b00000000;
    Set_Motor.high_close_motor_5     = 0b00000000;
    Set_Motor.low_stop_motor_5       = 0b00111111;
    Set_Motor.low_open_motor_5       = 0b10000000;
    Set_Motor.low_close_motor_5      = 0b01000000;

    Set_Motor.high_stop_motor_6      = 0b11111111;
    Set_Motor.high_open_motor_6      = 0b00000000;
    Set_Motor.high_close_motor_6     = 0b00000000;
    Set_Motor.low_stop_motor_6       = 0b11001111;
    Set_Motor.low_open_motor_6       = 0b00100000;
    Set_Motor.low_close_motor_6      = 0b00010000;

    Set_Motor.data_send_motor        = 0b00000000;
}


void stop_motor_1()
{
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_stop_motor_1;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_stop_motor_1;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void stop_motor_2()
{
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_stop_motor_2;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_stop_motor_2;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void stop_motor_3()
{
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_stop_motor_3;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_stop_motor_3;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void stop_motor_4()
{
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_stop_motor_4;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_stop_motor_4;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void stop_motor_5()
{
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_stop_motor_5;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_stop_motor_5;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void stop_motor_6()
{
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_stop_motor_6;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_stop_motor_6;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}

//----------------------------------------------------------------------------------------
void open_motor_1()
{
    stop_motor_1();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_open_motor_1;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_open_motor_1;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void open_motor_2()
{
    stop_motor_2();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_open_motor_2;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_open_motor_2;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void open_motor_3()
{
    stop_motor_3();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_open_motor_3;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_open_motor_3;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void open_motor_4()
{
    stop_motor_4();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_open_motor_4;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_open_motor_4;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void open_motor_5()
{
    stop_motor_5();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_open_motor_5;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_open_motor_5;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void open_motor_6()
{
    stop_motor_6();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_open_motor_6;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_open_motor_6;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}

//----------------------------------------------------------------------------------------
void close_motor_1()
{
    stop_motor_1();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_close_motor_1;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_close_motor_1;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void close_motor_2()
{
    stop_motor_2();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_close_motor_2;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_close_motor_2;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void close_motor_3()
{
    stop_motor_3();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_close_motor_3;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_close_motor_3;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void close_motor_4()
{
    stop_motor_4();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_close_motor_4;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_close_motor_4;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void close_motor_5()
{
    stop_motor_5();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_close_motor_5;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_close_motor_5;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
void close_motor_6()
{
    stop_motor_6();
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_close_motor_6;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_close_motor_6;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
