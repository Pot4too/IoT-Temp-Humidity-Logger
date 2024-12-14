#include <Arduino.h>
#include "SensorReading.h"

#define BAUD_RATE 115200

void setup() 
{
  Serial.begin(BAUD_RATE);
  while(!Serial){;}
  Serial.printf("Serial monitor running at %d", BAUD_RATE);
  if(Initialize())
    printf("Error initializing Sensor!");
}

void loop() {
}
