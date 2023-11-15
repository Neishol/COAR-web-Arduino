#include "SEN0162.hpp"
#include <Arduino.h>

SEN0162::SEN0162(int pin)
    : m_pin { pin } {}

int SEN0162::GetUVIndex()
{
    double analogValue = analogRead(m_pin);
    return analogValue < 74.47 ? 0 : 0.00026 * analogValue -1;
}
