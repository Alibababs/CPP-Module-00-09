#include "RPN.hpp"

RPN::RPN()
{
    // std::cout << "RPN constructor called" << std::endl;
}

RPN::RPN(const RPN &copy) : _stack(copy._stack)
{
    std::cout << "RPN copy constructor called" << std::endl;
}

RPN &RPN::operator=(const RPN &copy)
{
   std::cout << "RPN copy assignment operator called" << std::endl;
   if (this != &copy)
   {
    _stack = copy._stack;
   }
   return *this;
}

RPN::~RPN()
{
    // std::cout << "RPN destructor called" << std::endl;
}

static bool isOperator(const char &c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

static int checkSyntaxError(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]) && !std::isspace(str[i]) && !isOperator(str[i]))
            return (1);
        if (std::isdigit(str[i]) && ((i != 0 && !std::isspace(str[i - 1])) || !std::isspace(str[i + 1])))
            return (1);
        if (std::isspace(str[i]) && (std::isspace(str[i - 1]) || std::isspace(str[ i + 1])))
            return (1);
        if (isOperator(str[i]) && ((i != str.length() - 1 && !std::isspace(str[i + 1])) || !std::isspace(str[i - 1])))
            return (1);
        if (std::isspace(str[str.length() - 1]) || std::isspace(str[0]))
            return (1);
    }
    return (0);
}

int RPN::calculate(const std::string &str)
{
    if (checkSyntaxError(str) == 1)
        return (1);

    std::istringstream iss(str);
    char token;
    int a = 0;
    int b = 0;
    int result = 0;

    while (iss >> token)
    {
        if (isOperator(token))
        {
            if (_stack.size() < 2)
                return (1);
    
            b = _stack.top(); 
            _stack.pop();
            a = _stack.top(); 
            _stack.pop();

            if (token == '+')
                result = a + b;
            else if (token == '-')
                result = a - b;
            else if (token == '*')
                result = a * b;
            else
            {
                if (b == 0)
                    return (1);
                result = a / b;
            }
            _stack.push(result);
        }
        else
            _stack.push(token - '0');
    }
    if (_stack.size() != 1)
        return (1);
    std::cout << _stack.top() << std::endl;

    return (0);
}
