#include "state_machine.h"

void (*StateFunctions[CantStates][CantStimulous])(struct FSM*, enum Stimulus) = {
    
};

void stimulate(struct FSM* fsm, enum Stimulus stimulus)
{

    
}

int main()// cast to const char* because we need to move the pointer by bytes
{

    struct FSM fsm;
    fsm.currentState = Off;

    stimulate(&fsm, TurnOn);
    stimulate(&fsm, SpeedUp);
    stimulate(&fsm, SpeedUp);
    stimulate(&fsm, SpeedDown);
    stimulate(&fsm, SpeedUp);
    stimulate(&fsm, SpeedUp);
    stimulate(&fsm, TurnOff);

    
}
