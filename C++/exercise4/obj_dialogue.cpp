#include "obj_dialogue.h"
#include <memory>

int main()
{
    // Create instances of personOne and personTwo using smart pointers
    std::unique_ptr<personOne> person1 = std::make_unique<personOne>();
    std::unique_ptr<DialogueTwo> person2 = std::make_unique<personTwo>();

    // Start the dialogue
    person1.get()->startDialogue(*person2);

    return 0;
}