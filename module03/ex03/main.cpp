#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diams("Diams");

	diams.attack("Michel");

	diams.beRepaired(1);

	diams.takeDamage(1);

	diams.highFivesGuys();

	diams.guardGate();

	diams.whoAmI();

	return 0;
}