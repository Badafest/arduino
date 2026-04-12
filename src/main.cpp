#include <Arduino.h>
#include <Servo.h>
#include "helpers.h"

uint8_t potPin = A0;
uint8_t servoPin = 3;

Servo servo;

int angle = 0;
bool angle_increasing = true;

void setup()
{
  turnOffBuiltInLED();

  pinMode(potPin, INPUT);
  servo.attach(servoPin);
}

void loop()
{
  int potenVal = analogRead(A0);

  servo.write(map(potenVal, 0, 1023, 0, 180));
}