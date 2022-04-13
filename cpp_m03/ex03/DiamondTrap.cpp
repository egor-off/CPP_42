#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("NoName_clap_name")
{
	this->setName("NoName");
	this->setHp(100);
	this->setEp(50);
	this->setAd(30);
	std::cout << CYAN "DiamondTrap" YELLOW "default constructor called" RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->DiamondTrap::name.assign(name);
	this->setHp(100);
	this->setEp(50);
	this->setAd(30);
	std::cout << CYAN "DiamondTrap" YELLOW " default constructor with name called" RESET << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src )
{
	this->DiamondTrap::ClapTrap::setName(src.DiamondTrap::ClapTrap::getName());
	this->DiamondTrap::name = src.DiamondTrap::name;
	this->setHp(src.getHp());
	this->setEp(src.getEp());
	this->setAd(src.getAd());
	std::cout << CYAN "DiamondTrap" YELLOW " copy constructor called" RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << CYAN "DiamondTrap" RED " destructor called" RESET << std::endl;
}

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & src )
{
	if ( this != &src )
	{
		this->setName(src.getName());
		this->setHp(src.getHp());
		this->setEp(src.getEp());
		this->setAd(src.getHp());
	}
	return *this;
}

void DiamondTrap::whoAmI(void) {
	std::cout << GREEN "I am DiamondTrap who has two names:\n1. " MAGNETA << DiamondTrap::ClapTrap::getName();
	std::cout << GREEN "\n2. " BLUE << DiamondTrap::getName() << RESET << std::endl;
}

std::string DiamondTrap::getName() const {
	return (this->DiamondTrap::name);
}

void DiamondTrap::setName(const std::string &Name) {
	this->DiamondTrap::name = Name;
	this->ClapTrap::setName(Name + "_clap_name");
}

