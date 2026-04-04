#include <Arduino.h>
#include "helpers.h"
#include "ButtonControl.h"

ButtonControl button(
    3,  // button pin
    100 // debounce delay ms
);

uint8_t relayPin = 9;

void setup()
{
  // put your setup code here, to run once:
  turnOffBuiltInLED();

  button.Setup();

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, button.getState());
}

void loop()
{
  // put your main code here, to run repeatedly:
  button.Loop();
  digitalWrite(relayPin, button.getState());
}