#include "obj_dialogue.h"

int main()
{
    // Create instances of personOne and personTwo
    personOne* auxp1 = new personOne();
    DialogueOne* p1 = auxp1;
    DialogueTwo* p2 = new personTwo();

    // Call methods
    auxp1->startDialogue(*p2); // Start the dialogue

    delete p1;
    delete p2; // Clean up memory

    return 0;
}