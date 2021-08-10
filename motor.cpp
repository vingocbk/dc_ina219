#include "motor.h"


struct motor Set_Motor;
bool motor_is_stop[MAX_NUMBER_MOTOR] = {false,false,false,false,false,false,false,false,false};
uint8_t statusCurrentMotor[MAX_NUMBER_MOTOR] = {MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP,MOTOR_STOP};
bool start_check_motor_stop[MAX_NUMBER_MOTOR] = {false,false,false,false,false,false,false,false,false};
bool reverse_motor[MAX_ALL_MOTOR] = {false,false,false,false,false,false,false,false,false};
bool is_done_step()
{
    if(
        motor_is_stop[MOTOR_1]
        && motor_is_stop[MOTOR_2]
        && motor_is_stop[MOTOR_3]
        && motor_is_stop[MOTOR_4]
        && motor_is_stop[MOTOR_5]
        && motor_is_stop[MOTOR_6]
        && motor_is_stop[MOTOR_7]
        && motor_is_stop[MOTOR_8]
        && motor_is_stop[MOTOR_9]
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

    Set_Motor.open_motor[MOTOR_1]          = 0b10000000000000000000000000000000;
    Set_Motor.close_motor[MOTOR_1]         = 0b01000000000000000000000000000000;
    Set_Motor.stop_motor[MOTOR_1]          = 0b00111111111111111111111111111111;

    Set_Motor.open_motor[MOTOR_2]          = 0b00100000000000000000000000000000;
    Set_Motor.close_motor[MOTOR_2]         = 0b00010000000000000000000000000000;
    Set_Motor.stop_motor[MOTOR_2]          = 0b11001111111111111111111111111111;

    Set_Motor.open_motor[MOTOR_3]          = 0b00001000000000000000000000000000;
    Set_Motor.close_motor[MOTOR_3]         = 0b00000100000000000000000000000000;
    Set_Motor.stop_motor[MOTOR_3]          = 0b11110011111111111111111111111111;

    Set_Motor.open_motor[MOTOR_4]          = 0b00000010000000000000000000000000;
    Set_Motor.close_motor[MOTOR_4]         = 0b00000001000000000000000000000000;
    Set_Motor.stop_motor[MOTOR_4]          = 0b11111100111111111111111111111111;

    Set_Motor.open_motor[MOTOR_5]          = 0b00000000100000000000000000000000;
    Set_Motor.close_motor[MOTOR_5]         = 0b00000000010000000000000000000000;
    Set_Motor.stop_motor[MOTOR_5]          = 0b11111111001111111111111111111111;

    Set_Motor.open_motor[MOTOR_6]          = 0b00000000001000000000000000000000;
    Set_Motor.close_motor[MOTOR_6]         = 0b00000000000100000000000000000000;
    Set_Motor.stop_motor[MOTOR_6]          = 0b11111111110011111111111111111111;

    Set_Motor.open_motor[MOTOR_7]          = 0b00000000000010000000000000000000;
    Set_Motor.close_motor[MOTOR_7]         = 0b00000000000001000000000000000000;
    Set_Motor.stop_motor[MOTOR_7]          = 0b11111111111100111111111111111111;

    Set_Motor.open_motor[MOTOR_8]          = 0b00000000000000100000000000000000;
    Set_Motor.close_motor[MOTOR_8]         = 0b00000000000000010000000000000000;
    Set_Motor.stop_motor[MOTOR_8]          = 0b11111111111111001111111111111111;

    Set_Motor.open_motor[MOTOR_9]          = 0b00000000000000001000000000000000;
    Set_Motor.close_motor[MOTOR_9]         = 0b00000000000000000100000000000000;
    Set_Motor.stop_motor[MOTOR_9]          = 0b11111111111111110011111111111111;
    
    Set_Motor.convert_data_motor    = 0;

    //-------------------------------------------------
    Set_Motor.close_led[LED_R]             = 0b0100000000000000;
    Set_Motor.open_led[LED_R]              = 0b1011111111111111;

    Set_Motor.close_led[LED_G]             = 0b0010000000000000;
    Set_Motor.open_led[LED_G]              = 0b1101111111111111;

    Set_Motor.close_led[LED_B]             = 0b0001000000000000;
    Set_Motor.open_led[LED_B]              = 0b1110111111111111;

    Set_Motor.open_led[LED_1]              = 0b0000100000000000;
    Set_Motor.close_led[LED_1]             = 0b1111011111111111;

    Set_Motor.open_led[LED_2]              = 0b0000010000000000;
    Set_Motor.close_led[LED_2]             = 0b1111101111111111;

    Set_Motor.open_led[LED_3]              = 0b0000001000000000;
    Set_Motor.close_led[LED_3]             = 0b1111110111111111;

    Set_Motor.open_led[LED_4]              = 0b0000000100000000;
    Set_Motor.close_led[LED_4]             = 0b1111111011111111;

    Set_Motor.open_led[LED_5]              = 0b0000000010000000;
    Set_Motor.close_led[LED_5]             = 0b1111111101111111;

    Set_Motor.open_led[LED_6]              = 0b0000000001000000;
    Set_Motor.close_led[LED_6]             = 0b1111111110111111;

    Set_Motor.open_led[LED_7]              = 0b0000000000100000;
    Set_Motor.close_led[LED_7]             = 0b1111111111011111;

    Set_Motor.open_led[LED_8]              = 0b0000000000010000;
    Set_Motor.close_led[LED_8]             = 0b1111111111101111;

    Set_Motor.open_led[LED_9]              = 0b0000000000001000;
    Set_Motor.close_led[LED_9]             = 0b1111111111110111;

    Set_Motor.open_led[LED_10]             = 0b0000000000000100;
    Set_Motor.close_led[LED_10]            = 0b1111111111111011;

    Set_Motor.open_led[LED_11]             = 0b0000000000000010;
    Set_Motor.close_led[LED_11]            = 0b1111111111111101;

    Set_Motor.open_led[LED_12]             = 0b0000000000000001;
    Set_Motor.close_led[LED_12]            = 0b1111111111111110;

    Set_Motor.convert_data_led      = 0b1111000000000000;
}


void stop_motor(int number){
    ECHO("Stop Motor ");
    ECHOLN(number + 1);

    motor_is_stop[number] = true;
    statusCurrentMotor[number] = MOTOR_STOP;

    Set_Motor.convert_data_motor = Set_Motor.convert_data_motor & Set_Motor.stop_motor[number];
    Set_Motor.data_send_motor = (char*) &Set_Motor.convert_data_motor;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, *Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);

    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, *(Set_Motor.data_send_motor + 1));
    digitalWrite(LATCH_PIN_MOTOR, HIGH);

    switch (number)
    {
    case MOTOR_1:
        off_led(LED_3);
        break;
    case MOTOR_2:
        off_led(LED_4);
        break;
    case MOTOR_3:
        off_led(LED_5);
        break;
    case MOTOR_4:
        off_led(LED_6);
        break;
    case MOTOR_5:
        off_led(LED_7);
        break;
    case MOTOR_6:
        off_led(LED_8);
        break;
    default:
        break;
    }
}

