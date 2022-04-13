#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *mas = new Zombie[N];
	for (int i = 0; i < N; i++)
		mas[i].SetName(name);
	return (mas);
}
