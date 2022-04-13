#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{

	public:

		Cat();
		Cat( Cat const & src );
		~Cat();
		Cat &		operator=( Cat const & rhs );

		void makeSound() const;
		void setIdea(const std::string & idea, size_t index);
		const std::string& getIdea(size_t index) const;
	private:
		Brain* brain;
};

#endif /* ************************************************************* CAT_H */
