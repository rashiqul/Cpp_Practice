#include <gtest/gtest.h>
#include "../code/src/TemplateStack/TemplateStack.cpp"
#include "TemplateStack.h"

TEST(MyStackTest, PusAndTop)
{
    // Arrange
    MyStack<bool> stack(10);

    // Act 
    stack.push(true);
    stack.push(false);
    stack.push(true);

    // Assert
    EXPECT_TRUE(stack.top());
    stack.pop();
    EXPECT_FALSE(stack.top());
    stack.pop();
    EXPECT_TRUE(stack.top());
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}

TEST(MyStackTest, Pop)
{
    // Arrange
    MyStack<bool> stack(10);
    stack.push(true);
    stack.push(false);
    stack.push(true);

    // Act
    stack.pop();

    // Assert
    EXPECT_FALSE(stack.top());
}

TEST(MyStackTest, PopToEmpty)
{
    // Arrange
    MyStack<bool> stack(2);

    // Act
    stack.push(true);
    stack.push(false);
    stack.pop();
    stack.pop();

    // Assert
    EXPECT_TRUE(stack.isEmpty());
}
