#include "Arduino.h"
#include "../Program.h"

#ifndef __BUTTONCONTROL_H__
#define __BUTTONCONTROL_H__

class ButtonControl : Program
{
private:
    uint8_t _pin;
    unsigned long _delayMs;
    int _currentState;
    int _lastChangedState;
    unsigned long _lastStateChangedAt;

public:
    ButtonControl(uint8_t pin, unsigned long delayMs = 0);
    ~ButtonControl();

    int getState() const;

    void Setup();
    void Loop();
};

#endif