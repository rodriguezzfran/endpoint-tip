#include "friends_group.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

class FriendsGroupTest : public ::testing::Test
{
protected:
    FriendsGroup group;
};

TEST_F(FriendsGroupTest, ShowPrintsNothingForSingleBirthdayPerDate)
{
    testing::internal::CaptureStdout();
    group.addBirthday("2024-06-01", "Alice");
    group.addBirthday("2024-06-02", "Bob");
    group.show();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}

TEST_F(FriendsGroupTest, ShowPrintsDateWithMultipleBirthdays)
{
    testing::internal::CaptureStdout();
    group.addBirthday("2024-06-01", "Alice");
    group.addBirthday("2024-06-01", "Bob");
    group.show();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Date: 2024-06-01"), std::string::npos);
    EXPECT_NE(output.find("Alice"), std::string::npos);
    EXPECT_NE(output.find("Bob"), std::string::npos);
}

TEST_F(FriendsGroupTest, ShowPrintsOnlyDatesWithMultipleBirthdays)
{
    testing::internal::CaptureStdout();
    group.addBirthday("2024-06-01", "Alice");
    group.addBirthday("2024-06-01", "Bob");
    group.addBirthday("2024-06-02", "Charlie");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.find("Date: 2024-06-01"), std::string::npos);
    EXPECT_EQ(output.find("Alice"), std::string::npos);
    EXPECT_EQ(output.find("Bob"), std::string::npos);
}

TEST_F(FriendsGroupTest, ShowHandlesMultipleDatesWithMultipleBirthdays)
{
    testing::internal::CaptureStdout();
    group.addBirthday("2024-06-01", "Alice");
    group.addBirthday("2024-06-01", "Bob");
    group.addBirthday("2024-06-02", "Charlie");
    group.addBirthday("2024-06-02", "David");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.find("Date: 2024-06-01"), std::string::npos);
    EXPECT_EQ(output.find("Alice"), std::string::npos);
    EXPECT_EQ(output.find("Bob"), std::string::npos);
    EXPECT_EQ(output.find("Date: 2024-06-02"), std::string::npos);
    EXPECT_EQ(output.find("Charlie"), std::string::npos);
    EXPECT_EQ(output.find("David"), std::string::npos);
}
