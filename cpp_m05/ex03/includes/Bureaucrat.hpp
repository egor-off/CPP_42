#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "color.hpp"
# include "Form.hpp"

# define ERROR_HIGH "The setting grade is too high."
# define ERROR_LOW "The setting grade is too low."

class Form;

class Bureaucrat
{

	public:
		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat(const std::string & name, const int grade);
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		static const int MAXGRADE = 1;
		static const int MINGRADE = 150;

		const std::string & getName() const;
		int getGrade() const ;
		void setGrade(int grade);
		void incrementGrade();
		void decrementGrade();

		void signForm(Form& f) const;

		class GradeTooHighException;
		class GradeTooLowException;

		void executeForm(Form const & form);
	private:
		const std::string	name;
		int					grade;
		void checkGrade() const;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

class Bureaucrat::GradeTooHighException: public std::exception
{
public:
	const char* what() const throw();
};

class Bureaucrat::GradeTooLowException: public std::exception
{
public:
	const char* what() const throw();
};

#endif /* ****************************************************** BUREAUCRAT_H */
