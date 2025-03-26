#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType(void) const
{
    return (_type);
}

void Weapon::setType(std::string type)
{
    _type = type;
}
