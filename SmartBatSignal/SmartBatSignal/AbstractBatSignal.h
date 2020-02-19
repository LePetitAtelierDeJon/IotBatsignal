#ifndef ABSTRACT_BAT_SIGNAL_H
#define ABSTRACT_BAT_SIGNAL_H

/**
 * Interface for handling BatSignal :
 * turn the light on & off, trigger the signal & get the light status.
 */
class AbstractBatSignal {
public:
    virtual void turnTheLight(bool state) = 0;
    virtual void triggerSignal() = 0;
    virtual bool lightStatus() const = 0;

protected:
    bool batSignalState_;
};

#endif // ABSTRACT_BAT_SIGNAL_H