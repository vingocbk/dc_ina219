#include "motor.h"


struct motor Set_Motor;
bool motor_is_stop[MAX_NUMBER_MOTOR] = {false,false,false,false,false,false};
uint8_t statusCurrentMotor[MAX_NUMBER_MOTOR] = {MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP};
bool is_done_step()
{
    if(
        motor_is_stop[MOTOR_1]
        && motor_is_stop[MOTOR_2]
        && motor_is_stop[MOTOR_3]
        && motor_is_stop[MOTOR_4]
        && motor_is_stop[MOTOR_5]
        && motor_is_stop[MOTOR_6]
    )
    {
        return true;
    }
    else
    {
        return false;
    }
}

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
    ECHOLN("Stop Motor 1");
    motor_is_stop[MOTOR_1] = true;
    statusCurrentMotor[MOTOR_1] = MOTOR_STOP;
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
    ECHOLN("Stop Motor 2");
    motor_is_stop[MOTOR_2] = true;
    statusCurrentMotor[MOTOR_2] = MOTOR_STOP;
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
    ECHOLN("Stop Motor 3");
    motor_is_stop[MOTOR_3] = true;
    statusCurrentMotor[MOTOR_3] = MOTOR_STOP;
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
    ECHOLN("Stop Motor 4");
    motor_is_stop[MOTOR_4] = true;
    statusCurrentMotor[MOTOR_4] = MOTOR_STOP;
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
    ECHOLN("Stop Motor 5");
    motor_is_stop[MOTOR_5] = true;
    statusCurrentMotor[MOTOR_5] = MOTOR_STOP;
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
    ECHOLN("Stop Motor 6");
    motor_is_stop[MOTOR_6] = true;
    statusCurrentMotor[MOTOR_6] = MOTOR_STOP;
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
    motor_is_stop[MOTOR_1] = false;
    statusCurrentMotor[MOTOR_1] = MOTOR_OPEN;
    ECHOLN("Open Motor 1");
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
    motor_is_stop[MOTOR_2] = false;
    statusCurrentMotor[MOTOR_1] = MOTOR_OPEN;
    ECHOLN("Open Motor 2");
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
    motor_is_stop[MOTOR_3] = false;
    statusCurrentMotor[MOTOR_3] = MOTOR_OPEN;
    ECHOLN("Open Motor 3");
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
    motor_is_stop[MOTOR_4] = false;
    statusCurrentMotor[MOTOR_4] = MOTOR_OPEN;
    ECHOLN("Open Motor 4");
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
    motor_is_stop[MOTOR_5] = false;
    statusCurrentMotor[MOTOR_5] = MOTOR_OPEN;
    ECHOLN("Open Motor 5");
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
    motor_is_stop[MOTOR_6] = false;
    statusCurrentMotor[MOTOR_6] = MOTOR_OPEN;
    ECHOLN("Open Motor 5");
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
    motor_is_stop[MOTOR_1] = false;
    statusCurrentMotor[MOTOR_1] = MOTOR_CLOSE;
    ECHOLN("Close Motor 1");
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
    motor_is_stop[MOTOR_2] = false;
    statusCurrentMotor[MOTOR_2] = MOTOR_CLOSE;
    ECHOLN("Close Motor 2");
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
    motor_is_stop[MOTOR_3] = false;
    statusCurrentMotor[MOTOR_3] = MOTOR_CLOSE;
    ECHOLN("Close Motor 3");
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
    motor_is_stop[MOTOR_4] = false;
    statusCurrentMotor[MOTOR_4] = MOTOR_CLOSE;
    ECHOLN("Close Motor 4");
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
    motor_is_stop[MOTOR_5] = false;
    statusCurrentMotor[MOTOR_5] = MOTOR_CLOSE;
    ECHOLN("Close Motor 5");
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
    motor_is_stop[MOTOR_6] = false;
    statusCurrentMotor[MOTOR_6] = MOTOR_CLOSE;
    ECHOLN("Close Motor 6");
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.low_close_motor_6;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor & Set_Motor.high_close_motor_6;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}
