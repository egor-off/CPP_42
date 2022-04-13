#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << CYAN "Cure " YELLOW "default constructor called." RESET << std::endl;
}

Cure::Cure( const Cure & src ) : AMateria("cure")
{
	std::cout << CYAN "Cure " YELLOW "copy constructor called." RESET << std::endl;
	this->type.assign(src.getType());
}

Cure::~Cure()
{
	std::cout << CYAN "Cure " RED "default destructor called." RESET << std::endl;
}

Cure &				Cure::operator=( Cure const & rhs )
{
	std::cout << CYAN "Cure " YELLOW "copy assigment operator called." RESET << std::endl;
	this->type.assign(rhs.getType());
	return *this;
}

AMateria*	Cure::clone() const {
	return (new Cure(*this));
}

void		Cure::use(ICharacter& target) {
	std::cout << GREEN "* heals " BLUE << target.getName() << "’s" GREEN " wounds *" RESET << std::endl;
}
