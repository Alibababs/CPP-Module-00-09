#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap &operator=(const DiamondTrap &copy);
		~DiamondTrap();

		void attack(const std::string& target);
		void whoAmI();
};

#endif