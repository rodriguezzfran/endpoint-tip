#include "obj_dialogue.hpp"

int main()
{
    // Create instances of personOne and personTwo
    personOne p1;
    personTwo p2;

    // Call methods
    DialogueOne& d1 = p1;
    DialogueTwo& d2 = p2;

    d2.sayHello();
    d1.ResponseHello();
    d1.sayHowAreYou();
    d2.sayFineAndYou();

    return 0;
}