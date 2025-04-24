#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	_name = "noname";
	_hit = 100;
	_energy = 50;
	_attack_dmg = 20;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap")
{
	_name = name;
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "DiamondTrap NAME constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	_name = copy._name + "_clap_trap";
	_hit = copy._hit;
	_energy = copy._energy;
	_attack_dmg = copy._attack_dmg;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << _name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::_name << std::endl;
}
