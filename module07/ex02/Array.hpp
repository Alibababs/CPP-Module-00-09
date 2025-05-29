#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

template< typename T >
class Array
{
    private:
        unsigned int _size;
        T *_array;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &copy);
        ~Array();

        T &operator[](const unsigned int &index);
        unsigned int size() const;

};

#include "Array.tpp"

#endif