#include "Blink.h"

Blink::Blink(
    uint8_t ledPin = LED_BUILTIN,
    long timeHighMs = 1000,
    long timeLowMs = 1000,
    bool startHigh = false) : _ledPin(ledPin),
                              _timeHighMs(timeHighMs),
                              _timeLowMs(timeLowMs),
                              _startHigh(startHigh)
{
}

void Blink::Setup()
{
    pinMode(_ledPin, OUTPUT);
    _currentState = _startHigh ? HIGH : LOW;
    digitalWrite(_ledPin, _currentState);
    _lastTimestamp = millis();
}

void Blink::Loop()
{
    long waitTime = _currentState == LOW ? _timeLowMs : _timeHighMs;
    unsigned long currentTimestamp = millis();
    if (currentTimestamp - _lastTimestamp < waitTime)
    {
        return;
    }
    _currentState = _currentState == LOW ? HIGH : LOW;
    digitalWrite(_ledPin, _currentState);
    _lastTimestamp = currentTimestamp;
}

Blink::~Blink()
{
}