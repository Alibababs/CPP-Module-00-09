#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _array(NULL)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[_size])
{
}

template <typename T>
Array<T>::Array(const Array &copy) : _size(copy._size), _array(new T[_size])
{
    std::cout << "Array copy constructor called" << std::endl;
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = copy._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
   std::cout << "Array copy assignment operator called" << std::endl;
   if (this != &copy)
   {
        T *new_array = new T[copy._size];
        for (unsigned int i = 0; i < copy._size; i++)
            new_array[i] = copy._array[i];
    
        delete [] _array;
        _array = new_array;
        _size = copy._size;
   }
   return *this;
}

template <typename T>
Array<T>::~Array()
{
    // std::cout << "Array destructor called" << std::endl;
    delete [] _array;
}

template <typename T>
T &Array<T>::operator[](const unsigned int &index)
{
    if (index >= _size)
    {
        throw std::out_of_range("Index is out of bounds");
    }
    return _array[index];
}

template <typename T>
const T &Array<T>::operator[](const unsigned int &index) const
{
    if (index >= _size)
    {
        throw std::out_of_range("Index is out of bounds");
    }
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
