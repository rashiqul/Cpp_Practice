#include <gtest/gtest.h>
#include "FixedArray.h"

// Test: Default Constructor, all elements should be initialized to 0
TEST(FixedArrayTest, InitializeToZeros)
{
    // Arrange & Act
    FixedArray arr;
    
    // Assert
    for (int i = 0; i < 10; ++i) 
    {
        EXPECT_EQ(arr[i], 0);
    }
}

// Test: Operator[] bounds checking
TEST(FixedArrayTest, OutOfBoundsAccess)
{
    // Arrange
    FixedArray arr;
    
    // Act & Assert
    EXPECT_THROW(arr[-1], std::out_of_range);
    EXPECT_THROW(arr[10], std::out_of_range);
}

// Test: Operator+ for element-wise addition
TEST(FixedArrayTest, ElementWiseAddition)
{
    // Arrange
    FixedArray arr1;
    FixedArray arr2;

    // Act
    for (int i = 0; i < 10; ++i) 
    {
        arr1[i] = i;
        arr2[i] = i * 2;
    }

    FixedArray result = arr1 + arr2;

    // Assert
    for (int i = 0; i < 10; ++i) 
    {
        EXPECT_EQ(result[i], i + i * 2);
    }
}

// Test: Print function
TEST(FixedArrayTest, PrintFunction)
{
    // Arrange
    FixedArray arr;
    for (int i = 0; i < 10; ++i) 
    {
        arr[i] = i;
    }

    // Act
    arr.print();
}