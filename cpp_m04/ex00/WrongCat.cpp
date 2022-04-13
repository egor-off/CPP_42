#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << CYAN "WrongCat " YELLOW "default constructor." RESET << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat( const WrongCat & src )
{
	std::cout << CYAN "WrongCat " YELLOW "copy constructor." RESET << std::endl;
	this->setType(src.getType());
}

WrongCat::~WrongCat()
{
	std::cout << CYAN "WrongCat " RED "default destructor." RESET << std::endl;
}

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	std::cout << CYAN "WrongCat " YELLOW "copy assigment operator." RESET << std::endl;
	if ( this != &rhs )
		this->setType(rhs.getType());
	return *this;
}

void WrongCat::makeSound() {
	std::cout << RED "Wrong" GREEN " MEOW! MRRRR." RESET << std::endl;
}
