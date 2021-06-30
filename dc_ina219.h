#ifndef DC_INA219_H
#define DC_INA219_H

#include <Arduino.h>
#include "config.h"
#include "AppDebug.h"
#include <Wire.h>
#include <Adafruit_INA219.h>


struct INA219INFO
{
    uint8_t address_ina[MAX_ALL_MOTOR];
    uint8_t count;
};


void setupPinMode();
void scannerI2cAddress();
void printDataI2c();

#endif
