#include "dc_ina219.h"

BluetoothSerial SerialBT;
struct INA219INFO ina219_info;
struct SETUPMOTOR setup_motor;
struct RUNMOTOR run_motor;
Adafruit_INA219 ina219[MAX_NUMBER_MOTOR];

int count_to_start_check_current[MAX_NUMBER_MOTOR] = {0,0,0,0,0,0};

void readValueIna219()
{
    static uint32_t time_read_value = 0;
    if(millis() >= time_read_value + 100)
    {
        time_read_value = millis();
        setup_motor.value_current[MOTOR_1] = abs(ina219[MOTOR_1].getCurrent_mA());
        setup_motor.value_current[MOTOR_2] = abs(ina219[MOTOR_2].getCurrent_mA());
        setup_motor.value_current[MOTOR_3] = abs(ina219[MOTOR_3].getCurrent_mA());
        setup_motor.value_current[MOTOR_4] = abs(ina219[MOTOR_4].getCurrent_mA());
        setup_motor.value_current[MOTOR_5] = abs(ina219[MOTOR_5].getCurrent_mA());
        setup_motor.value_current[MOTOR_6] = abs(ina219[MOTOR_6].getCurrent_mA());

        setup_motor.value_bus_voltage[MOTOR_1] = abs(ina219[MOTOR_1].getBusVoltage_V());
        setup_motor.value_bus_voltage[MOTOR_2] = abs(ina219[MOTOR_2].getBusVoltage_V());
        setup_motor.value_bus_voltage[MOTOR_3] = abs(ina219[MOTOR_3].getBusVoltage_V());
        setup_motor.value_bus_voltage[MOTOR_4] = abs(ina219[MOTOR_4].getBusVoltage_V());
        setup_motor.value_bus_voltage[MOTOR_5] = abs(ina219[MOTOR_5].getBusVoltage_V());
        setup_motor.value_bus_voltage[MOTOR_6] = abs(ina219[MOTOR_6].getBusVoltage_V());

    }
}


void sendDatatoApp()
{
    String data = "{\"11\":\"";
    data += String(setup_motor.value_bus_voltage[MOTOR_1], 1);
    data += "\",\"21\":\"";
    data += String(setup_motor.value_bus_voltage[MOTOR_2], 1);
    data += "\",\"31\":\"";
    data += String(setup_motor.value_bus_voltage[MOTOR_3], 1);
    data += "\",\"41\":\"";
    data += String(setup_motor.value_bus_voltage[MOTOR_4], 1);
    data += "\",\"51\":\"";
    data += String(setup_motor.value_bus_voltage[MOTOR_5], 1);
    data += "\",\"61\":\"";
    data += String(setup_motor.value_bus_voltage[MOTOR_6], 1);
    //--------------------------
    data += "\",\"12\":\"";
    data += String(setup_motor.value_current[MOTOR_1], 1);
    data += "\",\"22\":\"";
    data += String(setup_motor.value_current[MOTOR_2], 1);
    data += "\",\"32\":\"";
    data += String(setup_motor.value_current[MOTOR_3], 1);
    data += "\",\"42\":\"";
    data += String(setup_motor.value_current[MOTOR_4], 1);
    data += "\",\"52\":\"";
    data += String(setup_motor.value_current[MOTOR_5], 1);
    data += "\",\"62\":\"";
    data += String(setup_motor.value_current[MOTOR_6], 1);
    //------------------------------
    data += "\",\"13\":\"";
    data += String(setup_motor.define_max_current[MOTOR_1]*VALUE_CONVERT);
    data += "\",\"23\":\"";
    data += String(setup_motor.define_max_current[MOTOR_2]*VALUE_CONVERT);
    data += "\",\"33\":\"";
    data += String(setup_motor.define_max_current[MOTOR_3]*VALUE_CONVERT);
    data += "\",\"43\":\"";
    data += String(setup_motor.define_max_current[MOTOR_4]*VALUE_CONVERT);
    data += "\",\"53\":\"";
    data += String(setup_motor.define_max_current[MOTOR_5]*VALUE_CONVERT);
    data += "\",\"63\":\"";
    data += String(setup_motor.define_max_current[MOTOR_6]*VALUE_CONVERT);

    data += "\",\"14\":\"";
    data += String(setup_motor.define_time_return[MOTOR_1]*VALUE_CONVERT);
    data += "\",\"24\":\"";
    data += String(setup_motor.define_time_return[MOTOR_2]*VALUE_CONVERT);
    data += "\",\"34\":\"";
    data += String(setup_motor.define_time_return[MOTOR_3]*VALUE_CONVERT);
    data += "\",\"44\":\"";
    data += String(setup_motor.define_time_return[MOTOR_4]*VALUE_CONVERT);
    data += "\",\"54\":\"";
    data += String(setup_motor.define_time_return[MOTOR_5]*VALUE_CONVERT);
    data += "\",\"64\":\"";
    data += String(setup_motor.define_time_return[MOTOR_6]*VALUE_CONVERT);

    data += "\",\"15\":\"";
    data += String(setup_motor.define_min_current[MOTOR_1]);
    data += "\",\"25\":\"";
    data += String(setup_motor.define_min_current[MOTOR_2]);
    data += "\",\"35\":\"";
    data += String(setup_motor.define_min_current[MOTOR_3]);
    data += "\",\"45\":\"";
    data += String(setup_motor.define_min_current[MOTOR_4]);
    data += "\",\"55\":\"";
    data += String(setup_motor.define_min_current[MOTOR_5]);
    data += "\",\"65\":\"";
    data += String(setup_motor.define_min_current[MOTOR_6]);
    data += "\"}";
    for(int i = 0; i<data.length(); i++){
        SerialBT.write(data[i]);
    }
}

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

    initMotor();
    
}

