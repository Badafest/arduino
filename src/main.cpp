#include <Arduino.h>
#include "helpers.h"
#include "LedMatrix.h"

uint8_t potPin = A0;
float voltage = 0;
LedMatrix ledMatrix(5, 6, 3, 1, 1);

void setup()
{
  // put your setup code here, to run once:
  turnOffBuiltInLED();
  ledMatrix.init();

  // display 0.0
  ledMatrix.displayDigit(0, 1);
  ledMatrix.displayDecimal(0);
  ledMatrix.displayDigit(0, 0);
}

void loop()
{
  // put your main code here, to run repeatedly:

  int adcValue = analogRead(potPin);
  float newVoltage = adcValue * (5.0 / 1023.0);

  if (abs(newVoltage - voltage) < 0.1)
  {
    return;
  }

  voltage = newVoltage;

  ledMatrix.clear();
  uint8_t voltageInt = 10 * voltage;
  ledMatrix.displayDigit(voltageInt % 10, 1);
  ledMatrix.displayDecimal(0);
  ledMatrix.displayDigit((voltageInt / 10) % 10, 0);

  delay(500);
}