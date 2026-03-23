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
    _current_state = _startHigh ? HIGH : LOW;
    digitalWrite(_ledPin, _current_state);
}

void Blink::Loop()
{
    delay(_current_state == LOW ? _timeLowMs : _timeHighMs);
    _current_state = _current_state == LOW ? HIGH : LOW;
    digitalWrite(_ledPin, _current_state);
}

Blink::~Blink()
{
}