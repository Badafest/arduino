#include <Arduino.h>
#include "helpers.h"

#include "Blink.h"

Blink blink(8, 1000, 500);

void setup()
{
  // put your setup code here, to run once:
  turnOffBuiltInLED();

  blink.Setup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  blink.Loop();
}
