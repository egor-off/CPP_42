#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << CYAN "WrongAnimal " YELLOW "default constructor." RESET << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	std::cout << CYAN "WrongAnimal " YELLOW "copy constructor." RESET << std::endl;
	this->setType(src.getType());
}

WrongAnimal::~WrongAnimal()
{
	std::cout << CYAN "WrongAnimal " RED "default destructor." RESET << std::endl;
}

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	std::cout << CYAN "WrongAnimal " YELLOW "copy assigment operator." RESET << std::endl;
	if ( this != &rhs )
		this->setType(rhs.getType());
	return *this;
}

std::string WrongAnimal::getType() const {
	return (this->type);
}

void WrongAnimal::setType(const std::string &Type) {
	this->type = Type;
}

void WrongAnimal::makeSound() {
	std::cout << RED "WrongAnimal" GREEN " make somthing strange." << RESET << std::endl;
}
