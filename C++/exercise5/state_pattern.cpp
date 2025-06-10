#include "state_pattern.h"

int main()
{

    FSMcontext fsm;

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