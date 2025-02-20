#include "DataLogger.h"

DataLogger::DataLogger(uint8_t cs_Pin, uint8_t dht_Pin, uint8_t dht_Type)
    : _dht(dht_Pin,dht_Type), _cs_Pin(cs_Pin){}

bool DataLogger::begin()
{
    _dht.begin();
    if (!SD.begin(_cs_Pin)) 
    {
        Serial.println("SD Card initialization failed!");
        return true;
    }
    Serial.println("SD Card initialized.");
    return false;
}

bool DataLogger::logData()
{
    float Temperature = _dht.readTemperature();
    float Humidity =_dht.readHumidity();

    if (isnan(Temperature) || isnan(Humidity)) 
    {
        Serial.println("Failed to read from DHT sensor!");
        return true;
    }
    
    float HeatIndex = _dht.computeHeatIndex(Temperature,Humidity,false);

    _file = SD.open("/datalog.txt", FILE_APPEND);
    if (!_file) 
    {
        Serial.println("Failed to open file for writing!");
        return true;
    }

    _file.print("Temperature: ");
    _file.print(Temperature);
    _file.print("°C, Humidity: ");
    _file.print(Humidity);
    _file.print("%, Heat index: ");
    _file.print(HeatIndex);
    _file.println("°C");

    _file.close();
    Serial.println("Data logged successfully.");
    return false;
}