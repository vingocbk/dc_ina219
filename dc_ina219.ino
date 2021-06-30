#include "dc_ina219.h"

struct INA219INFO Ina219_info;

Adafruit_INA219 ina219[MAX_ALL_MOTOR];


void setupPinMode()
{
    pinMode(BTN_IN_M1, INPUT);
    pinMode(BTN_IN_M2, INPUT);
    pinMode(BTN_IN_M3, INPUT);
    pinMode(BTN_IN_M4, INPUT);
    pinMode(BTN_IN_M5, INPUT);
    pinMode(BTN_IN_M6, INPUT);
    pinMode(BTN_IN_M7, INPUT);
    pinMode(BTN_IN_M8, INPUT);
    pinMode(BTN_IN_M9, INPUT);
    pinMode(BTN_IN_M10, INPUT);
    pinMode(BTN_MODE_SETUP, INPUT);
    pinMode(BTN_MODE_RUN, INPUT);

    pinMode(DATA_PIN_LED, OUTPUT);
    pinMode(LATCH_PIN_LED, OUTPUT);
    pinMode(CLOCK_PIN_LED, OUTPUT);
    pinMode(DATA_PIN_MOTOR, OUTPUT);
    pinMode(LATCH_PIN_MOTOR, OUTPUT);
    pinMode(CLOCK_PIN_MOTOR, OUTPUT);

    
}





void scannerI2cAddress()
{
    Serial.println ();
    Serial.println ("I2C scanner. Scanning ...");

    Ina219_info.count = 0;
    for (uint8_t i = 8; i < 120; i++)
    {
        Wire.beginTransmission (i);          // Begin I2C transmission Address (i)
        if (Wire.endTransmission () == 0)  // Receive 0 = success (ACK response) 
        {
        Serial.print ("Found address: ");
        Serial.print (i, DEC);
        Serial.print (" (0x");
        Serial.print (i, HEX);     // PCF8574 7 bit address
        Serial.println (")");
        Ina219_info.address_ina[Ina219_info.count] = i;
        Ina219_info.count++;
        }
    }
    Serial.print ("Found ");      
    Serial.print (Ina219_info.count, DEC);        // numbers of devices
    Serial.println (" device(s).");
}


void printDataI2c()
{
    float shuntvoltage = 0;
    float busvoltage = 0;
    float current_mA = 0;
    float loadvoltage = 0;
    float power_mW = 0;

    for (uint8_t i = 0; i < Ina219_info.count; i++)
    {
        shuntvoltage = ina219[i].getShuntVoltage_mV();
        busvoltage = ina219[i].getBusVoltage_V();
        current_mA = ina219[i].getCurrent_mA();
        power_mW = ina219[i].getPower_mW();
        loadvoltage = busvoltage + (shuntvoltage / 1000);
        Serial.printf("Bus Voltage %d:   ", i); Serial.print(busvoltage); Serial.println(" V");
        // Serial.printf("Shunt Voltage %d: ", i); Serial.print(shuntvoltage); Serial.println(" mV");
        // Serial.printf("Load Voltage %d:  ", i); Serial.print(loadvoltage); Serial.println(" V");
        Serial.printf("Current %d:       ", i); Serial.print(current_mA); Serial.println(" mA");
        // Serial.printf("Power %d:         ", i); Serial.print(power_mW); Serial.println(" mW");
        Serial.println("");
    }

    
    
    
}

void setup()
{
    Serial.begin (SERIAL_BAUDRATE);  
    Wire.begin (SDA_PIN, SCL_PIN);   // sda= GPIO_21 /scl= GPIO_22
    
    setupPinMode();

    scannerI2cAddress();
    if(Ina219_info.count > 0)
    {
        for(uint8_t i = 0; i < Ina219_info.count; i++)
        {
            ina219[i] = Adafruit_INA219(Ina219_info.address_ina[i]);
            ina219[i].begin();
            delay(10);
        }
    }


}

bool test = false;
float current_mA_test = 0;
void loop()
{
    // scannerI2cAddress ();
    // printDataI2c();
    // delay (1000);
    if(digitalRead(BTN_IN_M1) && test)
    {   
        delay(200);
        Serial.println("up");
        test = false;
        digitalWrite(LATCH_PIN_MOTOR, LOW);
        shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, 128);   //1000 0000
        digitalWrite(LATCH_PIN_MOTOR, HIGH);    
    }
    else if(!digitalRead(BTN_IN_M1) && !test)
    {
        delay(200);
        Serial.println("down");
        test = true;
        digitalWrite(LATCH_PIN_MOTOR, LOW);
        shiftOut(DATA_PIN_MOTOR, CLOCK_PIN_MOTOR, LSBFIRST, 64);    //0100 0000
        digitalWrite(LATCH_PIN_MOTOR, HIGH);

    }

    
    current_mA_test = ina219[0].getCurrent_mA();
    Serial.printf("Current %f", current_mA_test);
    Serial.println("");
    delay(500);
}
