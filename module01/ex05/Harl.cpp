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

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
		{
			(this->*f[i])();
			break ;
		}
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
