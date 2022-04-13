#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm: public Form
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& name, const std::string& target);
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );
		void execute(Bureaucrat const & executor) const;
		static Form* makeForm(const std::string& target);
	private:
		void checkExecution(Bureaucrat const & executor) const;
};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */
