#include <Arduino.h>
#include "helpers.h"

#include "TrafficLight.h"

TrafficLight trafficLight(8, 4, 2, 50000, 25000, 60000);

void setup()
{
  // put your setup code here, to run once:
  turnOffBuiltInLED();
  Serial.begin(9600);

  trafficLight.Setup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  trafficLight.Loop();
}
