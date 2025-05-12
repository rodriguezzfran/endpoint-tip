#include <stdio.h>

enum Stimulus
{
    TurnOn,
    TurnOff,
    SpeedUp,
    SpeedDown
};

enum State
{
    Off,
    Stopped,
    Walking,
    Running,
    Error
};

struct FSM
{
    enum State currentState;
};

void stimulate (struct FSM* fsm, enum Stimulus stimulus){

    switch(fsm->currentState){

        case Off:
            if(stimulus == TurnOn){
                fsm->currentState = Stopped;
                // [Estado anterior] ­­­­ <estímulo> ­­­­­> [Estado nuevo]
                printf("Off -- TurnOn --> Stopped\n");
            }
            break;
        case Stopped:
            switch (stimulus) {
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
            break;
        case Walking:
            switch (stimulus) {
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
            break;
        case Running:
            switch (stimulus) {
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
            break;
        case Error:
            if(stimulus == TurnOff){
                fsm->currentState = Off;
                printf("Error -- TurnOff --> Off\n");
            }
            break;
    }
}

int main() {

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
