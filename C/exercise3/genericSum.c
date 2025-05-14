#include <stdio.h>
 
/**
 * this macro calculates the offset of a member in a struct
 */
#define offsetOf(type, member) ((size_t) &((type *)0)->member)

/**
 * this function calculates the sum of a field in a struct
 * @param array: pointer to the array of structs
 * @param elementSize: size of the struct
 * @param fieldOffset: offset of the field in the struct
 * @param amountOfElements: number of elements in the array
 * @return: sum of the field in the struct
 */
int genericPlus(const void* array, size_t elementSize, size_t fieldOffset, size_t amountOfElements){

        int acum = 0;
        for (size_t i = 0; i < amountOfElements; i++) {
            acum += *(int*)((char*)array + fieldOffset); // cast to char* because we need to move the pointer by bytes
            array = (char*)array + elementSize;
        }

        return acum;

}

typedef struct structure{
    char charStructure;
    int intStructure;
    float floatStructure;
    double doubleStructure;
} structure;

structure arrayStructure[10] = {
    {'a', 1, 1.0, 1.1},
    {'b', 2, 2.0, 2.2},
    {'c', 3, 3.0, 3.3},
    {'d', 4, 4.0, 4.4},
    {'e', 5, 5.0, 5.5},
    {'f', 6, 6.0, 6.6},
    {'g', 7, 7.0, 7.7},
    {'h', 8, 8.0, 8.8},
    {'i', 9, 9.0, 9.9},
    {'j',10,10.0,10.10}
};

int main() {

    size_t fieldOffset = offsetOf(structure, intStructure);
    size_t elementSize = sizeof(structure);
    size_t amountOfElements = sizeof(arrayStructure) / sizeof(arrayStructure[0]);
    int sum = genericPlus(arrayStructure, elementSize, fieldOffset, amountOfElements);
    printf("sum of intStructure: %d\n", sum);

}