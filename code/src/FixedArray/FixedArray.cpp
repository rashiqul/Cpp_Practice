#include "FixedArray.h"

// Constructor to initialize the empty array
FixedArray::FixedArray() 
{
    for (int i = 0; i < SIZE; ++i) 
    {
        data[i] = 0;
    }
}

// Destructor
FixedArray::~FixedArray() 
{
    // No dynamic memory to free, but can be used for cleanup if needed
}

// Overload [] operator with bounds checking
int& FixedArray::operator[](int index)
{
    if (index < 0 || index >= SIZE)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

// operator + operator for element-wise addition
FixedArray FixedArray::operator+(const FixedArray& other)
{
    FixedArray result;
    for (int i = 0; i < SIZE; ++i) 
    {
        result[i] = this->data[i] + other.data[i];
    }
    return result;
}

// Display elements
void FixedArray::print() 
{
    for (int i = 0; i < SIZE; ++i)
        std::cout << data[i] << " ";
    std::cout << "\n";
}