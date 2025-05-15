#ifndef OBJ_DIALOGUE_HPP
#define OBJ_DIALOGUE_HPP

#include <string>
#include <iostream>

class DialogueTwo {

    public:

        // interface methods
        virtual void sayHello() = 0;
        virtual void sayFineAndYou() = 0;

        virtual ~DialogueTwo() = default;

};

class DialogueOne {

    public:

        // interface methods
        virtual void ResponseHello() = 0;
        virtual void sayHowAreYou() = 0;

        virtual ~DialogueOne() = default;

};

class personTwo : public DialogueTwo {

    public:

        void sayHello() override {
            std::cout << "Hello friend" << std::endl;
        }

        void sayFineAndYou() override {
            std::cout << "I am fine and you?" << std::endl;
        }

        ~personTwo() override = default;
};

class personOne : public DialogueOne {

    public:

        void ResponseHello() override {
            std::cout << "Hello!!" << std::endl;
        }

        void sayHowAreYou() override {
            std::cout << "How are you?" << std::endl;
        }

        ~personOne() override = default;
};

#endif 