#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "noname";
	_hit = 100;
	_energy = 50;
	_attack_dmg = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit = 100;
	_energy = 50;
	_attack_dmg = 20;
	std::cout << "ScavTrap NAME constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy)
	{
		_hit = copy._hit;
		_energy = copy._energy;
		_attack_dmg = copy._attack_dmg;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energy <= 0 || _hit <= 0)
	{
		std::cout << "ScavTrap " << _name 
				  << " can't do anything if it has no hit points or energy points left" 
				  << std::endl;
		return ;
	}
	if (_energy > 0)
		_energy--;
	std::cout << "ScavTrap " << _name 
			  << " super attacks " << target 
			  << ", causing " << _attack_dmg << " points of damage!"
			  << std::endl
			  << _name << " now has " << _energy << " energy points."
			  << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << _name << " is now in Gate keeper mode." << std::endl;
}
