#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), ad(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src ) : name(src.name), hp(src.hp), ep(src.ep), ad(src.ad)
{
	std::cout << "Copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->name.assign(rhs.name);
		this->hp = rhs.hp;
		this->ep = rhs.ep;
		this->ad = rhs.ad;
	}
	std::cout << "Copy assigment constructor called" << std::endl;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const std::string& target) {
	if (this->ep-- > 1 && this->hp > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target;
		std::cout << ", cousing " << this->getAd() << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hp > 0)
		std::cout << "ClapTrap " << this->name << " take " << amount << " of damage." << std::endl;
	if (amount >= this->hp)
	{
		std::cout << "He dies. Oh my god, you killed him!" << std::endl;
		this->hp = 0;
	}
	else
		this->hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->ep-- > 1 && this->hp > 0)
	{
		std::cout << "ClapTrap " << this->name << " been repaired for " << amount << " health points!" << std::endl;
		this->hp += amount;
	}
}

unsigned int ClapTrap::getAd() const {
	return (this->ad);
}

void ClapTrap::setAd(unsigned int Ad) {
	this->ad = Ad;
}
