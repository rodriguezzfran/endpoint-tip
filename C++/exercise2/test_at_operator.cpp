#include "at_operator.h"
#include <gtest/gtest.h>

// Test case for the declare_at macro
TEST(DeclareAtTest, DeclareAtMacro)
{

    const int initialized[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; ++i)
    {
        std::cout << initialized[i] << " "; // Print the original array
    }

    declare_at(int, refVar, &initialized[2]);

    // Check if the reference is correctly initialized
    refVar = 10;                   // Change the value at the referenced address
    for (int i = 0; i < 5; ++i)
    {
        std::cout << initialized[i] << " "; // Print the original array
    }
    EXPECT_EQ(initialized[2], 10); // Verify that the original array is modified
    EXPECT_EQ(refVar, 10);         // Verify that the reference reflects the change
}