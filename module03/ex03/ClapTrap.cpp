#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("noname"), _hit(10), _energy(10), _attack_dmg(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attack_dmg(0)
{
	std::cout << "ClapTrap NAME constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	_hit = copy._hit;
	_energy = copy._energy;
	_attack_dmg = copy._attack_dmg;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		_hit = copy._hit;
		_energy = copy._energy;
		_attack_dmg = copy._attack_dmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energy <= 0 || _hit <= 0)
	{
		std::cout << _name 
				  << " can't do anything if it has no hit points or energy points left" 
				  << std::endl;
		return ;
	}
	if (_energy > 0)
		_energy--;
	std::cout << _name 
			  << " attacks " << target 
			  << ", causing " << _attack_dmg << " points of damage!"
			  << std::endl
			  << _name << " now has " << _energy << " energy points."
			  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit > 0)
	{
		_hit -= amount;
		if (_hit < 0)
			_hit = 0;
		std::cout << _name 
				<< " receive " << amount << " points of damage!"
				<< std::endl
				<< _name  << " now has " << _hit << " hit points."
				<< std::endl;
	}
	else
		std::cout << _name << "is already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy <= 0 || _hit <= 0)
	{
		std::cout << _name 
				  << " can't do anything if it has no hit points or energy points left" 
				  << std::endl;
		return ;
	}
	if (_energy > 0)
		_energy--;
	_hit+= amount;
	std::cout << _name << " repairs itself..."
			<< std::endl
			<< _name << " receive " << amount << " hit points!"
			<< std::endl
			<< _name  << " now has " << _hit << " hit points."
			<< std::endl
			<< _name << " now has " << _energy << " energy points."
			<< std::endl;
}
