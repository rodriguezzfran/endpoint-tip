#include "mock_dialogues.h"
#include "obj_dialogue.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <iostream>

using ::testing::Exactly;
using ::testing::StrictMock;
using ::testing::Ref;


TEST(PersonTwoTest, TestPersonTwoHello) {
    // Capture the output 
    testing::internal::CaptureStdout();

    StrictMock<MockDialogueOne> mockPersonOne;
    std::unique_ptr<DialogueTwo> p2 = std::make_unique<personTwo>();

    EXPECT_CALL(mockPersonOne, howAreYou(Ref(*p2))).Times(1);

    p2->hello(mockPersonOne);
    
    // Get the captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the output contains the expected string
    EXPECT_NE(output.find("PersonTwo: Hello friend"), std::string::npos);
}

TEST(PersonOneTest, TestHowAreYouCallsFineAndYou) {
    StrictMock<MockDialogueTwo> mockDialogueTwo;

    // Esperamos que se llame fineAndYou
    EXPECT_CALL(mockDialogueTwo, fineAndYou()).Times(1);

    std::unique_ptr<DialogueOne> p1 = std::make_unique<personOne>();
    p1->howAreYou(mockDialogueTwo);
  
}
