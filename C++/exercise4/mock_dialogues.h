// mock_dialogues.h

#ifndef MOCK_DIALOGUES_H
#define MOCK_DIALOGUES_H

#include "obj_dialogue.h"
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

#endif // MOCK_DIALOGUES_H
