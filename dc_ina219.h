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

void sendDatatoApp();
void setupPinMode();
void scannerI2cAddress();
void printDataI2c();
void callbackBluetooth(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);
void check_current_motor_1();
void check_current_motor_2();
void check_current_motor_3();
void check_current_motor_4();
void check_current_motor_5();
void check_current_motor_6();


Ticker checkCurrentMotor1(check_current_motor_1, 300);   //every 300ms
Ticker checkCurrentMotor2(check_current_motor_2, 300);   //every 300ms
Ticker checkCurrentMotor3(check_current_motor_3, 300);   //every 300ms
Ticker checkCurrentMotor4(check_current_motor_4, 300);   //every 300ms
Ticker checkCurrentMotor5(check_current_motor_5, 300);   //every 300ms
Ticker checkCurrentMotor6(check_current_motor_6, 300);   //every 300ms
Ticker sendDatatoAppTicker(sendDatatoApp, 500);   //every 300ms

#endif
