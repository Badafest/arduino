#include "Arduino.h"
#include "LedControl.h"

#ifndef __LEDMATRIX_H__
#define __LEDMATRIX_H__

class LedMatrix
{

private:
    LedControl _ledControl;
    uint8_t _intensity;

    const int8_t _digitLeds[10][13] = {
        {0, 1, 2, 3, 5, 6, 8, 9, 11, 12, 13, 14, -1}, // 0
        {2, 5, 8, 11, 14, -1},                        // 1
        {0, 1, 2, 5, 6, 7, 8, 9, 12, 13, 14, -1},     // 2
        {0, 1, 2, 5, 6, 7, 8, 11, 12, 13, 14, -1},    // 3
        {0, 2, 3, 5, 6, 7, 8, 11, 14, -1},            // 4
        {0, 1, 2, 3, 6, 7, 8, 11, 12, 13, 14, -1},    // 5
        {0, 1, 2, 3, 6, 7, 8, 9, 11, 12, 13, 14, -1}, // 6
        {0, 1, 2, 5, 8, 11, 14, -1},                  // 7
        {0, 1, 2, 3, 5, 6, 7, 8, 9, 11, 12, 13, 14},  // 8
        {0, 1, 2, 3, 5, 6, 7, 8, 11, 12, 13, 14, -1}, // 9
    };

public:
    LedMatrix(
        uint8_t displayDIN = 0,
        uint8_t displayCLK = 0,
        uint8_t displayCS = 0,
        uint8_t displayMaxDevice = 0,
        uint8_t intensity = 2);

    void init();
    void clear();
    void displayDigit(uint8_t digit, uint8_t place);
    void displayDecimal(uint8_t place);
    ~LedMatrix();
};

#endif
