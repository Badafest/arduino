#include "Arduino.h"
#include "../Program.h"

#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

enum TrafficLightType
{
    TRAFFIC_LIGHT_RED,
    TRAFFIC_LIGHT_AMBER,
    TRAFFIC_LIGHT_GREEN
};

class TrafficLight : public Program
{

private:
    uint8_t _redPin;
    uint8_t _amberPin;
    uint8_t _greenPin;
    unsigned long _redTime;
    unsigned long _amberTime;
    unsigned long _greenTime;

    unsigned long _lastSwitchedAt;
    unsigned long _waitTime;
    TrafficLightType _currentLight;
    TrafficLightType _nextLight;

    unsigned long _remainingSeconds;

    void SwitchLight();

public:
    TrafficLight(
        uint8_t redPin = 8,
        uint8_t amberPin = 4,
        uint8_t greenPin = 2,
        unsigned long _redTime = 1000,
        unsigned long _amberTime = 1000,
        unsigned long _greenTime = 1000);

    virtual void Setup();
    virtual void Loop();
    ~TrafficLight();
};

#endif
