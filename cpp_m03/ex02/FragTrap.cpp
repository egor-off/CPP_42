#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << CYAN "FragTrap" YELLOW " was created with default constructor." RESET << std::endl;
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
	this->setName("NoName FragTrap");
}


FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << CYAN "FragTrap" YELLOW " was created with special name." RESET << std::endl;
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
}

FragTrap::FragTrap( const FragTrap & src )
{
	std::cout << CYAN "FragTrap" YELLOW" was created with copy constructor." RESET << std::endl;
	this->setName(src.getName());
	this->setHp(src.getHp());
	this->setEp(src.getEp());
	this->setAd(src.getAd());
}

FragTrap::~FragTrap()
{
	std::cout << CYAN "FragTrap" RED " was detroyed." RESET << std::endl;
}

FragTrap &	FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->setName(rhs.getName());
		this->setHp(rhs.getHp());
		this->setEp(rhs.getEp());
		this->setAd(rhs.getAd());
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << CYAN "FragTrap " << this->getName() << RESET " is asking for HighFive, brooo!" << std::endl;
}
