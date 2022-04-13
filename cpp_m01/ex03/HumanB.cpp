#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string _name)
{
	name = _name;
	weapon = nullptr;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->GetType() << std::endl;
}

void HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}

