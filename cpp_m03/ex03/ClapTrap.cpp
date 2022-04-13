#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/


ClapTrap::ClapTrap() : hp(10), ep(10), ad(0)
{
	std::cout << CYAN "ClapTrap" YELLOW "default constructor called" RESET << std::endl;
}


ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), ad(0)
{
	std::cout << CYAN "ClapTrap" YELLOW " default constructor with name called" RESET << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src ) : name(src.name), hp(src.hp), ep(src.ep), ad(src.ad)
{
	std::cout << CYAN "ClapTrap" YELLOW " copy constructor called" RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << CYAN "ClapTrap" RED " destructor called" RESET << std::endl;
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
	std::cout << YELLOW "Copy assigment constructor called" RESET << std::endl;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const std::string& target) {
	if (this->ep-- > 1 && this->hp > 0)
	{
		std::cout << CYAN "ClapTrap " << this->name << RESET " attacks " CYAN << target;
		std::cout << RESET ", cousing " CYAN << this->getAd() << RESET " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hp > 0)
	{
		std::cout << CYAN "ClapTrap " << this->name << BLUE " take " CYAN << amount << BLUE " of damage." RESET << std::endl;
		if (this->getHp() > amount)
			this->hp -= amount;
		else
			this->setHp(0);
		if (this->getHp() == 0)
			std::cout << BLUE "He dies. Oh my god, you killed " RED << this->getName() << BLUE "!" RESET << std::endl;
	}
	else
		std::cout << BLUE "You can't kill what already died! Please, do not attack the " RED << this->getName() << "'s" BLUE " body again!" RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->getEp() > 1 && this->hp > 0)
	{
		std::cout << "ClapTrap " << this->name << " been repaired for " << amount << " health points!" << std::endl;
		this->hp += amount;
		this->setEp(this->getEp() - 1);
	}
	else if (this->getHp() == 0)
		std::cout << this->getName() << " is already dead. What do you whant to repair?" << std::endl;
	else if (this->getEp() == 0)
		std::cout << this->getName() << " does not have enough energy point, sorry." << std::endl;
}

unsigned int ClapTrap::getAd() const {
	return (this->ad);
}

void ClapTrap::setAd(const unsigned int ad) {
	this->ad = ad;
}

unsigned int ClapTrap::getHp() const {
	return (this->hp);
}

void ClapTrap::setHp(const unsigned int hp) {
	this->hp = hp;
}

unsigned int ClapTrap::getEp() const {
	return (this->ep);
}

void ClapTrap::setEp(const unsigned int ep) {
	this->ep = ep;
}

std::string ClapTrap::getName() const {
	return (this->name);
}

void ClapTrap::setName(const std::string name) {
	this->name = name;
}
