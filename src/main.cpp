#include <Arduino.h>
#include "helpers.h"

uint8_t potPin = A0;
float voltage = 0;

void setup()
{
  // put your setup code here, to run once:
  turnOffBuiltInLED();

  Serial.begin(9600);
  Serial.println("UNO is ready!");
}

void loop()
{
  // put your main code here, to run repeatedly:

  int adcValue = analogRead(potPin);
  voltage = adcValue * (5.0 / 1023.0);

  Serial.print("ADC Value:");
  Serial.println(adcValue);

  Serial.print("Voltage:");
  Serial.println(voltage, 3);

  delay(1000);
}