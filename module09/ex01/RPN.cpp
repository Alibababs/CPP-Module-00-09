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

static bool sendError()
{
    std::cerr << "Error" << std::endl;
    exit (1);
}

static void checkSyntaxError(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]) && !std::isspace(str[i]) && !isOperator(str[i]))
            sendError();
        if (std::isdigit(str[i]) && ((i != 0 && !std::isspace(str[i - 1])) || !std::isspace(str[i + 1])))
            sendError();
        if (std::isspace(str[i]) && (std::isspace(str[i - 1]) || std::isspace(str[ i + 1])))
            sendError();
        if (isOperator(str[i]) && ((i != str.length() - 1 && !std::isspace(str[i + 1])) || !std::isspace(str[i - 1])))
            sendError();
        if (std::isspace(str[str.length() - 1]) || std::isspace(str[0]))
            sendError();
    }
}

void RPN::calculate(const std::string &str)
{
    checkSyntaxError(str);

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
                sendError();
    
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
                    sendError();
                result = a / b;
            }
            _stack.push(result);
        }
        else
            _stack.push(token - '0');
    }
    if (_stack.size() != 1)
        sendError();
    std::cout << _stack.top() << std::endl;
}
