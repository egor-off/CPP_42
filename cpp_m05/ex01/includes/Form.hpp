#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "color.hpp"
# include "Bureaucrat.hpp"

# define ERROR_FORM_HIGH "The bureacrat's grade or setting grade is too high."
# define ERROR_FORM_LOW "The bureacrat's grade or setting grade is too low."

class Bureaucrat;

class Form
{
	public:

		Form();
		Form(const std::string& name);
		Form(const std::string& name, int to_sign, int to_exec);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		static const int MAXGRADE = 1;
		static const int MINGRADE = 150;

		const std::string & getName() const;
		bool getSign() const;
		void setSign(bool sign);
		int getToSign() const;
		int getToExec() const;

		class GradeTooHighException;
		class GradeTooLowException;

		void beSigned(const Bureaucrat& b);
	private:
		const std::string	name;
		bool				sign;
		const int			to_sign;
		const int			to_exec;
		void checkGradeToSign() const;
		void checkGradeToExec() const;
		void checkGrade();
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

class Form::GradeTooHighException: public std::exception
{
public:
	const char* what() const throw();
};

class Form::GradeTooLowException: public std::exception
{
public:
	const char* what() const throw();
};

#endif /* ************************************************************ FORM_H */
