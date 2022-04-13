#include "Zombie.hpp"

int main()
{
	Zombie* vova = zombieHorde(5, "Azazer");
	for (int i = 0; i < 5; i++)
		vova[i].announce();
	delete[] vova;
}
