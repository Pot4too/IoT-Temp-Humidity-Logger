//#include <Arduino.h>
#include "DataLogger.h"

#define BAUD_RATE 115200
#define DELAY 1000   //Delay in milliseconds
#define CS_PIN 5
#define DHT_PIN 26
#define DHT_TYPE DHT22
#define LED_PIN 27

DataLogger logger(CS_PIN, DHT_PIN, DHT_TYPE);

void setup() 
{
  Serial.begin(BAUD_RATE);
  while(!Serial){;}
  Serial.printf("Serial monitor running at %d", BAUD_RATE);
  if(logger.begin())
    printf("Error initializing project!");
}

uint64_t myTime = millis();

void loop() 
{
  if(millis() > myTime + DELAY)
  {
    digitalWrite(LED_PIN,1);
    if(logger.logData())
      Serial.printf("ERROR: couldn't log data!\n");    
    myTime = millis();
  }
  digitalWrite(LED_PIN,0);
}

