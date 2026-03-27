#include <Arduino.h>
#include "helpers.h"

const uint8_t ledPin = 9;
bool ledOn = false;
int inInt = 0;

void setup()
{
  // put your setup code here, to run once:
  turnOffBuiltInLED();

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("UNO is ready!");
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (!Serial.available())
  {
    return;
  }

  inInt = Serial.parseInt();
  Serial.print("UNO received:");
  Serial.println(inInt);
  analogWrite(ledPin, constrain(inInt, 0, 255));
}