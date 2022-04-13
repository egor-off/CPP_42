#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << CYAN "Ice " YELLOW "default constructor called." RESET << std::endl;
}

Ice::Ice( const Ice & src ) : AMateria("ice")
{
	std::cout << CYAN "Ice " YELLOW "copy constructor called." RESET << std::endl;
	this->type.assign(src.getType());
}

Ice::~Ice()
{
	std::cout << CYAN "Ice " RED "default destructor called." RESET << std::endl;
}

Ice &				Ice::operator=( Ice const & rhs )
{
	std::cout << CYAN "Ice " YELLOW "copy assigment operator called." RESET << std::endl;
	this->type.assign(rhs.getType());
	return *this;
}

AMateria*	Ice::clone() const {
	return (new Ice(*this));
}

void		Ice::use(ICharacter& target) {
	std::cout << BLUE "* shoots an ice bolt at " GREEN << target.getName() << BLUE " *" RESET << std::endl;
}
