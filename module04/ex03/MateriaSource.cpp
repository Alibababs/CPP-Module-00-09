#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}
    
MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &copy)
	{
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

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	std::cout << "learn" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Materia learned" << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot learn more materia" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
		{
			std::cout << "Materia created" << std::endl;
			return _inventory[i]->clone();
		}
	}
	std::cout << "Materia not found" << std::endl;
	return 0;
}
