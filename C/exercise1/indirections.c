#include <stdio.h>
#include <stdint.h>

// function to dereference "indirections" times
int nIndirections (void* initial, unsigned int indirections) {

    // if initial is NULL, return 0
    if (initial == NULL) {
        return 0; 
    }

    void* current = initial; // current is a pointer who points to initial (and initial is a pointer to void) 

    for(unsigned int i=1; i<=indirections; i++){
        current = *(void**)current; // so current points to the value of the pointer current which also points to a pointer to pointer
    }

    return (int)(intptr_t)current; // cast current to int and return it

}

int main(){

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
    result = nIndirections((void *)ptr8,8);
    printf("result value: %d\n", result);

    result = nIndirections((void *)NULL,7);
    printf("result value: %d\n", result);

    result = nIndirections((void *)destination,0);
    printf("result value: %d\n", result);

}
