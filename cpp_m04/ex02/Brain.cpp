#include "Brain.hpp"

Brain::Brain()
{
	std::cout << CYAN "Brain " YELLOW "default constructor." RESET << std::endl;
}

Brain::Brain( const Brain & src )
{
	std::cout << CYAN "Brain " YELLOW "copy constructor." RESET << std::endl;
	for (size_t i = 0; i < 100; i++)
			this->ideas[i].assign(src.ideas[i]);
}

Brain::~Brain()
{
	std::cout << CYAN "Brain " RED "default destructor." RESET << std::endl;
}

Brain &				Brain::operator=( Brain const & rhs )
{
	std::cout << CYAN "Brain " YELLOW "copy assigment operator." RESET << std::endl;
	if ( this == &rhs ) return *this;
	for (size_t i = 0; i < 100; i++)
			this->ideas[i].assign(rhs.ideas[i]);
	return *this;
}

void Brain::setIdea(const std::string & idea, size_t index) {
	if (index > 99)
		std::cout << RED "WRONG INDEX, SORRY. NOTHING HAS HAPPENED" RESET <<  std::endl;
	if (ideas[index].empty())
		ideas[index].assign(idea);
	else
	{
		std::cout << RED "I want to warn you that you lost this -> ";
		std::cout << BLUE << getIdea(index) << RED " interesting idea." RESET << std::endl;
		ideas[index].assign(idea);
	}
}

const std::string & Brain::getIdea(size_t index) const {
	return ideas[index];
}
