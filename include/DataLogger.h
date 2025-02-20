#pragma once
#include <SD.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

class DataLogger {
    public:
        DataLogger(uint8_t cs_Pin, uint8_t dht_Pin, uint8_t dht_Type);
        bool begin();
        bool logData();
        //bool printData();
    private:
        uint8_t _cs_Pin;
        DHT _dht;
        File _file;
};