void setupI2c()
{
    ina219[MOTOR_1] = Adafruit_INA219(ADDRESS_INA_M1);
    ina219[MOTOR_2] = Adafruit_INA219(ADDRESS_INA_M2);
    ina219[MOTOR_3] = Adafruit_INA219(ADDRESS_INA_M3);
    ina219[MOTOR_4] = Adafruit_INA219(ADDRESS_INA_M4);
    ina219[MOTOR_5] = Adafruit_INA219(ADDRESS_INA_M5);
    ina219[MOTOR_6] = Adafruit_INA219(ADDRESS_INA_M6);
    ina219[MOTOR_1].begin();
    ina219[MOTOR_2].begin();
    ina219[MOTOR_3].begin();
    ina219[MOTOR_4].begin();
    ina219[MOTOR_5].begin();
    ina219[MOTOR_6].begin();
    delay(10);
}


void loadDataBegin()
{
    run_motor.isModeConfig = true;
    run_motor.beginChangeStep = true;
    run_motor.mode_run_open_step = OPEN_STEP_1;
    run_motor.mode_run_close_step = CLOSE_STEP_1;

    setup_motor.define_max_current[MOTOR_1] = EEPROM.read(EEPROM_MAX_CURRENT_1);
    ECHO("define_max_current[MOTOR_1] : ");
    ECHOLN(setup_motor.define_max_current[MOTOR_1]*VALUE_CONVERT);
    setup_motor.define_max_current[MOTOR_2] = EEPROM.read(EEPROM_MAX_CURRENT_2);
    ECHO("define_max_current[MOTOR_2] : ");
    ECHOLN(setup_motor.define_max_current[MOTOR_2]*VALUE_CONVERT);
    setup_motor.define_max_current[MOTOR_3] = EEPROM.read(EEPROM_MAX_CURRENT_3);
    ECHO("define_max_current[MOTOR_3] : ");
    ECHOLN(setup_motor.define_max_current[MOTOR_3]*VALUE_CONVERT);
    setup_motor.define_max_current[MOTOR_4] = EEPROM.read(EEPROM_MAX_CURRENT_4);
    ECHO("define_max_current[MOTOR_4] : ");
    ECHOLN(setup_motor.define_max_current[MOTOR_4]*VALUE_CONVERT);
    setup_motor.define_max_current[MOTOR_5] = EEPROM.read(EEPROM_MAX_CURRENT_5);
    ECHO("define_max_current[MOTOR_5] : ");
    ECHOLN(setup_motor.define_max_current[MOTOR_5]*VALUE_CONVERT);
    setup_motor.define_max_current[MOTOR_6] = EEPROM.read(EEPROM_MAX_CURRENT_6);
    ECHO("define_max_current[MOTOR_6] : ");
    ECHOLN(setup_motor.define_max_current[MOTOR_6]*VALUE_CONVERT);
    
    setup_motor.define_time_return[MOTOR_1] = EEPROM.read(EEPROM_TIME_RETURN_1);
    ECHO("time_return[MOTOR_1] : ");
    ECHOLN(setup_motor.define_time_return[MOTOR_1]*VALUE_CONVERT);
    setup_motor.define_time_return[MOTOR_2] = EEPROM.read(EEPROM_TIME_RETURN_2);
    ECHO("time_return[MOTOR_2] : ");
    ECHOLN(setup_motor.define_time_return[MOTOR_2]*VALUE_CONVERT);
    setup_motor.define_time_return[MOTOR_3] = EEPROM.read(EEPROM_TIME_RETURN_3);
    ECHO("time_return[MOTOR_3] : ");
    ECHOLN(setup_motor.define_time_return[MOTOR_3]*VALUE_CONVERT);
    setup_motor.define_time_return[MOTOR_4] = EEPROM.read(EEPROM_TIME_RETURN_4);
    ECHO("time_return[MOTOR_4] : ");
    ECHOLN(setup_motor.define_time_return[MOTOR_4]*VALUE_CONVERT);
    setup_motor.define_time_return[MOTOR_5] = EEPROM.read(EEPROM_TIME_RETURN_5);
    ECHO("time_return[MOTOR_5] : ");
    ECHOLN(setup_motor.define_time_return[MOTOR_5]*VALUE_CONVERT);
    setup_motor.define_time_return[MOTOR_6] = EEPROM.read(EEPROM_TIME_RETURN_6);
    ECHO("time_return[MOTOR_6] : ");
    ECHOLN(setup_motor.define_time_return[MOTOR_6]*VALUE_CONVERT);

    setup_motor.define_min_current[MOTOR_1] = EEPROM.read(EEPROM_MIN_CURRENT_1);
    ECHO("define_min_current[MOTOR_1] : ");
    ECHOLN(setup_motor.define_min_current[MOTOR_1]);
    setup_motor.define_min_current[MOTOR_2] = EEPROM.read(EEPROM_MIN_CURRENT_2);
    ECHO("define_min_current[MOTOR_2] : ");
    ECHOLN(setup_motor.define_min_current[MOTOR_2]);
    setup_motor.define_min_current[MOTOR_3] = EEPROM.read(EEPROM_MIN_CURRENT_3);
    ECHO("define_min_current[MOTOR_3] : ");
    ECHOLN(setup_motor.define_min_current[MOTOR_3]);
    setup_motor.define_min_current[MOTOR_4] = EEPROM.read(EEPROM_MIN_CURRENT_4);
    ECHO("define_min_current[MOTOR_4] : ");
    ECHOLN(setup_motor.define_min_current[MOTOR_4]);
    setup_motor.define_min_current[MOTOR_5] = EEPROM.read(EEPROM_MIN_CURRENT_5);
    ECHO("define_min_current[MOTOR_5] : ");
    ECHOLN(setup_motor.define_min_current[MOTOR_5]);
    setup_motor.define_min_current[MOTOR_6] = EEPROM.read(EEPROM_MIN_CURRENT_6);
    ECHO("define_min_current[MOTOR_6] : ");
    ECHOLN(setup_motor.define_max_current[MOTOR_6]);
}


