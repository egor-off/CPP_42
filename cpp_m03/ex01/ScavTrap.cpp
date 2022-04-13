#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	this->setHp(100);
	this->setEp(50);
	this->setAd(10);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap was created with special other name" << std::endl;
	this->setHp(100);
	this->setEp(50);
	this->setAd(10);
}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	std::cout << "ScavTrap was created other ScavTrap" << std::endl;
	this->setName(src.getName());
	this->setHp(src.getHp());
	this->setEp(src.getEp());
	this->setAd(src.getAd());
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap was destroyed" << std::endl;
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
		std::cout << "ScavTrap, other Trap, " << this->getName() << ", attacks " << target;
		std::cout << ", cousing " << this->getAd() << " points of damage!" << std::endl;
		this->setEp(this->getEp() - 1);
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " now in Gate keeper mode." << std::endl;
}
