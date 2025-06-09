#include "friends_group.h"

int main()
{
    FriendsGroup friends;

    // add 4 dates but only the last one has more than one birthday
    friends.addBirthday({2, 12, 2000}, "Fran"); 
    friends.addBirthday({15, 4, 2001}, "Javi");
    friends.addBirthday({21, 6, 2002}, "Augusto");
    friends.addBirthday({21, 6, 2002}, "Pablo");
    friends.addBirthday({07, 9, 2000}, "Julio");
    friends.addBirthday({07, 9, 2000}, "Gaston");
    friends.show2(); // should print the last date with the two names
}