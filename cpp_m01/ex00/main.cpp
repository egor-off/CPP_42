#include "Zombie.hpp"

int main()
{
	Zombie* vova = newZombie("Vova");
	Zombie* sanya = newZombie("Sanya");

	vova->announce();
	sanya->announce();

	randomChump("Vasya");

	delete vova;
	delete sanya;
}
