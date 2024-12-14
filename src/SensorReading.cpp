#include "SensorReading.h"


bool Initialize()
{
    DHT Sensor(DHT_PIN,DHT_TYPE);
    Sensor.begin();
    if(isnan(Sensor.readTemperature()))
        return true;
    return false;
}
float ReadTemperature();
float ReadHumidity();
float HeatIndex(float *Temperature, float *Humidity);
