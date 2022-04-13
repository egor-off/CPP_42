#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define CYAN "\033[0;36m"
# define MAGNETA "\033[0;35m"
# define RESET "\033[0m"

class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();

		WrongAnimal &		operator=( WrongAnimal const & rhs );

		std::string getType() const;
		void setType(const std::string &Type);

		virtual void makeSound();
	protected:
		std::string type;
};

#endif /* ***************************************************** WRONGANIMAL_H */