void scannerI2cAddress()
{
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
    ECHOLN ();
    ECHOLN ("I2C scanner. Scanning ...");

    ina219_info.count = 0;
    for (uint8_t i = 8; i < 120; i++)
    {
        Wire.beginTransmission (i);          // Begin I2C transmission Address (i)
        if (Wire.endTransmission () == 0)  // Receive 0 = success (ACK response) 
        {
        Serial.print ("Found address: ");
        Serial.print (i, DEC);
        Serial.print (" (0x");
        Serial.print (i, HEX);     // PCF8574 7 bit address
        ECHOLN (")");
        ina219_info.address_ina[ina219_info.count] = i;
        ina219_info.count++;
        }
    }
    Serial.print ("Found ");      
    Serial.print (ina219_info.count, DEC);        // numbers of devices
    ECHOLN (" device(s).");
}




void callbackBluetooth(esp_spp_cb_event_t event, esp_spp_cb_param_t *param)
{
    switch (event)
	{
	case ESP_SPP_SRV_OPEN_EVT:
		ECHOLN("Client Connected");
        sendDatatoAppTicker.start();
		break;
    case ESP_SPP_CLOSE_EVT:
        ECHOLN("Client Disconnected");
        sendDatatoAppTicker.stop();
		break;
	case ESP_SPP_DATA_IND_EVT:	
		if (param->data_ind.len < MAX_RESPONSE_LENGTH) 
        {
            String data;
            for(int i = 0; i < param->data_ind.len; i++)
            {
                data += (char)param->data_ind.data[i];
            }
            ECHO("data bluetooth: ");
            ECHOLN(data);
            StaticJsonBuffer<MAX_RESPONSE_LENGTH> jsonBuffer;
            JsonObject& rootData = jsonBuffer.parseObject(data);
            if(run_motor.isModeConfig)
            {
				if (rootData.success())
                {
					String type = rootData["type"];
					String name = rootData["name"];
                    if(type == "run_no_step")
                    {
                        String data = rootData["command"];
                        if(name == "motor1")
                        {
                            if(data == "open")
                            {
                                open_motor(MOTOR_1);
                                // checkCurrentMotor1.start();
                            }
                            else if(data == "stop")
                            {
                                stop_motor(MOTOR_1);
                                checkCurrentMotor1.stop();
                                count_to_start_check_current[MOTOR_1] = 0;
                            }
                            else if(data == "close")
                            {
                                close_motor(MOTOR_1);
                                // checkCurrentMotor1.start();
                            }
                        }
                        else if(name == "motor2")
                        {
                            if(data == "open")
                            {
                                open_motor(MOTOR_2);
                                // checkCurrentMotor2.start();
                            }
                            else if(data == "stop")
                            {
                                stop_motor(MOTOR_2);
                                checkCurrentMotor2.stop();
                                count_to_start_check_current[MOTOR_2] = 0;
                            }
                            else if(data == "close")
                            {
                                close_motor(MOTOR_2);
                                // checkCurrentMotor2.start();
                            }
                        }
                        else if(name == "motor3")
                        {
                            if(data == "open")
                            {
                                open_motor(MOTOR_3);
                                // checkCurrentMotor3.start();
                            }
                            else if(data == "stop")
                            {
                                stop_motor(MOTOR_3);
                                checkCurrentMotor3.stop();
                                count_to_start_check_current[MOTOR_3] = 0;
                            }
                            else if(data == "close")
                            {
                                close_motor(MOTOR_3);
                                // checkCurrentMotor3.start();
                            }
                        }
                        else if(name == "motor4")
                        {
                            if(data == "open")
                            {
                                open_motor(MOTOR_4);
                                // checkCurrentMotor4.start();
                            }
                            else if(data == "stop")
                            {
                                stop_motor(MOTOR_4);
                                checkCurrentMotor4.stop();
                                count_to_start_check_current[MOTOR_4] = 0;
                            }
                            else if(data == "close")
                            {
                                close_motor(MOTOR_4);
                                // checkCurrentMotor4.start();
                            }
                        }
                        else if(name == "motor5")
                        {
                            if(data == "open")
                            {
                                open_motor(MOTOR_5);
                                // checkCurrentMotor5.start();
                            }
                            else if(data == "stop")
                            {
                                stop_motor(MOTOR_5);
                                checkCurrentMotor5.stop();
                                count_to_start_check_current[MOTOR_5] = 0;
                            }
                            else if(data == "close")
                            {
                                close_motor(MOTOR_5);
                                // checkCurrentMotor5.start();
                            }
                        }
                        else if(name == "motor6")
                        {
                            if(data == "open")
                            {
                                open_motor(MOTOR_6);
                                // checkCurrentMotor6.start();
                            }
                            else if(data == "stop")
                            {
                                stop_motor(MOTOR_6);
                                checkCurrentMotor6.stop();
                                count_to_start_check_current[MOTOR_6] = 0;
                            }
                            else if(data == "close")
                            {
                                close_motor(MOTOR_6);
                                // checkCurrentMotor6.start();
                            }
                        }
                    }
                    else if(type == "save_data")
                    {
                        String max_current = rootData["max_current"];
                        String min_current = rootData["min_current"];
                        String time_return = rootData["time_return"];
                        if(name == "0")
                        {
                            if(max_current != "")
                            {
                                setup_motor.define_max_current[MOTOR_1] = max_current.toInt()/VALUE_CONVERT;
                                // ECHOLN(setup_motor.define_max_current[MOTOR_1]);
                                EEPROM.write(EEPROM_MAX_CURRENT_1,setup_motor.define_max_current[MOTOR_1]);
                            }
                            if(min_current != "")
                            {
                                setup_motor.define_min_current[MOTOR_1] = min_current.toInt();
                                // ECHOLN(setup_motor.define_max_current[MOTOR_1]);
                                EEPROM.write(EEPROM_MIN_CURRENT_1,setup_motor.define_min_current[MOTOR_1]);
                            }
                            if(time_return != "")
                            {
                                setup_motor.define_time_return[MOTOR_1] = time_return.toInt()/VALUE_CONVERT;
                                // ECHOLN(setup_motor.define_time_return[MOTOR_1]);
                                EEPROM.write(EEPROM_TIME_RETURN_1,setup_motor.define_time_return[MOTOR_1]);
                            }
                        }
                        else if(name == "1")
                        {
                            if(max_current != "")
                            {
                                setup_motor.define_max_current[MOTOR_2] = max_current.toInt()/VALUE_CONVERT;
                                EEPROM.write(EEPROM_MAX_CURRENT_2,setup_motor.define_max_current[MOTOR_2]);
                            }
                            if(min_current != "")
                            {
                                setup_motor.define_min_current[MOTOR_2] = min_current.toInt();
                                // ECHOLN(setup_motor.define_max_current[MOTOR_2]);
                                EEPROM.write(EEPROM_MIN_CURRENT_2,setup_motor.define_min_current[MOTOR_2]);
                            }
                            if(time_return != "")
                            {
                                setup_motor.define_time_return[MOTOR_2] = time_return.toInt()/VALUE_CONVERT;
                                EEPROM.write(EEPROM_TIME_RETURN_2,setup_motor.define_time_return[MOTOR_2]);
                            }
                        }
                        else if(name == "2")
                        {
                            if(max_current != "")
                            {
                                setup_motor.define_max_current[MOTOR_3] = max_current.toInt()/VALUE_CONVERT;
                                EEPROM.write(EEPROM_MAX_CURRENT_3,setup_motor.define_max_current[MOTOR_3]);
                            }
                            if(min_current != "")
                            {
                                setup_motor.define_min_current[MOTOR_3] = min_current.toInt();
                                // ECHOLN(setup_motor.define_max_current[MOTOR_3]);
                                EEPROM.write(EEPROM_MIN_CURRENT_3,setup_motor.define_min_current[MOTOR_3]);
                            }
                            if(time_return != "")
                            {
                                setup_motor.define_time_return[MOTOR_3] = time_return.toInt()/VALUE_CONVERT;
                                EEPROM.write(EEPROM_TIME_RETURN_3,setup_motor.define_time_return[MOTOR_3]);
                            }
                        }
                        else if(name == "3")
                        {
                            if(max_current != "")
                            {
                                setup_motor.define_max_current[MOTOR_4] = max_current.toInt()/VALUE_CONVERT;
                                EEPROM.write(EEPROM_MAX_CURRENT_4,setup_motor.define_max_current[MOTOR_4]);
                            }
                            if(min_current != "")
                            {
                                setup_motor.define_min_current[MOTOR_4] = min_current.toInt();
                                // ECHOLN(setup_motor.define_max_current[MOTOR_4]);
                                EEPROM.write(EEPROM_MIN_CURRENT_4,setup_motor.define_min_current[MOTOR_4]);
                            }
                            if(time_return != "")
                            {
                                setup_motor.define_time_return[MOTOR_4] = time_return.toInt()/VALUE_CONVERT;
                                EEPROM.write(EEPROM_TIME_RETURN_4,setup_motor.define_time_return[MOTOR_4]);
                            }
                        }
                        else if(name == "4")
                        {
                            if(max_current != "")
                            {
                                setup_motor.define_max_current[MOTOR_5] = max_current.toInt()/VALUE_CONVERT;
                                EEPROM.write(EEPROM_MAX_CURRENT_5,setup_motor.define_max_current[MOTOR_5]);
                            }
                            if(min_current != "")
                            {
                                setup_motor.define_min_current[MOTOR_5] = min_current.toInt();
                                // ECHOLN(setup_motor.define_max_current[MOTOR_5]);
                                EEPROM.write(EEPROM_MIN_CURRENT_5,setup_motor.define_min_current[MOTOR_5]);
                            }
                            if(time_return != "")
                            {
                                setup_motor.define_time_return[MOTOR_5] = time_return.toInt()/VALUE_CONVERT;
                                EEPROM.write(EEPROM_TIME_RETURN_5,setup_motor.define_time_return[MOTOR_5]);
                            }
                        }
                        else if(name == "5")
                        {
                            if(max_current != "")
                            {
                                setup_motor.define_max_current[MOTOR_6] = max_current.toInt()/VALUE_CONVERT;
                                EEPROM.write(EEPROM_MAX_CURRENT_6,setup_motor.define_max_current[MOTOR_6]);
                            }
                            if(min_current != "")
                            {
                                setup_motor.define_min_current[MOTOR_6] = min_current.toInt();
                                // ECHOLN(setup_motor.define_max_current[MOTOR_6]);
                                EEPROM.write(EEPROM_MIN_CURRENT_6,setup_motor.define_min_current[MOTOR_6]);
                            }
                            if(time_return != "")
                            {
                                setup_motor.define_time_return[MOTOR_6] = time_return.toInt()/VALUE_CONVERT;
                                EEPROM.write(EEPROM_TIME_RETURN_6,setup_motor.define_time_return[MOTOR_6]);
                            }
                        }
                        EEPROM.commit();
                    }
                }
            }

        }
        break;
    default:
        break;
    }
}

