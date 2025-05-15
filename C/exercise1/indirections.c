#include <stdint.h>
#include <stdio.h>

// function to dereference "indirections" times
int nIndirections(void* initial, unsigned int indirections)
{

    // if initial is NULL, return 0
    if (initial == NULL && indirections > 0)
    {
        return 0;
    }
    
    // current is a pointer who points to initial (and initial is a pointer to void)
    const void* current = initial; // you cant modify the value of what is pointed to

    for (unsigned int i = 1; i <= indirections; i++)
    {
        current = *(void**)current; // so current points to the value of the pointer current which also points to a pointer to pointer
    }

    return (int)(intptr_t)current; // cast current to int and return it
}

int main()
{

    int destination = 10;

    int* ptr = &destination;
    int** ptr2 = &ptr;
    int*** ptr3 = &ptr2;
    int**** ptr4 = &ptr3;
    int***** ptr5 = &ptr4;
    int****** ptr6 = &ptr5;
    int******* ptr7 = &ptr6;
    int******** ptr8 = &ptr7;

    int result;

    // this should print the value of destination
    result = nIndirections((void*)ptr8, 8);
    printf("result value: %d\n", result);

    // this should print 0
    result = nIndirections((void*)NULL, 7); 
    printf("result value: %d\n", result);

    // this should print the value of destination
    result = nIndirections((void*)destination, 0);
    printf("result value: %d\n", result);

    // this should print 0
    result = nIndirections((void*)0, 0);
    printf("result value: %d\n", result);


}
