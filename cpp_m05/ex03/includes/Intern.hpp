#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

typedef struct s_list
{
	std::string	name;
	Form*		(*makeForm) (const std::string&);
} t_list;

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		Form*	makeForm(const std::string& name_form, const std::string& target);
	private:
		t_list list[5];
		void	makeList();

};

#endif /* ********************************************************** INTERN_H */
