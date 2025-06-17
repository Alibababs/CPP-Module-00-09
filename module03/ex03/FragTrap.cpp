#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "noname";
	_hit = 100;
	_energy = 100;
	_attack_dmg = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit = 100;
	_energy = 100;
	_attack_dmg = 30;
	std::cout << "FragTrap NAME constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy)
	{
		_hit = copy._hit;
		_energy = copy._energy;
		_attack_dmg = copy._attack_dmg;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High five guys!" << std::endl;
}
