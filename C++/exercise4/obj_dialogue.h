#ifndef OBJ_DIALOGUE_H
#define OBJ_DIALOGUE_H

#include <iostream>
#include <string>

// Forward declaration of the classes
class DialogueTwo;
class DialogueOne;

class DialogueTwo
{

public:
    // interface methods
    virtual void hello(DialogueOne& personOne) = 0;
    virtual void fineAndYou() = 0;

    virtual ~DialogueTwo() = default;
};

class DialogueOne
{

public:
    // interface methods
    virtual void howAreYou(DialogueTwo& dialogueTwo) = 0;

    virtual ~DialogueOne() = default;
};

class personOne : public DialogueOne
{
private:
    void howAreYou(DialogueTwo& dialogueTwo) override
    {
        std::cout << "PersonOne: How are you?" << std::endl;
        dialogueTwo.fineAndYou(); // Call the method from personTwo
    }

public:
    void startDialogue(DialogueTwo& dialogueTwo)
    {
        dialogueTwo.hello(*this); // Start the dialogue
    }

    ~personOne() override
    {

    }
};

class personTwo : public DialogueTwo
{

private:
    
    void hello(DialogueOne& personOne) override
    {
        std::cout << "PersonTwo: Hello friend" << std::endl;
        personOne.howAreYou(*this); // Call the method from personOne
    }

    void fineAndYou() override
    {
        std::cout << "PersonTwo: I am fine and you?" << std::endl;
    }

public:

        ~personTwo() override
    {
        
    }

};

#endif // OBJ_DIALOGUE_H