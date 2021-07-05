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
#define MAX_NUMBER_LED          16
#define MAX_RESPONSE_LENGTH     512

#define MAX_SIZE_EEPROM_BUFFER  512
#define EEPROM_MAX_CURRENT_1    1
#define EEPROM_MAX_CURRENT_2    2
#define EEPROM_MAX_CURRENT_3    3
#define EEPROM_MAX_CURRENT_4    4
#define EEPROM_MAX_CURRENT_5    5
#define EEPROM_MAX_CURRENT_6    6
#define EEPROM_TIME_RETURN_1    7
#define EEPROM_TIME_RETURN_2    8
#define EEPROM_TIME_RETURN_3    9
#define EEPROM_TIME_RETURN_4    10
#define EEPROM_TIME_RETURN_5    11
#define EEPROM_TIME_RETURN_6    12
#define EEPROM_MIN_CURRENT_1    13
#define EEPROM_MIN_CURRENT_2    14
#define EEPROM_MIN_CURRENT_3    15
#define EEPROM_MIN_CURRENT_4    16
#define EEPROM_MIN_CURRENT_5    17
#define EEPROM_MIN_CURRENT_6    18



#define VALUE_CONVERT           10

#define MIN_CURRENT_MOTOR       50          //mA

enum
{
    MOTOR_1 = 0,
    MOTOR_2,
    MOTOR_3,
    MOTOR_4,
    MOTOR_5,
    MOTOR_6
};


// #define 
enum
{
    LED_R = 0,
    LED_G,
    LED_B,
    LED_1,
    LED_2,
    LED_3,
    LED_4,
    LED_5,
    LED_6,
    LED_7,
    LED_8,
    LED_9,
    LED_10,
    LED_11,
    LED_12,
};

// int LED_R      = 0;
// int LED_G      = 1;   
// int LED_B      = 2;
// int LED_1      = 3;
// int LED_2      = 4;
// int LED_3      = 5;
// int LED_4      = 6;
// int LED_5      = 7;
// int LED_6      = 8;
// int LED_7      = 9;
// int LED_8      = 10;
// int LED_9      = 11;
// int LED_10     = 12; 
// int LED_11     = 13;
// int LED_12     = 14;

enum
{
    MOTOR_STOP = 0,
    MOTOR_OPEN,
    MOTOR_CLOSE
};

enum
{
    OPEN_STEP_1 = 1,
    OPEN_STEP_2,
    OPEN_STEP_3,
    DONE_MODE_OPEN
};

enum
{
    CLOSE_STEP_1 = 1,
    CLOSE_STEP_2,
    CLOSE_STEP_3,
    DONE_MODE_CLOSE
};


#endif
