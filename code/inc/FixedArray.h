#ifndef FIXEDARRAY_H
#define FIXEDARRAY_H

#include <iostream>
#include <stdexcept>

class FixedArray 
{
    private:
        static const int SIZE = 10;
        int data[SIZE];

    public:
        // Constructor to initialize the empty array
        FixedArray();
        
        // Destructor
        ~FixedArray();

        // Overload [] operator with bounds checking
        int& operator[](int index);

        // operator + operator for element-wise addition
        FixedArray operator+(const FixedArray& other);

        // Display elements
        void print();
};

#endif // FIXEDARRAY_H