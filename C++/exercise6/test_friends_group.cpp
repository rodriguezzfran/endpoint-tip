#include "friends_group.h"
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
    group.addBirthday({01,06,2024}, "Alice");
    group.addBirthday({02,05,2024}, "Bob");
    group.show();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());
}

TEST_F(FriendsGroupTest, ShowPrintsDateWithMultipleBirthdays)
{
    testing::internal::CaptureStdout();
    group.addBirthday({01,06,2024}, "Alice");
    group.addBirthday({01,06,2024}, "Bob");
    group.show();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Date: 1/6/2024"), std::string::npos);
    EXPECT_NE(output.find("Alice"), std::string::npos);
    EXPECT_NE(output.find("Bob"), std::string::npos);
}

TEST_F(FriendsGroupTest, ShowPrintsOnlyDatesWithMultipleBirthdays)
{
    testing::internal::CaptureStdout();
    group.addBirthday({01,06,2024}, "Alice");
    group.addBirthday({01,06,2024}, "Bob");
    group.addBirthday({02,06,2024}, "Charlie");
    group.show();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Date: 1/6/2024"), std::string::npos);
    EXPECT_NE(output.find("Alice"), std::string::npos);
    EXPECT_NE(output.find("Bob"), std::string::npos);
    EXPECT_EQ(output.find("Charlie"), std::string::npos);
}

TEST_F(FriendsGroupTest, ShowHandlesMultipleDatesWithMultipleBirthdays)
{
    testing::internal::CaptureStdout();
    group.addBirthday({01,06,2024}, "Alice");
    group.addBirthday({01,06,2024}, "Bob");
    group.addBirthday({02,06,2024}, "Charlie");
    group.addBirthday({02,06,2024}, "David");
    group.show();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Date: 1/6/2024"), std::string::npos);
    EXPECT_NE(output.find("Alice"), std::string::npos);
    EXPECT_NE(output.find("Bob"), std::string::npos);
    EXPECT_NE(output.find("Date: 2/6/2024"), std::string::npos);
    EXPECT_NE(output.find("Charlie"), std::string::npos);
    EXPECT_NE(output.find("David"), std::string::npos);
}

TEST_F(FriendsGroupTest, Show2HandlesMultipleDatesWithMultipleBirthdays)
{
    testing::internal::CaptureStdout();
    group.addBirthday({01,06,2024}, "Alice");
    group.addBirthday({01,06,2024}, "Bob");
    group.addBirthday({02,06,2024}, "Charlie");
    group.addBirthday({02,06,2024}, "David");
    group.show2();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Date: 1/6/2024"), std::string::npos);
    EXPECT_NE(output.find("Alice"), std::string::npos);
    EXPECT_NE(output.find("Bob"), std::string::npos);
    EXPECT_NE(output.find("Date: 2/6/2024"), std::string::npos);
    EXPECT_NE(output.find("Charlie"), std::string::npos);
    EXPECT_NE(output.find("David"), std::string::npos);
}