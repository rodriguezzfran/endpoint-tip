#ifndef OBJ_DIALOGUE_H
#define OBJ_DIALOGUE_H

#include <iostream>
#include <string>

class DialogueTwo
{

public:
    // interface methods
    virtual void sayHello() = 0;
    virtual void sayFineAndYou() = 0;

    virtual ~DialogueTwo() = default;
};

class DialogueOne
{

public:
    // interface methods
    virtual void ResponseHello() = 0;
    virtual void sayHowAreYou() = 0;

    virtual ~DialogueOne() = default;
};

class personTwo : public DialogueTwo
{

private:
    // ver como implementar el puntero o referencia al otro objeto
    void sayHello() override
    {
        std::cout << "Hello friend" << std::endl;
    }

    void sayFineAndYou() override
    {
        std::cout << "I am fine and you?" << std::endl;
    }

public:
    ~personTwo() override = default; // cuando usar los destructures virtuales y por que?
};

class personOne : public DialogueOne
{

private:
    void ResponseHello() override
    {
        std::cout << "Hello!!" << std::endl;
    }

    void sayHowAreYou() override
    {
        std::cout << "How are you?" << std::endl;
    }

    // ver como hacer para que sea privado y que se pueda detruir desde la referencia a la interfaz
public:
    ~personOne() override = default;
};

#endif // OBJ_DIALOGUE_H