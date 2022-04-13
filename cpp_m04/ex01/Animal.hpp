#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define CYAN "\033[0;36m"
# define MAGNETA "\033[0;35m"
# define RESET "\033[0m"

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();
		virtual Animal &		operator=( Animal const & rhs );

		virtual void makeSound() const;

		std::string getType() const;
		void setType(const std::string &Type);
	protected:
		std::string type;
};

#endif /* ********************************************************** ANIMAL_H */
