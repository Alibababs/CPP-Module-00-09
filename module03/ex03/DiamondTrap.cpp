#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("noname_clap_name"), ScavTrap(), FragTrap()
{
	_name = "noname";
    this->_hit = FragTrap::_hit;
    this->_energy = ScavTrap::_energy;
    this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name)
{
	_name = name;
    this->_hit = FragTrap::_hit;
    this->_energy = ScavTrap::_energy; // FAUX ICI A REFAIRE
    this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "DiamondTrap NAME constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _name(copy._name) 
{
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) 
{
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &copy) 
    {
        ClapTrap::operator=(copy);
        ScavTrap::operator=(copy);
        FragTrap::operator=(copy);
        this->_name = copy._name;
    }
    return *this;
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