void check_current_motor_1()
{
    uint8_t status_forward;
    status_forward = statusCurrentMotor[MOTOR_1];
    count_to_start_check_current[MOTOR_1]++;
    if(count_to_start_check_current[MOTOR_1] >= 5)
    {
         if(int(setup_motor.value_current[MOTOR_1]) < setup_motor.define_min_current[MOTOR_1] 
         || int(setup_motor.value_current[MOTOR_1]) > (setup_motor.define_max_current[MOTOR_1]*VALUE_CONVERT))
//        if(int(setup_motor.value_current[MOTOR_1]) > (setup_motor.define_max_current[MOTOR_1]*VALUE_CONVERT))
        {   
            count_to_start_check_current[MOTOR_1] = 0;
            ECHOLN("Qua Tai Motor 1");
            stop_motor(MOTOR_1);
            if(is_done_step())
            {
                run_motor.mode_run_open_step++;
                run_motor.mode_run_close_step++;
                run_motor.beginChangeStep = true;
            }
            checkCurrentMotor1.stop();
            if(setup_motor.define_time_return[MOTOR_1] != 0 && setup_motor.define_time_return[MOTOR_1] != 255)
            {
                if(status_forward == MOTOR_OPEN)
                {
                    close_motor(MOTOR_1);
                    start_check_motor_stop[MOTOR_1] = false;    //luc return thi khong check van toc nua
                    motorRunReturn1.start();
                }
                else if(status_forward == MOTOR_CLOSE)
                {
                    open_motor(MOTOR_1);
                    start_check_motor_stop[MOTOR_1] = false;    //luc return thi khong check van toc nua
                    motorRunReturn1.start();
                }
            }
        }
    }
}

