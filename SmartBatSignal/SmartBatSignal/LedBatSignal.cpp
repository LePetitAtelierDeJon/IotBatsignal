#include <wiringPi.h>

#include "LedBatSignal.h"

LedBatSignal::LedBatSignal()
{
    // Init wiringPi for accessing raspberry GPIOs.
    wiringPiSetupSys();
}

void LedBatSignal::turnTheLight(bool state)
{
    digitalWrite(LED, state);
    batSignalState_ = state;
}

void LedBatSignal::triggerSignal()
{
    for (int i = 0; i < BLINK_COUNT; ++i)
    {
        digitalWrite(LED, HIGH);
        delay(BLINK_DURATION);
        digitalWrite(LED, LOW);
        delay(BLINK_DURATION);
    }
}

bool LedBatSignal::lightStatus() const
{
    return batSignalState_;
}