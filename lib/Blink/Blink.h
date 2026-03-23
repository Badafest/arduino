#include "Arduino.h"
#include "../Program.h"

#ifndef __BLINK_H__
#define __BLINK_H__

class Blink : public Program
{
private:
    uint8_t _ledPin;
    long _timeHighMs;
    long _timeLowMs;
    bool _startHigh;
    uint8_t _currentState;
    unsigned long _lastTimestamp;

public:
    Blink(
        uint8_t ledPin = LED_BUILTIN,
        long timeHighMs = 1000,
        long timeLowMs = 1000,
        bool startHigh = false);
    virtual void Setup();
    virtual void Loop();
    ~Blink();
};

#endif