void check_current_motor_2()
{
    uint8_t status_forward;
    status_forward = statusCurrentMotor[MOTOR_2];
    count_to_start_check_current[MOTOR_2]++;
    if(count_to_start_check_current[MOTOR_2] >= 5)
    {
         if(int(setup_motor.value_current[MOTOR_2]) < setup_motor.define_min_current[MOTOR_2] 
         || int(setup_motor.value_current[MOTOR_2]) > (setup_motor.define_max_current[MOTOR_2]*VALUE_CONVERT))
//        if(int(setup_motor.value_current[MOTOR_2]) > (setup_motor.define_max_current[MOTOR_2]*VALUE_CONVERT))
        {   
            count_to_start_check_current[MOTOR_2] = 0;
            ECHOLN("Qua Tai Motor 2");
            stop_motor(MOTOR_2);
            if(is_done_step())
            {
                run_motor.mode_run_open_step++;
                run_motor.mode_run_close_step++;
                run_motor.beginChangeStep = true;
            }
            checkCurrentMotor2.stop();
            if(setup_motor.define_time_return[MOTOR_2] != 0 && setup_motor.define_time_return[MOTOR_2] != 255)
            {
                if(status_forward == MOTOR_OPEN)
                {
                    close_motor(MOTOR_2);
                    start_check_motor_stop[MOTOR_2] = false;    //luc return thi khong check van toc nua
                    motorRunReturn2.start();
                }
                else if(status_forward == MOTOR_CLOSE)
                {
                    open_motor(MOTOR_2);
                    start_check_motor_stop[MOTOR_2] = false;    //luc return thi khong check van toc nua
                    motorRunReturn2.start();
                }
            }
        }
    }
}

void check_current_motor_3()
{
    uint8_t status_forward;
    status_forward = statusCurrentMotor[MOTOR_3];
    count_to_start_check_current[MOTOR_3]++;
    if(count_to_start_check_current[MOTOR_3] >= 5)
    {
        if(int(setup_motor.value_current[MOTOR_3]) < setup_motor.define_min_current[MOTOR_3] 
        || int(setup_motor.value_current[MOTOR_3]) > (setup_motor.define_max_current[MOTOR_3]*VALUE_CONVERT))
        // if(int(setup_motor.value_current[MOTOR_3]) > (setup_motor.define_max_current[MOTOR_3]*VALUE_CONVERT))
        {   
            count_to_start_check_current[MOTOR_3] = 0;
            ECHOLN("Qua Tai Motor 3");
            stop_motor(MOTOR_3);
            if(is_done_step())
            {
                run_motor.mode_run_open_step++;
                run_motor.mode_run_close_step++;
                run_motor.beginChangeStep = true;
            }
            checkCurrentMotor3.stop();
            if(setup_motor.define_time_return[MOTOR_3] != 0 && setup_motor.define_time_return[MOTOR_3] != 255)
            {
                if(status_forward == MOTOR_OPEN)
                {
                    close_motor(MOTOR_3);
                    start_check_motor_stop[MOTOR_3] = false;    //luc return thi khong check van toc nua
                    motorRunReturn3.start();
                }
                else if(status_forward == MOTOR_CLOSE)
                {
                    open_motor(MOTOR_3);
                    start_check_motor_stop[MOTOR_3] = false;    //luc return thi khong check van toc nua
                    motorRunReturn3.start();
                }
            }
        }
    }
}

void check_current_motor_4()
{
    uint8_t status_forward;
    status_forward = statusCurrentMotor[MOTOR_4];
    count_to_start_check_current[MOTOR_4]++;
    if(count_to_start_check_current[MOTOR_4] >= 5)
    {
        if(int(setup_motor.value_current[MOTOR_4]) < setup_motor.define_min_current[MOTOR_4] 
        || int(setup_motor.value_current[MOTOR_4]) > (setup_motor.define_max_current[MOTOR_4]*VALUE_CONVERT))
        // if(int(setup_motor.value_current[MOTOR_4]) > (setup_motor.define_max_current[MOTOR_4]*VALUE_CONVERT))
        {   
            count_to_start_check_current[MOTOR_4] = 0;
            ECHOLN("Qua Tai Motor 4");
            stop_motor(MOTOR_4);
            if(is_done_step())
            {
                run_motor.mode_run_open_step++;
                run_motor.mode_run_close_step++;
                run_motor.beginChangeStep = true;
            }
            checkCurrentMotor4.stop();
            if(setup_motor.define_time_return[MOTOR_4] != 0 && setup_motor.define_time_return[MOTOR_4] != 255)
            {
                if(status_forward == MOTOR_OPEN)
                {
                    close_motor(MOTOR_4);
                    start_check_motor_stop[MOTOR_4] = false;    //luc return thi khong check van toc nua
                    motorRunReturn4.start();
                }
                else if(status_forward == MOTOR_CLOSE)
                {
                    open_motor(MOTOR_4);
                    start_check_motor_stop[MOTOR_4] = false;    //luc return thi khong check van toc nua
                    motorRunReturn4.start();
                }
            }
        }
    }
}

