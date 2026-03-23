#include "Arduino.h"

#ifndef __HELPERS_H__
#define __HELPERS_H__

// the built in LED (digital pin 13) is ON during start for some reason
void turnOffBuiltInLED()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
}

#endif