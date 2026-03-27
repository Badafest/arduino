#include <Arduino.h>
#include "helpers.h"
#include "LedMatrix.h"

uint8_t potPin = A0;
float voltage = 0;
LedMatrix ledMatrix(5, 6, 3, 1, 2);

void setup()
{
  // put your setup code here, to run once:
  turnOffBuiltInLED();
  ledMatrix.init();
  ledMatrix.displayDigit(2, 0);

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

  ledMatrix.clear();
  uint8_t voltageInt = 10 * voltage;
  ledMatrix.displayDigit(voltageInt % 10, 1);
  ledMatrix.displayDecimal(0);
  ledMatrix.displayDigit((voltageInt / 10) % 10, 0);

  delay(1000);
}