void check_current_motor_5()
{
    uint8_t status_forward;
    status_forward = statusCurrentMotor[MOTOR_5];
    count_to_start_check_current[MOTOR_5]++;
    if(count_to_start_check_current[MOTOR_5] >= 5)
    {
        if(int(setup_motor.value_current[MOTOR_5]) < setup_motor.define_min_current[MOTOR_5] 
        || int(setup_motor.value_current[MOTOR_5]) > (setup_motor.define_max_current[MOTOR_5]*VALUE_CONVERT))
        // if(int(setup_motor.value_current[MOTOR_5]) > (setup_motor.define_max_current[MOTOR_5]*VALUE_CONVERT))
        {   
            count_to_start_check_current[MOTOR_5] = 0;
            ECHOLN("Qua Tai Motor 5");
            stop_motor(MOTOR_5);
            if(is_done_step())
            {
                run_motor.mode_run_open_step++;
                run_motor.mode_run_close_step++;
                run_motor.beginChangeStep = true;
            }
            checkCurrentMotor5.stop();
            if(setup_motor.define_time_return[MOTOR_5] != 0 && setup_motor.define_time_return[MOTOR_5] != 255)
            {
                if(status_forward == MOTOR_OPEN)
                {
                    close_motor(MOTOR_5);
                    start_check_motor_stop[MOTOR_5] = false;    //luc return thi khong check van toc nua
                    motorRunReturn5.start();
                }
                else if(status_forward == MOTOR_CLOSE)
                {
                    open_motor(MOTOR_5);
                    start_check_motor_stop[MOTOR_5] = false;    //luc return thi khong check van toc nua
                    motorRunReturn5.start();
                }
            }
        }
    }
}

void check_current_motor_6()
{
    uint8_t status_forward;
    status_forward = statusCurrentMotor[MOTOR_6];
    count_to_start_check_current[MOTOR_6]++;
    if(count_to_start_check_current[MOTOR_6] >= 5)
    {
        if(int(setup_motor.value_current[MOTOR_6]) < setup_motor.define_min_current[MOTOR_6] 
        || int(setup_motor.value_current[MOTOR_6]) > (setup_motor.define_max_current[MOTOR_6]*VALUE_CONVERT))
        // if(int(setup_motor.value_current[MOTOR_6]) > (setup_motor.define_max_current[MOTOR_6]*VALUE_CONVERT))
        {   
            count_to_start_check_current[MOTOR_6] = 0;
            ECHOLN("Qua Tai Motor 6");
            stop_motor(MOTOR_6);
            if(is_done_step())
            {
                run_motor.mode_run_open_step++;
                run_motor.mode_run_close_step++;
                run_motor.beginChangeStep = true;
            }
            checkCurrentMotor6.stop();
            if(setup_motor.define_time_return[MOTOR_6] != 0 && setup_motor.define_time_return[MOTOR_6] != 255)
            {
                if(status_forward == MOTOR_OPEN)
                {
                    close_motor(MOTOR_6);
                    start_check_motor_stop[MOTOR_6] = false;    //luc return thi khong check van toc nua
                    motorRunReturn6.start();
                }
                else if(status_forward == MOTOR_CLOSE)
                {
                    open_motor(MOTOR_6);
                    start_check_motor_stop[MOTOR_6] = false;    //luc return thi khong check van toc nua
                    motorRunReturn6.start();
                }
            }
        }
    }
}

void returStopMotor1()
{
    static uint8_t return_stop_motor_1 = 0;
    return_stop_motor_1++;
    if(return_stop_motor_1 == setup_motor.define_time_return[MOTOR_1])
    {
        return_stop_motor_1 = 0;
        stop_motor(MOTOR_1);
        motorRunReturn1.stop();
    }
}
void returStopMotor2()
{
    static uint8_t return_stop_motor_2 = 0;
    return_stop_motor_2++;
    if(return_stop_motor_2 == setup_motor.define_time_return[MOTOR_2])
    {
        return_stop_motor_2 = 0;
        stop_motor(MOTOR_2);
        motorRunReturn2.stop();
    }
}
void returStopMotor3()
{
    static uint8_t return_stop_motor_3 = 0;
    return_stop_motor_3++;
    if(return_stop_motor_3 == setup_motor.define_time_return[MOTOR_3])
    {
        return_stop_motor_3 = 0;
        stop_motor(MOTOR_3);
        motorRunReturn3.stop();
    }
}
void returStopMotor4()
{
    static uint8_t return_stop_motor_4 = 0;
    return_stop_motor_4++;
    if(return_stop_motor_4 == setup_motor.define_time_return[MOTOR_4])
    {
        return_stop_motor_4 = 0;
        stop_motor(MOTOR_4);
        motorRunReturn4.stop();
    }
}
void returStopMotor5()
{
    static uint8_t return_stop_motor_5 = 0;
    return_stop_motor_5++;
    if(return_stop_motor_5 == setup_motor.define_time_return[MOTOR_5])
    {
        return_stop_motor_5 = 0;
        stop_motor(MOTOR_5);
        motorRunReturn5.stop();
    }
}
void returStopMotor6()
{
    static uint8_t return_stop_motor_6 = 0;
    return_stop_motor_6++;
    if(return_stop_motor_6 == setup_motor.define_time_return[MOTOR_6])
    {
        return_stop_motor_6 = 0;
        stop_motor(MOTOR_6);
        motorRunReturn6.stop();
    }
}


