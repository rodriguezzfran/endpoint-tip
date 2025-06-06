#include "pepe_and_juan.h"
#include <gtest/gtest.h>

// Test case for the declare_at macro
TEST(PepeAndJuanTest, PepeAndJuanMacro)
{

    // Create an instance of Pepe
    Pepe pepe = {10, 20, 30, 40, 50, 60};

    // Create an instance of Juan
    Juan juan(pepe, 40);

    // Check if the values are correctly initialized
    EXPECT_EQ(pepe.x, 10);
    EXPECT_EQ(pepe.y, 20);
    EXPECT_EQ(pepe.z, 30);
    EXPECT_EQ(pepe.a, 40);
    EXPECT_EQ(pepe.b, 50);
    EXPECT_EQ(pepe.c, 60);
    EXPECT_EQ(juan.pp.x, pepe.x);
    EXPECT_EQ(juan.pp.y, pepe.y);
    EXPECT_EQ(juan.pp.z, pepe.z);
    EXPECT_EQ(juan.pp.a, pepe.a);
    EXPECT_EQ(juan.pp.b, pepe.b);
    EXPECT_EQ(juan.pp.c, pepe.c);
    EXPECT_EQ(juan.a, 40);
}

// Test case for the size of the structures
TEST(PepeAndJuanTest, SizeOfStructures)
{

    // Check the size of Pepe
    EXPECT_EQ(sizeof(Pepe), 12); // Assuming 4 bytes for each int
    std::cout << "Size of Pepe: " << sizeof(Pepe) << std::endl;
    std::cout << "Size of Juan: " << sizeof(Juan) << std::endl;
    std::cout << "it could be true deppending on the size of the structure pepe" << std::endl;
    std::cout << "the Juan size is 8 bytes of the reference + 4 bytes of the int + 4 bytes of "
                 "the padding in this architecture, so it always will be 16 bytes and different from pepe"
              << std::endl;

    // Check the size of Juan
    EXPECT_EQ(sizeof(Juan), 16); // Assuming 4 bytes for int and 8 for reference
    EXPECT_NE(sizeof(Juan), sizeof(Pepe)); // Juan should not be the same size as Pepe
}
