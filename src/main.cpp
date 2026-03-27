#include <Arduino.h>
#include "helpers.h"

const uint8_t buttonPin = 12;
const uint8_t ledPin = 9;

bool ledOn = false;

char inChar;
int counter = 0;

void setup()
{
  // put your setup code here, to run once:
  turnOffBuiltInLED();

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("UNO is ready!");
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, ledOn ? HIGH : LOW);

  uint8_t buttonUp = digitalRead(buttonPin);
  delay(150);
  if (digitalRead(buttonPin) != buttonUp)
  {
    ledOn = !ledOn;
  }
}

void serialEvent()
{
  if (!Serial.available())
  {
    return;
  }

  inChar = Serial.read();
  Serial.print("UNO received:");
  Serial.println(inChar);

  if (inChar == '1')
  {
    ledOn = true;
  }
  else if (inChar == '0')
  {
    ledOn = false;
  }
}
