#ifndef STATE_PATTERN_H
#define STATE_PATTERN_H

#include <iostream>
#include <memory>
#include <string>

class OffState;
class StoppedState;
class WalkingState;
class RunningState;
class ErrorState;
class FSMcontext;

// Abstract State class
class State
{
protected:
    FSMcontext& context;

    explicit State(FSMcontext& ctx) : context(ctx) {}

public:
    virtual ~State() = default;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void speedUp() = 0;
    virtual void speedDown() = 0;
};

class OffState : public State
{
public:
    explicit OffState(FSMcontext& ctx) : State(ctx) {}

    void turnOn() override;

    void turnOff() override {}
    void speedUp() override {}
    void speedDown() override {}
};

class StoppedState : public State
{
public:
    explicit StoppedState(FSMcontext& ctx) : State(ctx) {}

    void turnOn() override {}

    void turnOff() override;
    void speedUp() override;
    void speedDown() override;
};

class WalkingState : public State
{
public:
    explicit WalkingState(FSMcontext& ctx) : State(ctx) {}

    void turnOn() override {}

    void turnOff() override;
    void speedUp() override;
    void speedDown() override;
};

class RunningState : public State
{
public:
    explicit RunningState(FSMcontext& ctx) : State(ctx) {}

    void turnOn() override {}

    void turnOff() override;
    void speedUp() override;
    void speedDown() override;
};

class ErrorState : public State
{
public:
    explicit ErrorState(FSMcontext& ctx) : State(ctx) {}

    void turnOn() override {}

    void turnOff() override;

    void speedUp() override {}
    void speedDown() override {}
};

class FSMcontext
{
private:
    std::unique_ptr<State> _currentState;

public:
    FSMcontext()
    {
        _currentState = std::unique_ptr<State>(new OffState(*this));
    }

    void changeState(std::unique_ptr<State> newState)
    {
        _currentState = std::move(newState);
    }

    void turnOn()
    {
        _currentState->turnOn();
    }

    void turnOff()
    {
        _currentState->turnOff();
    }

    void speedUp()
    {
        _currentState->speedUp();
    }

    void speedDown()
    {
        _currentState->speedDown();
    }
};

// OffState
inline void OffState::turnOn() {
    std::cout << "Off -- TurnOn --> Stopped\n";
    context.changeState(std::make_unique<StoppedState>(context));
}

// StoppedState
inline void StoppedState::turnOff() {
    std::cout << "Stopped -- TurnOff --> Off\n";
    context.changeState(std::make_unique<OffState>(context));
}
inline void StoppedState::speedUp() {
    std::cout << "Stopped -- SpeedUp --> Walking\n";
    context.changeState(std::make_unique<WalkingState>(context));
}
inline void StoppedState::speedDown() {
    std::cout << "Stopped -- SpeedDown --> Error\n";
    context.changeState(std::make_unique<ErrorState>(context));
}

// WalkingState
inline void WalkingState::turnOff() {
    std::cout << "Walking -- TurnOff --> Off\n";
    context.changeState(std::make_unique<OffState>(context));
}
inline void WalkingState::speedUp() {
    std::cout << "Walking -- SpeedUp --> Running\n";
    context.changeState(std::make_unique<RunningState>(context));
}
inline void WalkingState::speedDown() {
    std::cout << "Walking -- SpeedDown --> Stopped\n";
    context.changeState(std::make_unique<StoppedState>(context));
}

// RunningState
inline void RunningState::turnOff() {
    std::cout << "Running -- TurnOff --> Off\n";
    context.changeState(std::make_unique<OffState>(context));
}
inline void RunningState::speedUp() {
    std::cout << "Running -- SpeedUp --> Error\n";
    context.changeState(std::make_unique<ErrorState>(context));
}
inline void RunningState::speedDown() {
    std::cout << "Running -- SpeedDown --> Walking\n";
    context.changeState(std::make_unique<StoppedState>(context));
}

// ErrorState
inline void ErrorState::turnOff() {
    std::cout << "Error -- TurnOff --> Off\n";
    context.changeState(std::make_unique<OffState>(context));
}

#endif // STATE_PATTERN_H
