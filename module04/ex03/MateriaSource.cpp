#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _type("notype")
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

MateriaSource::MateriaSource(std::string const & type) : _type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria*)
{
    std::cout << "learn" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    std::cout << "create" << std::endl;
}