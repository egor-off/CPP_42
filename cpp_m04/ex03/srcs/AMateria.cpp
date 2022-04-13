#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	std::cout << CYAN "AMaterial " YELLOW "constructor with name called." RESET << std::endl;
	this->type.assign(type);
}


std::string const & AMateria::getType() const {
	return (type);
}

AMateria::~AMateria()
{
	std::cout << CYAN "AMaterial " RED "default destructor called." RESET << std::endl;
}
