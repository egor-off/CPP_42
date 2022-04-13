#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon();
	Weapon(std::string _type);
	~Weapon();

	std::string GetType() const;
	void setType(const std::string &Type);
};




#endif
