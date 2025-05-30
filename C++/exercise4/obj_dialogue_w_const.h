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
    virtual void sayHello(DialogueOne& personOne) = 0;
    virtual void sayFineAndYou() = 0;

    virtual ~DialogueTwo() = default;
};

class DialogueOne
{

public:
    // interface methods
    virtual void sayHowAreYou(DialogueTwo& dialogueTwo) = 0;
    
    virtual ~DialogueOne() = default;
};

class personOne : public DialogueOne
{
private:

    void sayHowAreYou(DialogueTwo& dialogueTwo) override
    {
        std::cout << "PersonOne: How are you?" << std::endl;
        dialogueTwo.sayFineAndYou(); // Call the method from personTwo
    }

    // ver como hacer para que sea privado y que se pueda detruir desde la referencia a la interfaz
public:

    void startDialogue(DialogueTwo& dialogueTwo)
    {
        dialogueTwo.sayHello(*this); // Start the dialogue
        
    }

    ~personOne() override = default;
};


class personTwo : public DialogueTwo
{

private:
    // ver como implementar el puntero o referencia al otro objeto
    void sayHello(DialogueOne& personOne) override
    {
        std::cout << "PersonTwo: Hello friend" << std::endl;
        personOne.sayHowAreYou(*this); // Call the method from personOne
        
    }

    void sayFineAndYou() override
    {
        std::cout << "PersonTwo: I am fine and you?" << std::endl;
    }

    
public:
    ~personTwo() override = default; // cuando usar los destructures virtuales y por que?
};

#endif // OBJ_DIALOGUE_H