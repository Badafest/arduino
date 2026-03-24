#include <Arduino.h>
#include "helpers.h"

#include "TrafficLight.h"

TrafficLight trafficLight(
    2,     // red pin
    6,     // amber pin
    10,    // green pin
    30000, // red time (ms)
    5000,  // amber time (ms)
    20000, // green time (ms)
    12,    // display data in pin
    4,     // display clock pin
    8,     // display CS pin
    1      // display max device
);

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
