#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "color.hpp"

# define ERROR_HIGH "The setting grade is too high."
# define ERROR_LOW "The setting grade is too low."

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

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return (ERROR_HIGH);
			}
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return (ERROR_LOW);
			}
		};

	private:
		const std::string	name;
		int					grade;
		void checkGrade() const;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */
