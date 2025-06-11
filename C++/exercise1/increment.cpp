#include <iostream>

// th '&' symbol is used to pass the variable by reference
void increment(int& num)
{
    std::cout << "Incrementing " << num << std::endl;
    num++;
}
