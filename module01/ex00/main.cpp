#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie *zombie = newZombie("Zombie1");
	zombie->announce();
	randomChump("Zombie2");	
	delete zombie;
	return (0);
}
