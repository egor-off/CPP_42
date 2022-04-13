#include "Cat.hpp"

Cat::Cat()
{
	std::cout << CYAN "Cat " YELLOW "default constructor." RESET << std::endl;
	this->type.assign("Cat");
	brain = new Brain();
}

Cat::Cat( const Cat & src )
{
	std::cout << CYAN "Cat " YELLOW "copy constructor." RESET << std::endl;
	this->type.assign(src.type);
	brain = new Brain(*(src.brain));
}

Cat::~Cat()
{
	std::cout << CYAN "Cat " RED "default destructor." RESET << std::endl;
	delete brain;
}

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << CYAN "Cat " YELLOW "copy assigment operator." RESET << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.type;
		delete brain;
		brain = new Brain(*(rhs.brain));
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << GREEN "MEOW!" RESET << std::endl;
}

void Cat::setIdea(const std::string & idea, size_t index) {
	brain->setIdea(idea, index);
}

const std::string& Cat::getIdea(size_t index) const {
	return brain->getIdea(index);
}
