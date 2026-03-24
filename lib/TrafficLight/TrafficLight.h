#include "Arduino.h"
#include "LedControl.h"

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

    LedControl _ledControl;

    unsigned long _lastSwitchedAt;
    unsigned long _waitTime;
    TrafficLightType _currentLight;
    TrafficLightType _nextLight;

    const int8_t _digitLeds[10][13] = {
        {0, 1, 2, 3, 5, 6, 8, 9, 11, 12, 13, 14, -1},
        {2, 5, 8, 11, 14, -1},
        {0, 1, 2, 5, 6, 7, 8, 9, 12, 13, 14, -1},
        {0, 1, 2, 5, 6, 7, 8, 11, 12, 13, 14, -1},
        {0, 2, 3, 5, 6, 7, 8, 11, 14, -1},
        {0, 1, 2, 3, 6, 7, 8, 11, 12, 13, 14, -1},
        {0, 1, 2, 3, 6, 7, 8, 9, 11, 12, 13, 14, -1},
        {0, 1, 2, 5, 8, 11, 14, -1},
        {0, 1, 2, 3, 5, 6, 7, 8, 9, 11, 12, 13, 14},
        {0, 1, 2, 3, 5, 6, 7, 8, 11, 12, 13, 14, -1},
    };

    unsigned long _remainingSeconds;

    void SwitchLight();
    void DisplayDigit(uint8_t digit, uint8_t place);

public:
    TrafficLight(
        uint8_t redPin = 8,
        uint8_t amberPin = 4,
        uint8_t greenPin = 2,
        unsigned long _redTime = 1000,
        unsigned long _amberTime = 1000,
        unsigned long _greenTime = 1000,
        uint8_t displayDIN = 0,
        uint8_t displayCLK = 0,
        uint8_t displayCS = 0,
        uint8_t displayMaxDevice = 0);

    virtual void Setup();
    virtual void Loop();
    ~TrafficLight();
};

#endif
