#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "color.hpp"
# include "Bureaucrat.hpp"

# define ERROR_FORM_HIGH "The bureacrat's grade or setting grade is too high."
# define ERROR_FORM_LOW "The bureacrat's grade or setting grade is too low."
# define IS_NOT_SIGNED "The form is not signed yet."

class Bureaucrat;

class Form
{
	public:

		Form();
		Form(const std::string& name);
		Form(const std::string& name, int to_sign, int to_exec);
		Form( Form const & src );
		virtual ~Form();

		virtual Form &		operator=( Form const & rhs );

		static const int MAXGRADE = 1;
		static const int MINGRADE = 150;

		const std::string & getName() const;
		bool getSign() const;
		void setSign(bool sign);
		int getToSign() const;
		int getToExec() const;

		class GradeTooHighException;
		class GradeTooLowException;
		class IsNotSignedException;

		void beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;
		const std::string& getTarget() const;
		void setTarget(const std::string& target);
	private:
		const std::string	name;
		bool				sign;
		const int			to_sign;
		const int			to_exec;
		void checkGradeToSign() const;
		void checkGradeToExec() const;
		void checkGrade();
		std::string			target;
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

class Form::IsNotSignedException: public std::exception
{
public:
	const char* what() const throw();
};

#endif /* ************************************************************ FORM_H */
