#include "state_pattern.h"
#include <gtest/gtest.h>

TEST(FSMContextTest, PositivePath)
{
    FSMcontext fsm;
    std::unique_ptr<State> off = std::make_unique<OffState>(fsm);

    testing::internal::CaptureStdout();
    fsm.turnOn();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Off -- TurnOn --> Stopped\n");
}

TEST(FSMContextTest, StoppedToWalkingToRunningTransition)
{
    FSMcontext fsm;
    std::unique_ptr<State> off = std::make_unique<OffState>(fsm);

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