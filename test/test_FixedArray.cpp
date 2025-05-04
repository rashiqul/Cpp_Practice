#include <gtest/gtest.h>
#include "FixedArray.h"

// Test: Default Constructor, all elements should be initialized to 0
TEST(FixedArrayTest, InitializeToZeros)
{
    FixedArray arr;
    for (int i = 0; i < 10; ++i) 
    {
        EXPECT_EQ(arr[i], 0);
    }
}