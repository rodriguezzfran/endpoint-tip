#include "mock_dialogues.h"
#include "obj_dialogue.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Exactly;

// Test personOne class mocking personTwo class
TEST(DialogueTest, MockDialogueOne)
{

    personTwo p2;
    MockDialogueOne mockDialogueOne;

    EXPECT_CALL(mockDialogueOne, ResponseHello()).Times(Exactly(1));
    EXPECT_CALL(mockDialogueOne, sayHowAreYou()).Times(Exactly(1));

    p2.sayHello();
    mockDialogueOne.ResponseHello();
    mockDialogueOne.sayHowAreYou();
    p2.sayFineAndYou();
}

// Test personTwo class mocking personOne class
TEST(DialogueTest, MockDialogueTwo)
{

    personOne p1;
    MockDialogueTwo mockDialogueTwo;

    EXPECT_CALL(mockDialogueTwo, sayHello()).Times(Exactly(1));
    EXPECT_CALL(mockDialogueTwo, sayFineAndYou()).Times(Exactly(1));

    mockDialogueTwo.sayHello();
    p1.ResponseHello();
    p1.sayHowAreYou();
    mockDialogueTwo.sayFineAndYou();
}