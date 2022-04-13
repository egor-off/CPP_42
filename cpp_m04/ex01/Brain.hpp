#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define CYAN "\033[0;36m"
# define MAGNETA "\033[0;35m"
# define RESET "\033[0m"

class Brain
{
	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &		operator=( Brain const & rhs );
		void setIdea(const std::string & idea, size_t index);
		const std::string & getIdea(size_t index) const;
	private:
		std::string ideas[100];
};

#endif /* *********************************************************** BRAIN_H */
