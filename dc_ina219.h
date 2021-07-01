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

#endif
