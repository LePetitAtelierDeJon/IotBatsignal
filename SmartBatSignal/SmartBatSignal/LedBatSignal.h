#ifndef LED_BAT_SIGNAL_H
#define LED_BAT_SIGNAL_H

#include "AbstractBatSignal.h"

class LedBatSignal :
    public AbstractBatSignal

{
public:
    LedBatSignal();
    ~LedBatSignal();

    // Inherited via AbstractBatSignal
    virtual void turnTheLight(bool state) override;
    virtual void triggerSignal() override;
    virtual bool lightStatus() const override;
private:
    // Gpio for the led.
    const int LED = 17;

    // Duration of a light blink in ms.
    const int BLINK_DURATION = 500;

    // Number of blink when the signal is triggered.
    const int BLINK_COUNT = 3;
};

#endif //LED_BAT_SIGNAL_H