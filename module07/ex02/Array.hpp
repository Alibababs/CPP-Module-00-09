#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

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

        unsigned int size() const;

};

#endif