//----------------------------------------------------------------------------------------
void open_motor(int number)
{
    stop_motor(number);
    motor_is_stop[number] = false;
    statusCurrentMotor[number] = MOTOR_OPEN;
    ECHO("Open Motor ");
    ECHOLN(number + 1);
    Set_Motor.convert_data_motor = Set_Motor.convert_data_motor | Set_Motor.open_motor[number];
    Set_Motor.data_send_motor = (char*) &Set_Motor.convert_data_motor;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, *Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);

    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, *(Set_Motor.data_send_motor + 1));
    digitalWrite(LATCH_PIN_MOTOR, HIGH);

    start_check_motor_stop[number] = true;

    switch (number)
    {
    case MOTOR_1:
        on_led(LED_3);
        break;
    case MOTOR_2:
        on_led(LED_4);
        break;
    case MOTOR_3:
        on_led(LED_5);
        break;
    case MOTOR_4:
        on_led(LED_6);
        break;
    case MOTOR_5:
        on_led(LED_7);
        break;
    case MOTOR_6:
        on_led(LED_8);
        break;
    default:
        break;
    }
}

//----------------------------------------------------------------------------------------
void close_motor(int number)
{
    stop_motor(number);
    motor_is_stop[number] = false;
    statusCurrentMotor[number] = MOTOR_CLOSE;
    ECHO("Close Motor ");
    ECHOLN(number + 1);
    Set_Motor.convert_data_motor = Set_Motor.convert_data_motor | Set_Motor.close_motor[number];
    Set_Motor.data_send_motor = (char*) &Set_Motor.convert_data_motor;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, *Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);

    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, *(Set_Motor.data_send_motor + 1));
    digitalWrite(LATCH_PIN_MOTOR, HIGH);

    start_check_motor_stop[number] = true;
    switch (number)
    {
    case MOTOR_1:
        on_led(LED_3);
        break;
    case MOTOR_2:
        on_led(LED_4);
        break;
    case MOTOR_3:
        on_led(LED_5);
        break;
    case MOTOR_4:
        on_led(LED_6);
        break;
    case MOTOR_5:
        on_led(LED_7);
        break;
    case MOTOR_6:
        on_led(LED_8);
        break;
    default:
        break;
    }
}

//----------------------------------------------------------------------------------------
void on_led(int number)
{
    // ECHO("led: ");
    // ECHOLN(number);
    Set_Motor.convert_data_led = Set_Motor.convert_data_led | Set_Motor.on_led[number];
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);
}

//----------------------------------------------------------------------------------------
void off_led(int number)
{
    // ECHO("led: ");
    // ECHOLN(number);
    Set_Motor.convert_data_led = Set_Motor.convert_data_led & Set_Motor.off_led[number];
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);
}
