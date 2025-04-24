#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class DiamondTrap : public ClapTrap
{
	private:

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap &operator=(const DiamondTrap &copy);
		~DiamondTrap();

		void attack(const std::string& target);
		void guardGate();
};

#endif