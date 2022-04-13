#include "Animal.hpp"

Animal::Animal()
{
	std::cout << CYAN "Animal " YELLOW "default constructor." RESET << std::endl;
}

Animal::Animal( const Animal & src )
{
	std::cout << CYAN "Animal " YELLOW "copy constructor." RESET << std::endl;
	this->setType(src.getType());
	std::cout << BLUE "in copy constructor------------------------" RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << CYAN "Animal " RED "default destructor." RESET << std::endl;
}

Animal &				Animal::operator=( Animal const & rhs )
{
	std::cout << CYAN "Animal " YELLOW "copy assigment operator." RESET << std::endl;
	if ( this == &rhs ) return *this;
	setType(rhs.getType());
	return *this;
}

void Animal::makeSound() const {
	std::cout << CYAN << "Animal " GREEN "make some sound." << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}

void Animal::setType(const std::string &Type) {
	this->type.assign(Type);
}
