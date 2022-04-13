#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Dog : public Animal
{

	public:

		Dog();
		Dog( Dog const & src );
		~Dog();
		Dog &		operator=( Dog const & rhs );

		void makeSound() const;
		void setIdea(const std::string & idea, size_t index);
		const std::string& getIdea(size_t index) const;
	private:
		Brain* brain;
};

std::ostream &			operator<<( std::ostream & o, Dog const & i );

#endif /* ************************************************************* DOG_H */
