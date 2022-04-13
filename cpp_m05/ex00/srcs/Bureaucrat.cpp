#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("NoName"), grade(MINGRADE)
{
	std::cout << CYAN "Bureaucrat" YELLOW " deafault constructor called." RESET << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : name(src.name), grade(src.grade)
{
	std::cout << CYAN "Bureaucrat" YELLOW " copy constructor called." RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string & name, const int grade) : name(name), grade(grade)
{
	std::cout << CYAN "Bureaucrat" YELLOW " constructor with name and grade called." RESET << std::endl;
	checkGrade();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << CYAN "Bureaucrat" RED " destructor called." RESET << std::endl;
}

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this == &rhs ) return *this;
	this->setGrade(rhs.getGrade());
	std::cout << CYAN "Bureaucrat" YELLOW " copy assigment operator called." RESET << std::endl;
	return *this;
}

const std::string & Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

void Bureaucrat::setGrade(int grade) {
	this->grade = grade;
	checkGrade();
}

void Bureaucrat::incrementGrade() {
	this->grade--;
	checkGrade();
}

void Bureaucrat::decrementGrade() {
	this->grade++;
	checkGrade();
}

void Bureaucrat::checkGrade() const {
	if (this->grade > MINGRADE)
		throw GradeTooLowException();
	if (this->grade < MAXGRADE)
		throw GradeTooHighException();
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << GREEN << i.getName() << ", " BLUE "bureaucrat grade is "  << i.getGrade() << RESET << std::endl;
	return o;
}
