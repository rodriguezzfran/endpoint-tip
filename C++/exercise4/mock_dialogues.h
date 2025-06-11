// mock_dialogues.h

#ifndef MOCK_DIALOGUES_H
#define MOCK_DIALOGUES_H

#include "obj_dialogue.h"
#include <gmock/gmock.h>

class MockDialogueOne : public DialogueOne
{
public:
    MOCK_METHOD(void, howAreYou, (DialogueTwo&), (override));
};

class MockDialogueTwo : public DialogueTwo
{
public:
    MOCK_METHOD(void, hello, (DialogueOne&), (override));
    MOCK_METHOD(void, fineAndYou, (), (override));
};

#endif // MOCK_DIALOGUES_H
