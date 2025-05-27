#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _array(NULL)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), array(new T[_size])
{
}

template <typename T>
Array<T>::Array(const Array &copy) : data(new T[_size])
{
    std::cout << "Array copy constructor called" << std::endl;
    _size = copy._size;
    for (unsigned int i = 0; i < _size; i++)
        data[i] = copy.data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
   std::cout << "Array copy assignment operator called" << std::endl;
   if (this != &copy)
   {
       this->_size = copy._size;
       delete data[];
       data = new T[_size];
       for (unsigned int i = 0; i < _size; i++)
        data[i] = copy.data[i];
   }
   return *this;
}