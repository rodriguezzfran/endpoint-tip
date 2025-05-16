#include "state_machine.h"

void stimulateOff(struct FSM* fsm, enum Stimulus stimulus)
{

    if (stimulus == TurnOn)
    {
        fsm->currentState = Stopped;
        printf("Off -- TurnOn --> Stopped\n");
    }
}

void stimulateStopped(struct FSM* fsm, enum Stimulus stimulus)
{
    switch (stimulus)
    {
        case TurnOff:
            fsm->currentState = Off;
            printf("Stopped -- TurnOff --> Off\n");
            break;
        case SpeedUp:
            fsm->currentState = Walking;
            printf("Stopped -- SpeedUp --> Walking\n");
            break;
        case SpeedDown:
            fsm->currentState = Error;
            printf("Stopped -- SpeedDown --> Error\n");
            break;
        default:
            break;
    }
}

void stimulateWalking(struct FSM* fsm, enum Stimulus stimulus)
{
    switch (stimulus)
    {
        case TurnOff:
            fsm->currentState = Off;
            printf("Walking -- TurnOff --> Off\n");
            break;
        case SpeedUp:
            fsm->currentState = Running;
            printf("Walking -- SpeedUp --> Running\n");
            break;
        case SpeedDown:
            fsm->currentState = Stopped;
            printf("Walking -- SpeedDown --> Stopped\n");
            break;
        default:
            break;
    }
}

void stimulateRunning(struct FSM* fsm, enum Stimulus stimulus)
{
    switch (stimulus)
    {
        case TurnOff:
            fsm->currentState = Off;
            printf("Running -- TurnOff --> Off\n");
            break;
        case SpeedUp:
            fsm->currentState = Error;
            printf("Running -- SpeedUp --> Error\n");
            break;
        case SpeedDown:
            fsm->currentState = Walking;
            printf("Running -- SpeedDown --> Walking\n");
            break;
        default:
            break;
    }
}

void stimulateError(struct FSM* fsm, enum Stimulus stimulus)
{
    switch (stimulus)
    {
        case TurnOff:
            fsm->currentState = Off;
            printf("Error -- TurnOff --> Off\n");
            break;
        default:
            break;
    }
}

void stimulate(struct FSM* fsm, enum Stimulus stimulus)
{

    if (!isValidFSM(fsm))
    {
        printf("FSM not valid\n");
        return;
    }
    else if (!isValidStimulus(stimulus))
    {
        printf("Stimulus not valid\n");
        return;
    }
    else if (!isValidState(fsm->currentState))
    {
        printf("State not valid\n");
        return;
    }
    else
    {
        switch (fsm->currentState)
        {
            case Off:
                stimulateOff(fsm, stimulus);
                break;
            case Stopped:
                stimulateStopped(fsm, stimulus);
                break;
            case Walking:
                stimulateWalking(fsm, stimulus);
                break;
            case Running:
                stimulateRunning(fsm, stimulus);
                break;
            case Error:
                stimulateError(fsm, stimulus);
                break;
            default:
                printf("State not valid\n");
                break;
        }
    }
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
