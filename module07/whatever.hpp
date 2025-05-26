#include <iostream>

template< typename T >
void swap(T &x, T &y)
{
    T temp;

    temp = x;
    x = y;
    y = temp;
}

template< typename T >
T const &min(T const &x, T const &y)
{
    if (x == y)
        return y;
    else
        return (x < y ? x : y);
}

template< typename T >
T const &max(T const &x, T const &y)
{
    if (x == y)
        return y;
    else
        return (x > y ? x : y);
}
