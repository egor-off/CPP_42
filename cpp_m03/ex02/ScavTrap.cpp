#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	std::cout << CYAN "ScavTrap" YELLOW " was created with no name" RESET << std::endl;
	this->setHp(100);
	this->setEp(50);
	this->setAd(10);
	this->setName("ScavTrap NoName");
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << CYAN "ScavTrap" YELLOW " was created with special other name" RESET << std::endl;
	this->setHp(100);
	this->setEp(50);
	this->setAd(10);
}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	std::cout << CYAN "ScavTrap" YELLOW" was created other ScavTrap" RESET << std::endl;
	this->setName(src.getName());
	this->setHp(src.getHp());
	this->setEp(src.getEp());
	this->setAd(src.getAd());
}

ScavTrap::~ScavTrap()
{
	std::cout << CYAN "ScavTrap" RED " was destroyed" RESET << std::endl;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs )
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

void ScavTrap::attack(const std::string &target)
{
	if (this->getEp() > 1 && this->getHp() > 0)
	{
		std::cout << CYAN "ScavTrap" RESET ", other Trap, " CYAN << this->getName() << RESET ", attacks " CYAN << target;
		std::cout << RESET ", cousing " CYAN << this->getAd() << RESET " points of damage!" << std::endl;
		this->setEp(this->getEp() - 1);
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " now in Gate keeper mode." << std::endl;
}
