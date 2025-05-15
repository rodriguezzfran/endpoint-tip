#include <gtest/gtest.h>
#include "increment.h"

TEST(IncrementTest, PositiveNumber) {
    int num;
    std::cout << "Enter a positive number: ";
    std::cin >> num;
    while (num < 0) {
        std::cout << "Please enter a positive number: ";
        std::cin >> num;
    }
    int lastNum = num;
    increment(num);
    EXPECT_EQ(lastNum+1, num);
}

TEST(IncrementTest, NegativeNumber) {
    int num;
    std::cout << "Enter a negative number: ";
    std::cin >> num;
    while (num >= 0) {
        std::cout << "Please enter a negative number: ";
        std::cin >> num;
    }
    int lastNum = num;
    increment(num);
    EXPECT_EQ(lastNum+1, num);
}