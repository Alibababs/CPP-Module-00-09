#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN &);
        RPN &operator=(const RPN &);
        ~RPN();
};

#endif