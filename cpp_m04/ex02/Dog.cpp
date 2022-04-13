#include "Dog.hpp"

Dog::Dog()
{
	std::cout << CYAN "Dog " YELLOW "default constructor." RESET << std::endl;
	this->type.assign("Dog");
	brain = new Brain();
}

Dog::Dog( const Dog & src )
{
	std::cout << CYAN "Dog " YELLOW "copy constructor." RESET << std::endl;
	this->type.assign(src.type);
	brain = new Brain(*(src.brain));
}

Dog::~Dog()
{
	std::cout << CYAN "Dog " RED "default destructor." RESET << std::endl;
	delete brain;
}

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << CYAN "Dog " YELLOW "copy assigment operator." RESET << std::endl;

	if ( this != &rhs )
	{
		this->type = rhs.type;
		delete brain;
		brain = new Brain(*(rhs.brain));
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << GREEN "BARK! BARK!" RESET << std::endl;
}

void Dog::setIdea(const std::string & idea, size_t index) {
	brain->setIdea(idea, index);
}

const std::string& Dog::getIdea(size_t index) const {
	return brain->getIdea(index);
}
