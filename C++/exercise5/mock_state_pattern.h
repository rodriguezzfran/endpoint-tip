// mock_state.hpp
#ifndef MOCK_STATE_H
#define MOCK_STATE_H

#include "state_pattern.h"
#include <gmock/gmock.h>

class MockState : public State
{
public:
    MOCK_METHOD(void, turnOn, (), (override));
    MOCK_METHOD(void, turnOff, (), (override));
    MOCK_METHOD(void, speedUp, (), (override));
    MOCK_METHOD(void, speedDown, (), (override));
};

#endif // MOCK_STATE_H
