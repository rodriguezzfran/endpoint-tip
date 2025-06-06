#include "mock_state_pattern.h"
#include <gtest/gtest.h>

using ::testing::Exactly;

TEST(FSMContextTest, CallsTurnOnOnCurrentState)
{
    std::unique_ptr<MockState> mock = std::make_unique<MockState>();
    MockState* mock_ptr = mock.get();
    FSMcontext fsm(std::move(mock));

    EXPECT_CALL(*mock_ptr, turnOn()).Times(1);
    fsm.turnOn();
}

TEST(FSMContextTest, PositivePath)
{
    std::unique_ptr<State> off = std::make_unique<OffState>();
    FSMcontext fsm(std::move(off));

    testing::internal::CaptureStdout();
    fsm.turnOn();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Off -- TurnOn --> Stopped\n");
}

TEST(FSMContextTest, StoppedToWalkingToRunningTransition)
{
    std::unique_ptr<State> off = std::make_unique<OffState>();
    FSMcontext fsm(std::move(off));

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