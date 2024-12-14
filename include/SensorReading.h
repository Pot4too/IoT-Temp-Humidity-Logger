#pragma once
#include "DHT.h"

#define DHT_TYPE DHT22
#define DHT_PIN 5


bool Initialize();
float ReadTemperature();
float ReadHumidity();
float HeatIndex(float *Temperature, float *Humidity);
