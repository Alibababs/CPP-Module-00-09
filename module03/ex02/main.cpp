#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	FragTrap fragou("Fragou");

	fragou.attack("enemy");
	
	fragou.takeDamage(1);

	fragou.beRepaired(1);

	fragou.highFivesGuys();

	return 0;
}