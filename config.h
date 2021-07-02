#ifndef CONFIG_H
#define CONFIG_H

#define SERIAL_BAUDRATE     115200

#define SCL_PIN             22
#define SDA_PIN             21

#define BTN_IN_M1           4
#define BTN_IN_M2           5
#define BTN_IN_M3           34
#define BTN_IN_M4           15
#define BTN_IN_M5           35
#define BTN_IN_M6           32
#define BTN_IN_M7           33
#define BTN_IN_M8           26
#define BTN_IN_M9           27
#define BTN_IN_M10          12

#define BTN_MODE_SETUP      23
#define BTN_MODE_RUN        25

#define DATA_PIN_LED        16
#define LATCH_PIN_LED       13
#define CLOCK_PIN_LED       14

#define DATA_PIN_MOTOR      19
#define LATCH_PIN_MOTOR     17
#define CLOCK_PIN_MOTOR     18


#define ADDRESS_INA_M1          0x40
#define ADDRESS_INA_M2          0x41
#define ADDRESS_INA_M3          0x42
#define ADDRESS_INA_M4          0x43
#define ADDRESS_INA_M5          0x44
#define ADDRESS_INA_M6          0x45
#define ADDRESS_INA_M7          0x46
#define ADDRESS_INA_M8          0x47
#define ADDRESS_INA_M9          0x48
#define ADDRESS_INA_M10         0x49
#define ADDRESS_INA_M11         0x50

#define MAX_ALL_MOTOR           6
#define MAX_NUMBER_MOTOR        6
// #define MAX_ALL_MOTOR           12

enum
{
    MOTOR_1 = 0,
    MOTOR_2,
    MOTOR_3,
    MOTOR_4,
    MOTOR_5,
    MOTOR_6
};



enum
{
    MOTOR_STOP = 0,
    MOTOR_OPEN,
    MOTOR_CLOSE
};

#endif
