#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(): _type("notype")
{
    std::cout << "IMateriaSource constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &copy)
{
    std::cout << "IMateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}
    
IMateriaSource &IMateriaSource::operator=(const IMateriaSource &copy)
{
    std::cout << "IMateriaSource assignment operator called" << std::endl;
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

IMateriaSource::~IMateriaSource()
{
    std::cout << "IMateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

IMateriaSource::IMateriaSource(std::string const & type) : _type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

void IMateriaSource::learnMateria(AMateria*)
{
    std::cout << "learn" << std::endl;
}

AMateria* IMateriaSource::createMateria(std::string const & type)
{
    std::cout << "create" << std::endl;
}