#include "friends_group.hpp"

int main()
{
    FriendsGroup friends;

    // add 4 dates but only the last one has more than one birthday
    friends.addBirthday("02/12/2000",
                        "Fran"); // esto tendria que ser un date definido por el usuario
    friends.addBirthday("15/04/2001", "Javi");
    friends.addBirthday("21/06/2002", "Augusto");
    friends.addBirthday("21/06/2002", "Pablo");
    friends.addBirthday("07/09/2000", "Julio");
    friends.addBirthday("07/09/2000", "Gaston");
    friends.show2(); // should print the last date with the two names
}