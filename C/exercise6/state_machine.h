#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <stdio.h>
#include <stdbool.h>

enum Stimulus
{
    TurnOn,
    TurnOff,
    SpeedUp,
    SpeedDown,
    CantStimulous
};

enum State
{
    Off,
    Stopped,
    Walking,
    Running,
    Error,
    CantStates
};

struct FSM
{
    enum State currentState;
};

bool isValidFSM(struct FSM* fsm)
{
    if (fsm == NULL)
    {
        return false;
    }
    return true;
}

bool isValidStimulus(enum Stimulus stimulus)
{
    if (stimulus >= CantStimulous)
    {
        return false;
    }
    return true;
}

bool isValidState(enum State state)
{
    if (state >= CantStates)
    {
        return false;
    }
    return true;
}

#endif