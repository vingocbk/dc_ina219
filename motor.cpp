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

    Set_Motor.on_motor_1            = 0b1000000000000000;
    Set_Motor.off_motor_1           = 0b0100000000000000;
    Set_Motor.stop_motor_1          = 0b0011111111111111;

    Set_Motor.on_motor_1            = 0b0010000000000000;
    Set_Motor.off_motor_1           = 0b0001000000000000;
    Set_Motor.stop_motor_1          = 0b1100111111111111;

    Set_Motor.on_motor_1            = 0b0000100000000000;
    Set_Motor.off_motor_1           = 0b0000010000000000;
    Set_Motor.stop_motor_1          = 0b1111001111111111;

    Set_Motor.on_motor_1            = 0b0000001000000000;
    Set_Motor.off_motor_1           = 0b0000000100000000;
    Set_Motor.stop_motor_1          = 0b1111110011111111;

    Set_Motor.on_motor_1            = 0b0000000010000000;
    Set_Motor.off_motor_1           = 0b0000000001000000;
    Set_Motor.stop_motor_1          = 0b1111111100111111;

    Set_Motor.on_motor_1            = 0b0000000000100000;
    Set_Motor.off_motor_1           = 0b0000000000010000;
    Set_Motor.stop_motor_1          = 0b1111111111001111;
    
    Set_Motor.convert_data_motor    = 0;

    //-------------------------------------------------


    Set_Motor.on_led_3              = 0b0000001000000000;
    Set_Motor.off_led_3             = 0b1111110111111111;

    Set_Motor.on_led_4              = 0b0000000100000000;
    Set_Motor.off_led_4             = 0b1111111011111111;

    Set_Motor.on_led_5              = 0b0000000010000000;
    Set_Motor.off_led_5             = 0b1111111101111111;

    Set_Motor.on_led_6              = 0b0000000001000000;
    Set_Motor.off_led_6             = 0b1111111110111111;

    Set_Motor.on_led_7              = 0b0000000000100000;
    Set_Motor.off_led_7             = 0b1111111111011111;

    Set_Motor.on_led_8              = 0b0000000000010000;
    Set_Motor.off_led_8             = 0b1111111111101111;

    Set_Motor.convert_data_led      = 0b1111000000000000;


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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_open_motor_1;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_open_motor_1;
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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_open_motor_2;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_open_motor_2;
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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_open_motor_3;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_open_motor_3;
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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_open_motor_4;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_open_motor_4;
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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_open_motor_5;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_open_motor_5;
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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_open_motor_6;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_open_motor_6;
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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_close_motor_1;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_close_motor_1;
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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_close_motor_2;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_close_motor_2;
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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_close_motor_3;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_close_motor_3;
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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_close_motor_4;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_close_motor_4;
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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_close_motor_5;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_close_motor_5;
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
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.low_close_motor_6;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
    Set_Motor.data_send_motor = Set_Motor.data_send_motor | Set_Motor.high_close_motor_6;
    digitalWrite(LATCH_PIN_MOTOR, LOW);
    shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, Set_Motor.data_send_motor);
    digitalWrite(LATCH_PIN_MOTOR, HIGH);
}


void on_led_motor_1()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led | Set_Motor.on_led_3;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}

void on_led_motor_2()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led | Set_Motor.on_led_4;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led));
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}

void on_led_motor_3()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led | Set_Motor.on_led_5;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}

void on_led_motor_4()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led | Set_Motor.on_led_6;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}

void on_led_motor_5()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led | Set_Motor.on_led_7;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}

void on_led_motor_6()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led | Set_Motor.on_led_8;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}

void off_led_motor_1()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led & Set_Motor.off_led_3;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}

void off_led_motor_2()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led & Set_Motor.off_led_4;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}

void off_led_motor_3()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led & Set_Motor.off_led_5;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}


void off_led_motor_4()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led & Set_Motor.off_led_6;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}

void off_led_motor_5()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led & Set_Motor.off_led_7;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}

void off_led_motor_6()
{
    Set_Motor.convert_data_led = Set_Motor.convert_data_led & Set_Motor.off_led_8;
    Set_Motor.data_send_led = (char*) &Set_Motor.convert_data_led;
    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *Set_Motor.data_send_led);
    digitalWrite(LATCH_PIN_LED, HIGH);

    digitalWrite(LATCH_PIN_LED, LOW);
    shiftOut(DATA_PIN_LED, CLOCK_PIN_LED, LSBFIRST, *(Set_Motor.data_send_led + 1));
    digitalWrite(LATCH_PIN_LED, HIGH);

}