void checkButtonControl()
{
    // static bool test[MAX_NUMBER_MOTOR] = {false,false,false,false,false,false};
    static unsigned int count[MAX_NUMBER_MOTOR] = {0,0,0,0,0,0};

    if(!digitalRead(BTN_IN_M1))
    {
        while (!digitalRead(BTN_IN_M1))
        {
            delay(10);
        }
        count[MOTOR_1] ++;
        if(count[MOTOR_1] == 1)
        {
            open_motor(MOTOR_1);
        }
        else if(count[MOTOR_1] == 2)
        {
            stop_motor(MOTOR_1);
        }
        else if(count[MOTOR_1] == 3)
        {
            close_motor(MOTOR_1);
        }
        else if(count[MOTOR_1] == 4)
        {
            count[MOTOR_1] = 0;
            stop_motor(MOTOR_1);
        }
    }

    if(!digitalRead(BTN_IN_M2))
    {
        while (!digitalRead(BTN_IN_M2))
        {
            delay(10);
        }
        count[MOTOR_2] ++;
        if(count[MOTOR_2] == 1)
        {
            open_motor(MOTOR_2);
        }
        else if(count[MOTOR_2] == 2)
        {
            stop_motor(MOTOR_2);
        }
        else if(count[MOTOR_2] == 3)
        {
            close_motor(MOTOR_2);
        }
        else if(count[MOTOR_2] == 4)
        {
            count[MOTOR_2] = 0;
            stop_motor(MOTOR_2);
        }
    }

    if(!digitalRead(BTN_IN_M3))
    {
        while (!digitalRead(BTN_IN_M3))
        {
            delay(10);
        }
        count[MOTOR_3] ++;
        if(count[MOTOR_3] == 1)
        {
            open_motor(MOTOR_3);
        }
        else if(count[MOTOR_3] == 2)
        {
            stop_motor(MOTOR_3);
        }
        else if(count[MOTOR_3] == 3)
        {
            close_motor(MOTOR_3);
        }
        else if(count[MOTOR_3] == 4)
        {
            count[MOTOR_3] = 0;
            stop_motor(MOTOR_3);
        }
    }

    if(!digitalRead(BTN_IN_M4))
    {
        while (!digitalRead(BTN_IN_M4))
        {
            delay(10);
        }
        count[MOTOR_4] ++;
        if(count[MOTOR_4] == 1)
        {
            open_motor(MOTOR_4);
        }
        else if(count[MOTOR_4] == 2)
        {
            stop_motor(MOTOR_4);
        }
        else if(count[MOTOR_4] == 3)
        {
            close_motor(MOTOR_4);
        }
        else if(count[MOTOR_4] == 4)
        {
            count[MOTOR_4] = 0;
            stop_motor(MOTOR_4);
        }
    }

    if(!digitalRead(BTN_IN_M5))
    {
        while (!digitalRead(BTN_IN_M5))
        {
            delay(10);
        }
        count[MOTOR_5] ++;
        if(count[MOTOR_5] == 1)
        {
            open_motor(MOTOR_5);
        }
        else if(count[MOTOR_5] == 2)
        {
            stop_motor(MOTOR_5);
        }
        else if(count[MOTOR_5] == 3)
        {
            close_motor(MOTOR_5);
        }
        else if(count[MOTOR_5] == 4)
        {
            count[MOTOR_5] = 0;
            stop_motor(MOTOR_5);
        }
    }

    if(!digitalRead(BTN_IN_M6))
    {
        while (!digitalRead(BTN_IN_M6))
        {
            delay(10);
        }
        count[MOTOR_6] ++;
        if(count[MOTOR_6] == 1)
        {
            open_motor(MOTOR_6);
        }
        else if(count[MOTOR_6] == 2)
        {
            stop_motor(MOTOR_6);
        }
        else if(count[MOTOR_6] == 3)
        {
            close_motor(MOTOR_6);
        }
        else if(count[MOTOR_6] == 4)
        {
            count[MOTOR_6] = 0;
            stop_motor(MOTOR_6);
        }
    }
    

}

void checkStartCalCurrent()
{
    if(start_check_motor_stop[MOTOR_1])
    {
        start_check_motor_stop[MOTOR_1] = false;
        checkCurrentMotor1.start();
    }
    if(start_check_motor_stop[MOTOR_2])
    {
        start_check_motor_stop[MOTOR_2] = false;
        checkCurrentMotor2.start();
    }
    if(start_check_motor_stop[MOTOR_3])
    {
        start_check_motor_stop[MOTOR_3] = false;
        checkCurrentMotor3.start();
    }
    if(start_check_motor_stop[MOTOR_4])
    {
        start_check_motor_stop[MOTOR_4] = false;
        checkCurrentMotor4.start();
    }
    if(start_check_motor_stop[MOTOR_5])
    {
        start_check_motor_stop[MOTOR_5] = false;
        checkCurrentMotor5.start();
    }
    if(start_check_motor_stop[MOTOR_6])
    {
        start_check_motor_stop[MOTOR_6] = false;
        checkCurrentMotor6.start();
    }
}

void tickerUpdate()
{
    sendDatatoAppTicker.update();
    checkCurrentMotor1.update();
    checkCurrentMotor2.update();
    checkCurrentMotor3.update();
    checkCurrentMotor4.update();
    checkCurrentMotor5.update();
    checkCurrentMotor6.update();
    motorRunReturn1.update();
    motorRunReturn2.update();
    motorRunReturn3.update();
    motorRunReturn4.update();
    motorRunReturn5.update();
    motorRunReturn6.update();
    sendDatatoAppTicker.update();
}

