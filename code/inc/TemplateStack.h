#ifndef TEMPLATESTACK_H
#define TEMPLATESTACK_H

#include <vector>
#include <stdexcept>
#include <iostream>


#define BITS_PER_BYTE 8u

// Template class for a stack
template <typename T>
class MyStack
{
    private:
        std::vector<T> stack;
        int size;

    public:
        // Default constructor
        MyStack() : size(64) {}

        // Template push method
        void push(const T& value)
        {
            stack.push_back(value);
        }

        // Template pop method
        void pop()
        {
            if (stack.empty())
            {
                throw std::out_of_range("Stack is empty");
            }
            stack.pop_back();
        }

        // Template top method
        T top() const
        {
            if (stack.empty())
            {
                throw std::out_of_range("Stack is empty");
            }
            return stack.back();
        }

        // Template isEmpty method
        bool isEmpty() const
        {
            return stack.empty();
        }

        // Default destructor
        ~MyStack();
};


#endif // TEMPLATESTACK_H