#ifndef STATE_PATTERN_H
#define STATE_PATTERN_H

#include <iostream>
#include <memory>
#include <string>

class FSMcontext;
class OffState;
class StoppedState;
class WalkingState;
class RunningState;
class ErrorState;

// Abstract State class
class State
{
protected:
    FSMcontext* context;

public:
    virtual ~State() = default;
    void setContext(FSMcontext* context)
    {
        this->context = context; // raw pointer to the context
    }

    // Every state must implement these methods
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void speedUp() = 0;
    virtual void speedDown() = 0;
};

class FSMcontext
{
private:
    // poner _
    std::shared_ptr<State> currentState; // actual state of the FSM, dynamically allocated object
                                         // that heredits from State

public:
    FSMcontext(std::shared_ptr<State> initialState)
    {
        changeState(initialState);
    }

    void changeState(std::shared_ptr<State> newState)
    {
        currentState = newState;
        currentState->setContext(this);
    }

    void turnOn()
    {
        currentState->turnOn();
    }

    void turnOff()
    {
        currentState->turnOff();
    }

    void speedUp()
    {
        currentState->speedUp();
    }

    void speedDown()
    {
        currentState->speedDown();
    }
};

class OffState : public State
{
public:
    void turnOn() override
    {
        std::cout << "Off -- TurnOn --> Stopped\n";
        context->changeState(std::static_pointer_cast<State>(std::make_shared<StoppedState>()));
    }

    void turnOff() override {}
    void speedUp() override {}
    void speedDown() override {}
};

class StoppedState : public State
{
public:
    void turnOn() override {}

    void turnOff() override
    {
        std::cout << "Stopped -- TurnOff --> Off\n";
        context->changeState(std::static_pointer_cast<State>(std::make_shared<OffState>()));
    }

    void speedUp() override
    {
        std::cout << "Stopped -- SpeedUp --> Walking\n";
        context->changeState(std::static_pointer_cast<State>(std::make_shared<WalkingState>()));
    }
    void speedDown() override
    {
        std::cout << "Stopped -- SpeedDown --> Error\n";
        context->changeState(std::static_pointer_cast<State>(std::make_shared<ErrorState>()));
    }
};

class WalkingState : public State
{
public:
    void turnOn() override {}
    void turnOff() override
    {
        std::cout << "Walking -- TurnOff --> Off\n";
        context->changeState(std::make_shared<OffState>());
    }

    void speedUp() override
    {
        std::cout << "Walking -- SpeedUp --> Running\n";
        context->changeState(std::static_pointer_cast<State>(std::make_shared<RunningState>()));
    }

    void speedDown() override
    {
        std::cout << "Walking -- SpeedDown --> Stopped\n";
        context->changeState(std::static_pointer_cast<State>(std::make_shared<StoppedState>()));
    }
};

class RunningState : public State
{
public:
    void turnOn() override {}
    void turnOff() override
    {
        std::cout << "Running -- TurnOff --> Off\n";
        context->changeState(std::make_shared<OffState>());
    }

    void speedUp() override
    {
        std::cout << "Running -- SpeedUp --> Error\n";
        context->changeState(std::static_pointer_cast<State>(std::make_shared<ErrorState>()));
    }

    void speedDown() override
    {
        std::cout << "Running -- SpeedDown --> Walking\n";
        context->changeState(std::make_shared<StoppedState>());
    }
};

class ErrorState : public State
{
public:
    void turnOn() override {}
    void turnOff() override
    {
        std::cout << "Error -- TurnOff --> Off\n";
        context->changeState(std::make_shared<OffState>());
    }

    void speedUp() override {}
    void speedDown() override {}
};

#endif // STATE_PATTERN_H