void checkButtonConfigModeRun()
{
    static bool check_mode_setup = true;
    if(!digitalRead(BTN_MODE_SETUP) && check_mode_setup)
    {
        delay(100);
        ECHOLN("MODE SETUP");
        check_mode_setup = false;
        run_motor.isModeConfig = true;
    }
    else if(digitalRead(BTN_MODE_SETUP) && !check_mode_setup)
    {
        delay(100);
        ECHOLN("MODE RUN");
        check_mode_setup = true;
        run_motor.isModeConfig = false;
    }
}

void setup()
{
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  //Brownout detector was triggered
    Serial.begin (SERIAL_BAUDRATE);  
    Wire.begin (SDA_PIN, SCL_PIN);   // sda= GPIO_21 /scl= GPIO_22
    EEPROM.begin(MAX_SIZE_EEPROM_BUFFER);
    setupPinMode();
    scannerI2cAddress();
    setupI2c();
    loadDataBegin();

    SerialBT.flush();
    SerialBT.end(); 
    if(!SerialBT.begin("Test Motor")){
        ECHOLN("An error occurred initializing Bluetooth");
    }else{
        ECHOLN("Bluetooth initialized");
    }
	SerialBT.register_callback(callbackBluetooth);

    for(int i = 0; i < MAX_NUMBER_MOTOR; i++)
    {
        stop_motor(i);
    }


}



void loop()
{
    
    readValueIna219();
    tickerUpdate();
    checkStartCalCurrent();
    
    checkButtonConfigModeRun();

    if(!run_motor.isModeConfig)
    {
        if(digitalRead(BTN_MODE_RUN))
        {
            run_motor.mode_run_close_step = CLOSE_STEP_1;
            switch (run_motor.mode_run_open_step)
            {
            case OPEN_STEP_1:
                if(run_motor.beginChangeStep)
                {
                    ECHOLN("START MODE RUN OPEN STEP 1");
                    run_motor.beginChangeStep = false;
                    open_motor(MOTOR_1);
                    // checkCurrentMotor1.start();
                    open_motor(MOTOR_2);
                    // checkCurrentMotor2.start();
                    open_motor(MOTOR_3);
                    // checkCurrentMotor3.start();
                    stop_motor(MOTOR_4);
                    stop_motor(MOTOR_5);
                    stop_motor(MOTOR_6);
                }
                break;
            case OPEN_STEP_2:
                if(run_motor.beginChangeStep)
                {
                    ECHOLN("START MODE RUN OPEN STEP 2");
                    run_motor.beginChangeStep = false;
                    stop_motor(MOTOR_1);
                    stop_motor(MOTOR_2);
                    stop_motor(MOTOR_3);
                    open_motor(MOTOR_4);
                    // checkCurrentMotor4.start();
                    open_motor(MOTOR_5);
                    // checkCurrentMotor5.start();
                    open_motor(MOTOR_6);
                    // checkCurrentMotor6.start();
                }
                break;
            case OPEN_STEP_3:
                if(run_motor.beginChangeStep)
                {
                    ECHOLN("START MODE RUN OPEN STEP 3");
                    run_motor.beginChangeStep = false;
                    close_motor(MOTOR_1);
                    // checkCurrentMotor1.start();
                    close_motor(MOTOR_2);
                    // checkCurrentMotor2.start();
                    stop_motor(MOTOR_3);
                    stop_motor(MOTOR_4);
                    stop_motor(MOTOR_5);
                    stop_motor(MOTOR_6);
                }
                break;
            case DONE_MODE_OPEN:
                ECHOLN("DONE RUN OPEN MODE");
                run_motor.mode_run_open_step++;
                break;
            default:
                break;
            }
        }
        //-----------------------------------------------
        else
        {
            run_motor.mode_run_open_step = OPEN_STEP_1;
            switch (run_motor.mode_run_close_step)
            {
            case CLOSE_STEP_1:
                if(run_motor.beginChangeStep)
                {
                    ECHOLN("START MODE RUN CLOSE STEP 1");
                    run_motor.beginChangeStep = false;
                    open_motor(MOTOR_1);
                    // checkCurrentMotor1.start();
                    open_motor(MOTOR_2);
                    // checkCurrentMotor2.start();
                    stop_motor(MOTOR_3);
                    stop_motor(MOTOR_4);
                    stop_motor(MOTOR_5);
                    stop_motor(MOTOR_6);
                }
                break;
            case CLOSE_STEP_2:
                if(run_motor.beginChangeStep)
                {
                    ECHOLN("START MODE RUN CLOSE STEP 2");
                    run_motor.beginChangeStep = false;
                    stop_motor(MOTOR_1);
                    stop_motor(MOTOR_2);
                    stop_motor(MOTOR_3);
                    close_motor(MOTOR_4);
                    // checkCurrentMotor4.start();
                    close_motor(MOTOR_5);
                    // checkCurrentMotor5.start();
                    close_motor(MOTOR_6);
                    // checkCurrentMotor6.start();
                }
                break;
            case CLOSE_STEP_3:
                if(run_motor.beginChangeStep)
                {
                    ECHOLN("START MODE RUN CLOSE STEP 3");
                    run_motor.beginChangeStep = false;
                    close_motor(MOTOR_1);
                    // checkCurrentMotor1.start();
                    close_motor(MOTOR_2);
                    // checkCurrentMotor2.start();
                    close_motor(MOTOR_3);
                    // checkCurrentMotor3.start();
                    stop_motor(MOTOR_4);
                    stop_motor(MOTOR_5);
                    stop_motor(MOTOR_6);
                }
                break;
            case DONE_MODE_CLOSE:
                ECHOLN("DONE RUN CLOSE MODE");
                run_motor.mode_run_close_step++;
                break;
            default:
                break;
            }
        }
        


    }
    else{
        checkButtonControl();
    }
    


}
