#include "ButtonControl.h"

ButtonControl::ButtonControl(
    uint8_t pin,
    unsigned long delayMs) : _pin(pin),
                             _delayMs(delayMs),
                             _currentState(LOW),
                             _lastStateChangedAt(0)
{
}

ButtonControl::~ButtonControl()
{
}

int ButtonControl::getState() const { return _currentState; }

void ButtonControl::Setup()
{
    pinMode(_pin, INPUT_PULLUP);
    _currentState = digitalRead(_pin);

    _lastChangedState = _currentState;
    _lastStateChangedAt = millis();
}

void ButtonControl::Loop()
{
    int state = digitalRead(_pin);
    long currentTimestamp = millis();

    if (state != _lastChangedState)
    {
        _lastStateChangedAt = currentTimestamp;
    }

    if (currentTimestamp - _lastStateChangedAt > _delayMs)
    {
        _currentState = state;
    }

    _lastChangedState = state;
}