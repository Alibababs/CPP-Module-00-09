#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain( std::string level )
{
    void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i = 0;
    while (i < 4)
    {
        if (levels[i] == level)
			break ;
        i++;
    }
    switch (i)
    {
        case 0:
            (this->*f[0])();
        case 1:
            (this->*f[1])();
        case 2:
            (this->*f[2])();
        case 3:
            (this->*f[3])();
            break;
        default:
            std::cout << "Invalid level" << std::endl;
            break;
    }
}

void Harl::debug()
{
    std::cout << "DEBUG MESSAGE" << std::endl;
}

void Harl::info()
{
    std::cout << "INFO MESSAGE" << std::endl;
}

void Harl::warning()
{
    std::cout << "WARNING MESSAGE" << std::endl;
}

void Harl::error()
{
    std::cout << "ERROR MESSAGE" << std::endl;
}
