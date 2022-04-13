#include "Cat.hpp"

Cat::Cat()
{
	std::cout << CYAN "Cat " YELLOW "default constructor." RESET << std::endl;
	this->type.assign("Cat");
}

Cat::Cat( const Cat & src )
{
	std::cout << CYAN "Cat " YELLOW "copy constructor." RESET << std::endl;
	this->type.assign(src.type);
}

Cat::~Cat()
{
	std::cout << CYAN "Cat " RED "default destructor." RESET << std::endl;
}

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << CYAN "Cat " YELLOW "copy assigment operator." RESET << std::endl;
	if ( this != &rhs )
		this->type = rhs.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << GREEN "MEOW!" RESET << std::endl;
}
