# Vector.h

This is a header only implementation of a vector data structure (aka dynamic array)

## Installation
There is no need to install or compile anything. Simply add file "Vector.h" to your project and #include <Vector.h>

## Documentation

        bool isEmpty();
Checks whether vector is empty or not.

        int size();
Returns the size of a vector.

        Type& at(int index);
Returns an index-th element of a vector. Throws an exception if index is out of vector range. You can also use directly square brackets to access elements.

        void pushBack(Type element);
Adds new element to the end of a vector.

        void pushBack(const Vector<Type>& other);
Adds elements of one vector to another.

        void insertAt(Type element, int position);
Adds an element at a specific position. Throws an exception if index is out of vector range.

        void popBack();
Removes last element of a vector.

        void removeAt(int position);
Removes a position-th element of a vector. Throws an exception if index is out of vector range.

        void removeAll();
Removes all elements of a vector.

        Vector<Type> clone();
Returns a copy of a vector.

        std::string toString(char delimiter = ' ');
Converts all the data of a vector into a string, each element divided by delimiter (by default uses whitespace). Can convert only vectors containing primitive data types like char, bool, int, short, etc.

## Exaple of usage
        #include <iostream>

        #include "Vector.h"

        int main() 
        {
                Vector<int> v(5);

                v.pushBack(1);
                v.pushBack(2);
                v.insertAt(0, 0);

                std::cout << v.toString() << std::endl;
                std::cout << v[2] << " " << v[1] << " " << v[0] << std::endl;

                v.removeAll();

                return 0;
        }

The following program outputs:
        
        0 1 2
        2 1 0