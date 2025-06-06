#include "state_pattern.h"

int main()
{
    std::unique_ptr<State> offState
        = std::make_unique<OffState>(); // this is a pointer to a OffState object
    FSMcontext fsm(std::move(offState));

    fsm.turnOn();    // Off -- TurnOn --> Stopped
    fsm.speedUp();   // Stopped -- SpeedUp --> Walking
    fsm.speedUp();   // Walking -- SpeedUp --> Running
    fsm.turnOff();   // Stopped -- TurnOff --> Off
    fsm.turnOn();    // Off -- TurnOn --> Stopped
    fsm.speedDown(); // Stopped -- SpeedDown --> Error
    fsm.turnOff();   // Error -- TurnOff --> Off
    fsm.turnOn();    // Off -- TurnOn --> Stopped
    fsm.speedUp();   // Stopped -- SpeedUp --> Walking
    fsm.speedUp();   // Walking -- SpeedUp --> Running
    fsm.speedUp();   // Running -- SpeedUp --> Error
    fsm.turnOff();   // Error -- TurnOff --> Off

    return 0;
}