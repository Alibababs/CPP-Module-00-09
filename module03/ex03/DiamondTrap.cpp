#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	_name = "noname";
	_hit = 100;
	_energy = 50;
	_attack_dmg = 20;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	_name = name;
	_hit = 100;
	_energy = 50;
	_attack_dmg = 20;
	std::cout << "DiamondTrap NAME constructor called" << std::endl;
	std::cout << "DiamondTrap Name : " << _name << std::endl;
	std::cout << "DiamondTrap Hit points : " << _hit << std::endl;
	std::cout << "DiamondTrap Energy : " << _energy << std::endl;
	std::cout << "DiamondTrap Attack Damage : " << _attack_dmg << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy)
{
	_hit = copy._hit;
	_energy = copy._energy;
	_attack_dmg = copy._attack_dmg;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		_hit = copy._hit;
		_energy = copy._energy;
		_attack_dmg = copy._attack_dmg;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	if (_energy <= 0 || _hit <= 0)
	{
		std::cout << "DiamondTrap " << _name 
				  << " can't do anything if it has no hit points or energy points left" 
				  << std::endl;
		return ;
	}
	if (_energy > 0)
		_energy--;
	std::cout << "DiamondTrap " << _name 
			  << " super attacks " << target 
			  << ", causing " << _attack_dmg << " points of damage!"
			  << std::endl
			  << _name << " now has " << _energy << " energy points."
			  << std::endl;
}

void DiamondTrap::guardGate()
{
	std::cout << "DiamondTrap is now in Gate keeper mode." << std::endl;
}
