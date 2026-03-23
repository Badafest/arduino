#include <Arduino.h>
#include "helpers.h"

#include "Blink.h"

Blink red(8, 3000, 4500, true);
Blink amber(4, 1500, 3000);
Blink green(2, 3000, 4500);

void setup()
{
  // put your setup code here, to run once:
  turnOffBuiltInLED();

  red.Setup();
  amber.Setup();
  green.Setup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  red.Loop();
  amber.Loop();
  green.Loop();
}
