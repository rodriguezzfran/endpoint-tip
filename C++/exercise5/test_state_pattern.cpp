#include "mock_state_pattern.h"
#include <gtest/gtest.h>

using ::testing::Exactly;

TEST(FSMContextTest, CallsTurnOnOnCurrentState)
{
    auto mock = std::make_shared<MockState>();
    FSMcontext fsm(mock);

    EXPECT_CALL(*mock, turnOn()).Times(1);
    fsm.turnOn();
}

TEST(FSMContextTest, PositivePath)
{
    std::shared_ptr<State> off = std::make_shared<OffState>();
    FSMcontext fsm(off);

    testing::internal::CaptureStdout();
    fsm.turnOn();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Off -- TurnOn --> Stopped\n");
}

TEST(FSMContextTest, StoppedToWalkingToRunningTransition)
{
    std::shared_ptr<State> off = std::make_shared<OffState>();
    FSMcontext fsm(off);

    testing::internal::CaptureStdout();
    fsm.turnOn();  // Off → Stopped
    fsm.speedUp(); // Stopped → Walking
    fsm.speedUp(); // Walking → Running
    fsm.speedUp(); // Running → Error
    fsm.turnOff(); // Error → Off
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Off -- TurnOn --> Stopped\n"
                      "Stopped -- SpeedUp --> Walking\n"
                      "Walking -- SpeedUp --> Running\n"
                      "Running -- SpeedUp --> Error\n"
                      "Error -- TurnOff --> Off\n");
}