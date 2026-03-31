#include <Arduino.h>
#include "helpers.h"

uint8_t buttonPin = 12;
uint8_t buzzerPin = 9;

float sinVal;
float toneVal;

void setup()
{
  // put your setup code here, to run once:
  turnOffBuiltInLED();

  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // X from 0 degree->360 degree
  for (int x = 0; x < 360; x++)
  {

    if (digitalRead(buttonPin) == HIGH)
    {
      analogWrite(buzzerPin, 0);
      break;
    }

    sinVal = sin(x * (PI / 180));  // Calculate the sine of x
    toneVal = 2000 + sinVal * 500; // Calculate sound frequency according to the sine of x
    tone(buzzerPin, toneVal);      // Output sound frequency to buzzerPin
    delay(10);
  }
}