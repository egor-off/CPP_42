#include "Dog.hpp"

Dog::Dog()
{
	std::cout << CYAN "Dog " YELLOW "default constructor." RESET << std::endl;
	this->type.assign("Dog");
}

Dog::Dog( const Dog & src )
{
	std::cout << CYAN "Dog " YELLOW "copy constructor." RESET << std::endl;
	this->type.assign(src.type);
}

Dog::~Dog()
{
	std::cout << CYAN "Dog " RED "default destructor." RESET << std::endl;
}

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << CYAN "Dog " YELLOW "copy assigment operator." RESET << std::endl;

	if ( this != &rhs )
		this->type = rhs.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << GREEN "BARK! BARK!" RESET << std::endl;
}
