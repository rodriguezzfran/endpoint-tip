#include "state_machine.h"

void TurnOnFromOff(struct FSM* fsm)
{
    fsm->currentState = Stopped;
    printf("Off -- TurnOn --> Stopped\n");
}

void TurnOffFromStopped(struct FSM* fsm)
{
    fsm->currentState = Off;
    printf("Stopped -- TurnOff --> Off\n");
}

void SpeedUpFromStopped(struct FSM* fsm)
{
    fsm->currentState = Walking;
    printf("Stopped -- SpeedUp --> Walking\n");
}

void SpeedDownFromStopped(struct FSM* fsm)
{
    fsm->currentState = Error;
    printf("Stopped -- SpeedDown --> Error\n");
}

void TurnOffFromWalking(struct FSM* fsm)
{
    fsm->currentState = Off;
    printf("Walking -- TurnOff --> Off\n");
}

void SpeedUpFromWalking(struct FSM* fsm)
{
    fsm->currentState = Running;
    printf("Walking -- SpeedUp --> Running\n");
}

void SpeedDownFromWalking(struct FSM* fsm)
{
    fsm->currentState = Stopped;
    printf("Walking -- SpeedDown --> Stopped\n");
}

void TurnOffFromRunning(struct FSM* fsm)
{
    fsm->currentState = Off;
    printf("Running -- TurnOff --> Off\n");
}

void SpeedUpFromRunning(struct FSM* fsm)
{
    fsm->currentState = Error;
    printf("Running -- SpeedUp --> Error\n");
}

void SpeedDownFromRunning(struct FSM* fsm)
{
    fsm->currentState = Walking;
    printf("Running -- SpeedDown --> Walking\n");
}

void TurnOffFromError(struct FSM* fsm)
{
    fsm->currentState = Off;
    printf("Error -- TurnOff --> Off\n");
}

void NoAction(struct FSM* fsm)
{
   (void)fsm; // No action, just a placeholder
}

void (*StateFunctions[CantStates][CantStimulous])(struct FSM*) = 
{
    {TurnOnFromOff, NoAction, NoAction, NoAction},
    {NoAction, TurnOffFromStopped, SpeedUpFromStopped, SpeedDownFromStopped},
    {NoAction, TurnOffFromWalking, SpeedUpFromWalking, SpeedDownFromWalking},
    {NoAction, TurnOffFromRunning, SpeedUpFromRunning, SpeedDownFromRunning},
    {NoAction, TurnOffFromError, NoAction, NoAction}
};

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
        StateFunctions[fsm->currentState][stimulus](fsm);
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
