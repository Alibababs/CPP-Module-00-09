#include "ICharacter.hpp"

ICharacter::ICharacter() : _name("noname")
{
    std::cout << "ICharacter constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &copy)
{
    std::cout << "ICharacter copy constructor called" << std::endl;
	_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}
    
ICharacter &ICharacter::operator=(const ICharacter &copy)
{
    std::cout << "ICharacter assignment operator called" << std::endl;
    if (this != &copy)
	{
        _name = copy._name;
		for (int i = 0; i < 4; i++)
		{
            if (_inventory[i])
			{
                delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone();
		}
	}
	return *this;
}

ICharacter::~ICharacter()
{
    std::cout << "ICharacter destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

ICharacter::ICharacter(std::string const & name) : _name(name)
{
	std::cout << "ICharacter name constructor called" << std::endl;
}

const std::string &ICharacter::getName() const
{
	return _name;
}

void ICharacter::equip(AMateria* m)
{
    std::cout << "EQUIP" << std::endl;
}

void ICharacter::unequip(int idx)
{
    std::cout << "UNEQUIP" << std::endl;
}

void ICharacter::use(int idx, ICharacter& target)
{
	std::cout << "USE" << std::endl;
}
