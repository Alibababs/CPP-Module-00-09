#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavou("Scavou");

	scavou.attack("enemy");
	
	scavou.takeDamage(1);

	scavou.beRepaired(1);

	scavou.guardGate();

	ClapTrap clapou("Clapou");

	clapou.attack("enemy");
	
	clapou.takeDamage(1);

	clapou.beRepaired(1);

	return 0;
}