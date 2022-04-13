#include "Zombie.hpp"
#include <string>

Zombie* newZombie(std::string name)
{
	Zombie* newZombie = new Zombie(name);

	return (newZombie);
}
