#ifndef DC_INA219_H
#define DC_INA219_H

#include <Arduino.h>
#include "config.h"
#include "AppDebug.h"
#include <Wire.h>
#include <Adafruit_INA219.h>
#include "motor.h"
#include "soc/soc.h"  //Brownout detector was triggered
#include "soc/rtc_cntl_reg.h"
#include "EEPROM.h"
#include "ArduinoJson.h"
#include "BluetoothSerial.h"
#include <Ticker.h>

struct INA219INFO
{
    uint8_t address_ina[MAX_ALL_MOTOR];
    uint8_t count;
};

struct SETUPMOTOR
{
    float value_bus_voltage[MAX_NUMBER_MOTOR];
    float value_current[MAX_NUMBER_MOTOR];    //gia tri hien tai 
    uint8_t define_max_current[MAX_NUMBER_MOTOR];   //gia tri max. neu vuot gia tri nay thi se ngat
    uint8_t define_time_return[MAX_NUMBER_MOTOR];
};

// struct VALUEINA
// {
//     /* data */
// };


struct RUNMOTOR
{
    bool isModeConfig;
    bool beginChangeStep;
    int mode_run_open_step;
    int mode_run_close_step;
};


void readValueIna219();
void sendDatatoApp();
void setupPinMode();
void setupI2c();
void loadDataBegin();
void scannerI2cAddress();
void callbackBluetooth(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);
void check_current_motor_1();
void check_current_motor_2();
void check_current_motor_3();
void check_current_motor_4();
void check_current_motor_5();
void check_current_motor_6();
void returStopMotor1();
void returStopMotor2();
void returStopMotor3();
void returStopMotor4();
void returStopMotor5();
void returStopMotor6();
void tickerUpdate();

Ticker checkCurrentMotor1(check_current_motor_1, 300);   //every 300ms
Ticker checkCurrentMotor2(check_current_motor_2, 300);   //every 300ms
Ticker checkCurrentMotor3(check_current_motor_3, 300);   //every 300ms
Ticker checkCurrentMotor4(check_current_motor_4, 300);   //every 300ms
Ticker checkCurrentMotor5(check_current_motor_5, 300);   //every 300ms
Ticker checkCurrentMotor6(check_current_motor_6, 300);   //every 300ms
Ticker sendDatatoAppTicker(sendDatatoApp, 1000);   //every 500ms

Ticker motorRunReturn1(returStopMotor1, 10);   //every 10ms
Ticker motorRunReturn2(returStopMotor2, 10);   //every 10ms
Ticker motorRunReturn3(returStopMotor3, 10);   //every 10ms
Ticker motorRunReturn4(returStopMotor4, 10);   //every 10ms
Ticker motorRunReturn5(returStopMotor5, 10);   //every 10ms
Ticker motorRunReturn6(returStopMotor6, 10);   //every 10ms

#endif
