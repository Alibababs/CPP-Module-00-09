#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <list>
#include <limits>
#include <stack>

template< typename T >
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &);
        MutantStack &operator=(const MutantStack &);
        ~MutantStack();

};

#include "MutantStack.tpp"

#endif