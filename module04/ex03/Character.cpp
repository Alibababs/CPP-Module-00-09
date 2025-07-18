#include "Character.hpp"

Character::Character() : _name("noname")
{
    // std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
    {
        _inventory[i] = NULL;
    }
}

Character::Character(std::string const &name) : _name(name)
{
    // std::cout << "Character name constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
    {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character &copy)
{
    std::cout << "Character copy constructor called" << std::endl;
	_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}
    
Character &Character::operator=(const Character &copy)
{
    std::cout << "Character assignment operator called" << std::endl;
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

Character::~Character()
{
    // std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

const std::string &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "MATERIA DOESNT EXIST" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
		{
			std::cout << "Materia already equip" << std::endl;
			return ;
		}
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "EQUIP in slot: [" << i + 1 << "/4]" << std::endl;
			return;
		}
	}
	std::cout << "Inventory full : Materia destroy" << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (_inventory[idx])
		{

			std::cout << "UNEQUIP" << std::endl;
			delete _inventory[idx];
			_inventory[idx] = NULL;
			return;
		}
		else
			std::cout << "Nothing to unequip" << std::endl; 
	}
	else
		std::cout << "Index out of range" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (!_inventory[idx])
		{
			std::cout << "No materia in this index" << std::endl;
			return ;
		}
		_inventory[idx]->use(target);
	}
	else
		std::cout << "Index out of range" << std::endl;
}
