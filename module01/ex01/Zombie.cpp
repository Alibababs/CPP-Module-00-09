#include "Zombie.hpp"

Zombie::Zombie()
{
}  

Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name, int N)
{
    std::stringstream stringnumber;
    stringnumber << N;
    _name = name + " [" + stringnumber.str() + "]";
}