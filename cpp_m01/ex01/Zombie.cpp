#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie()
{
	std::cout << "Zombie without name was born" << std::endl;
}

Zombie::Zombie(std::string name_)
{
	name = name_;
	std::cout << name << " was born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(const std::string &Name)
{
	name = Name;
}
