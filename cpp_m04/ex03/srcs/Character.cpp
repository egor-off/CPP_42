#include "Character.hpp"

Character::Character()
{
	std::cout << CYAN "Character " YELLOW "default constructor called." RESET << std::endl;
	this->set_empty_invent();
}

Character::Character(const std::string name)
{
	std::cout << CYAN "Character " YELLOW "constructor with name called." RESET << std::endl;
	this->name.assign(name);
	this->set_empty_invent();
}

Character::Character( const Character & src )
{
	std::cout << CYAN "Character " YELLOW "copy constructor called." RESET << std::endl;
	this->name.assign(src.getName());
	// this->set_empty_invent();
	this->copy_invent(src);
}

Character::~Character()
{
	std::cout << CYAN "Character " RED "default destructor called." RESET << std::endl;
	this->clean_invent();
}

Character &				Character::operator=( Character const & rhs )
{
	std::cout << CYAN "Character " YELLOW "copy assigment operator called." RESET << std::endl;
	this->name.assign(rhs.getName());
	this->clean_invent();
	this->copy_invent(rhs);
	return *this;
}

std::string const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	if (this->invent_equiped == invent_size)
	{
		std::cout << RED "There is no more place to equip this Materia." << std::endl;
		return ;
	}
	for (size_t i = 0; i < invent_size; i++)
	{
		if (this->invent[i] == nullptr)
		{
			this->invent[i] = m;
			break;
		}
	}
	this->invent_equiped++;
}

void Character::unequip(int idx) {
	if (this->invent[idx] == nullptr) return ;

	this->invent[idx] = nullptr;
	this->invent_equiped--;
}

void Character::use(int idx, ICharacter& target) {
	if (this->invent[idx] != nullptr)
		this->invent[idx]->use(target);
}

void	Character::clean_invent() {
	for (size_t i = 0; i < invent_size; i++)
		delete this->invent[i];
	this->set_empty_invent();
}

void	Character::set_empty_invent() {
	for (size_t i = 0; i < invent_size; ++i)
		this->invent[i] = nullptr;
	this->invent_equiped = 0;
}

void	Character::copy_invent( Character const & src ) {
	for (size_t i = 0; i < invent_size; i++)
	{
		if (src.invent[i] != nullptr)
			this->invent[i] = src.invent[i]->clone();
	}
	this->invent_equiped = src.invent_equiped;
}
