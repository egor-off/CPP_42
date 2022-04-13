#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string _type)
{
	type = _type;
}

Weapon::~Weapon()
{
}

std::string Weapon::GetType() const
{
	return (type);
}

void Weapon::setType(const std::string &Type)
{
	type = Type;
}
