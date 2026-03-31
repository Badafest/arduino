#include <Arduino.h>
#include "helpers.h"

uint8_t buttonPin = 3;
uint8_t relayPin = 9;

int lastButtonState = LOW;

void setup()
{
  // put your setup code here, to run once:
  turnOffBuiltInLED();

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:

  int buttonState = digitalRead(buttonPin);
  if (buttonState == lastButtonState)
  {
    return;
  }

  lastButtonState = buttonState;
  digitalWrite(relayPin, 1 - lastButtonState);
}