#include <stdio.h>

struct structure{
    char charStructure;
    int intStructure;
    float floatStructure;
    double doubleStructure;
    int arrayStructure[10];
};

/*
 the first argument is the struct type
 the second argument is the member of the struct
 ((type *)0) points to the beginning of the struct "type"
 ->member is a member of the struct from the beginning of the struct
*/
#define offsetOf(type, member) ((size_t) &((type *)0)->member)

int main() {
    printf("offset of charStructure: %zu\n", offsetOf(struct structure, charStructure));
    printf("offset of intStructure: %zu\n", offsetOf(struct structure, intStructure));
    printf("offset of floatStructure: %zu\n", offsetOf(struct structure, floatStructure));
    printf("offset of doubleStructure: %zu\n", offsetOf(struct structure, doubleStructure));
    printf("offset of arrayStructure: %zu\n", offsetOf(struct structure, arrayStructure));
}