#include "genericList.h"

declare_list_type(int, intList)
declare_list_type(float, floatList)

int main(){

    intList list1;
    floatList list2;

    init_list(int, intList, &list1);
    init_list(float, floatList, &list2);

    add_to_list(int, intList, &list1, 10);
    add_to_list(int, intList, &list1, 20);
    add_to_list(int, intList, &list1, 30);

    add_to_list(float, floatList, &list2, 10.5);
    add_to_list(float, floatList, &list2, 20.5);
    add_to_list(float, floatList, &list2, 30.5);

    print_list_int(int, intList, &list1);
    print_list_float(float, floatList, &list2);

    free_list(int, intList, &list1);
    free_list(float, floatList, &list2);
    
    return 0;

}