// mock_dialogues.hpp

#ifndef MOCK_DIALOGUES_HPP
#define MOCK_DIALOGUES_HPP

#include "obj_dialogue.hpp"
#include <gmock/gmock.h>

class MockDialogueTwo : public DialogueTwo
{
public:
    MOCK_METHOD(void, sayHello, (), (override));
    MOCK_METHOD(void, sayFineAndYou, (), (override));
};

class MockDialogueOne : public DialogueOne
{
public:
    MOCK_METHOD(void, ResponseHello, (), (override));
    MOCK_METHOD(void, sayHowAreYou, (), (override));
};

#endif
