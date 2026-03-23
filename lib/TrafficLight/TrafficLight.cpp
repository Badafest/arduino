#include "TrafficLight.h"

TrafficLight::TrafficLight(
    uint8_t redPin,
    uint8_t amberPin,
    uint8_t greenPin,
    unsigned long redTime,
    unsigned long amberTime,
    unsigned long greenTime) : _redPin(redPin),
                               _amberPin(amberPin),
                               _greenPin(greenPin),
                               _redTime(redTime),
                               _amberTime(amberTime),
                               _greenTime(greenTime)
{
}

void TrafficLight::Setup()
{
    pinMode(_redPin, OUTPUT);
    pinMode(_amberPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);

    _nextLight = TRAFFIC_LIGHT_RED;
    SwitchLight();
}

void TrafficLight::Loop()
{
    unsigned long ellapsedTime = millis() - _lastSwitchedAt;
    unsigned long remainingSeconds = round((_waitTime - ellapsedTime) / 1000);

    if (remainingSeconds == _remainingSeconds)
    {
        return;
    }
    _remainingSeconds = remainingSeconds;

    Serial.print("WAIT: ");
    Serial.println(_remainingSeconds);

    if (_remainingSeconds > 0)
    {
        return;
    }

    SwitchLight();
}

void TrafficLight::SwitchLight()
{
    digitalWrite(_redPin, LOW);
    digitalWrite(_amberPin, LOW);
    digitalWrite(_greenPin, LOW);

    TrafficLightType newCurrentLight = _nextLight;

    switch (newCurrentLight)
    {
    case TRAFFIC_LIGHT_RED:
        digitalWrite(_redPin, HIGH);
        _waitTime = _redTime;
        _nextLight = TRAFFIC_LIGHT_AMBER;
        break;
    case TRAFFIC_LIGHT_AMBER:
        digitalWrite(_amberPin, HIGH);
        _waitTime = _amberTime;
        _nextLight = _currentLight == TRAFFIC_LIGHT_RED
                         ? TRAFFIC_LIGHT_GREEN
                         : TRAFFIC_LIGHT_RED;
        break;
    case TRAFFIC_LIGHT_GREEN:
        digitalWrite(_greenPin, HIGH);
        _waitTime = _greenTime;
        _nextLight = TRAFFIC_LIGHT_AMBER;
        break;
    default:
        break;
    }

    _currentLight = newCurrentLight;
    _lastSwitchedAt = millis();
    _remainingSeconds = round(_waitTime / 1000);
}

TrafficLight::~TrafficLight()
{
}