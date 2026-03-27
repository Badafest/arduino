#include "LedMatrix.h"
#include "LedControl.h"

LedMatrix::LedMatrix(
    uint8_t displayDIN,
    uint8_t displayCLK,
    uint8_t displayCS,
    uint8_t displayMaxDevice,
    uint8_t intensity) : _ledControl(displayDIN, displayCLK, displayCS, displayMaxDevice),
                         _intensity(intensity)
{
}

void LedMatrix::init()
{
    _ledControl.shutdown(0, false);
    _ledControl.setIntensity(0, _intensity);
    clear();
}

void LedMatrix::clear()
{
    _ledControl.clearDisplay(0);
}

void LedMatrix::displayDigit(uint8_t digit, uint8_t place)
{
    // start from second row
    uint8_t row = 1;
    // start from second column + offset based on place
    // one place takes 3 columns
    uint8_t col = 1 + place * 4;

    for (uint8_t i = 0; i < 13; i++)
    {
        int8_t ledIndex = _digitLeds[digit][i];
        if (ledIndex < 0)
        {
            break;
        }

        uint8_t _row = row + _digitLeds[digit][i] / 3;
        uint8_t _col = col + _digitLeds[digit][i] % 3;

        _ledControl.setLed(0, _row, _col, HIGH);
    }
}

LedMatrix::~LedMatrix()
{
}