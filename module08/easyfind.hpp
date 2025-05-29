#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <list>

template <typename T>
typename T::const_iterator easyfind(const T &container, const int &n)
{
    return (std::find(container.begin(), container.end(), n));
}

#endif