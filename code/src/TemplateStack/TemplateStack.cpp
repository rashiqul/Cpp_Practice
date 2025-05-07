/* 
 * This file provides a template specialization of the MyStack<T> class for the `bool` type.
 * 
 * Concept: Bitset Simulation
 * ----------------------------------
 * Storing boolean values using a standard stack (like std::vector<bool>) can be inefficient
 * in terms of memory, as each bool may be stored as a full byte (8 bits).
 * 
 * Instead, we simulate a compact "bitset"-like storage using bit-packing:
 * - Each byte (`uint8_t`) can hold up to 8 boolean values.
 * - We use bitwise operations to store and retrieve individual bits.
 * 
 * This technique is particularly useful in embedded systems where:
 * - Memory usage must be minimized.
 * - Flags or binary states are commonly tracked.
 * 
 * Operations supported:
 * - `push(bool)`     → Adds a new bit to the top of the stack.
 * - `pop()`          → Removes the top bit.
 * - `top()`          → Returns the current top bit.
 * - `isEmpty()`      → Checks if the bit-stack is empty.
 * 
 * Internally, the stack grows by appending new bytes as needed, and pops remove bytes 
 * once all their bits have been cleared.
 * 
 * This mimics how `std::vector<bool>` is specialized in the STL, but with full control and 
 * transparency.
 */

#pragma once

#include <cstdint>
#include "TemplateStack.h"

// Template specialization for bool
template <>
class MyStack<bool> 
{
    private:
        // Each byte can hold 8 boolean values
        std::vector <uint8_t> stack;
        // bit position per byte in the stack
        int bitsUsed;
        int size;
    
    public:
        // Default constructor
        MyStack(int size, int bitsUsed = 0) : size(size), bitsUsed(bitsUsed) 
        {
            // Initialize the stack with the specified size
            stack.reserve(size);
        }

        // Push method for bool
        void push(const bool value)
        {
            // Stack overflow check
            if (bitsUsed >= size)
            {
                throw std::overflow_error("Stack overflow");
            }
            // if the current byte is full, add a new byte
            if (bitsUsed % BITS_PER_BYTE == 0) 
            {
                stack.push_back(0);
            }
            // Set the appropriate bit in the last byte of the stack to 1 if the value is true.
            if (value)
            {
                stack.back() |= (1 << (bitsUsed % BITS_PER_BYTE));
            }
            bitsUsed++;
        }

        // Pop method for bool
        void pop()
        {
            // Check if the stack is empty
            if (bitsUsed == 0)
            {
                throw std::underflow_error("Stack is empty");
            }

            // Decrement the number of bits used
            bitsUsed--;

            if (bitsUsed % BITS_PER_BYTE == 0)
            {
                // Remove the last byte if all bits are cleared
                stack.pop_back();
            }
        }

        // Top method for bool
        bool top() const
        {
            // Check if the stack is empty
            if (bitsUsed == 0)
            {
                throw::std::underflow_error("Stack is empty");
            }
            // Get the index of the last byte
            int index = (bitsUsed - 1) / BITS_PER_BYTE;
            // Get the bit position in the last byte
            int bitPosition = (bitsUsed - 1) % BITS_PER_BYTE;
            // Return the value of the bit at the top of the stack
            return ((stack[index] >> bitPosition) & 1);
        }

        // isEmpty method for bool
        bool isEmpty() const
        {
            return (bitsUsed == 0);
        }

        // Destructor
        ~MyStack() = default;
};

