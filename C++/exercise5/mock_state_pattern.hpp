// mock_state.hpp
#ifndef MOCK_STATE_HPP
#define MOCK_STATE_HPP

#include "state_pattern.hpp"
#include <gmock/gmock.h>

class MockState : public State {
public:
    MOCK_METHOD(void, turnOn, (), (override));
    MOCK_METHOD(void, turnOff, (), (override));
    MOCK_METHOD(void, speedUp, (), (override));
    MOCK_METHOD(void, speedDown, (), (override));
};

#endif
