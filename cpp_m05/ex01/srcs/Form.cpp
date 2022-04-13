#include "Form.hpp"

Form::Form(): name("NoName"), sign(false), to_sign(100), to_exec(50)
{
	std::cout << CYAN "Form" YELLOW " deafault constructor called." RESET << std::endl;
}

Form::Form(const std::string& name)
	: name(name),
	  sign(false),
	  to_sign(100),
	  to_exec(50)
{
	std::cout << CYAN "Form" YELLOW " constructor with name called." RESET << std::endl;
}

Form::Form(const std::string& name, int to_sign, int to_exec)
	: name(name),
	  sign(false),
	  to_sign(to_sign),
	  to_exec(to_exec)
{
	std::cout << CYAN "Form" YELLOW " constructor with attributes called." RESET << std::endl;
	checkGrade();
}

Form::Form( const Form & src ): name(src.name), sign(src.sign), to_sign(src.to_sign), to_exec(src.to_exec)
{
	std::cout << CYAN "Form" YELLOW " copy constructor called." RESET << std::endl;
}

Form::~Form()
{
	std::cout << CYAN "Form" RED " destructor called." RESET << std::endl;
}

Form &				Form::operator=( Form const & rhs )
{
	std::cout << CYAN "Form" YELLOW " copy assigment operator called." RESET << std::endl;
	Form * tmp = new Form(rhs);
	delete this;
	return *tmp;
}

const std::string & Form::getName() const {
	return (name);
}

bool Form::getSign() const {
	return (this->sign);
}

void Form::setSign(bool sign) {
	this->sign = sign;
}

int Form::getToSign() const {
	return (this->to_sign);
}

int Form::getToExec() const {
	return (this->to_exec);
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->to_sign)
		throw GradeTooLowException();
	this->sign = true;
}

void Form::checkGradeToSign() const {
	if (this->to_sign > MINGRADE)
		throw GradeTooLowException();
	if (this->to_sign < MAXGRADE)
		throw GradeTooHighException();
}

void Form::checkGradeToExec() const {
	if (this->to_exec > MINGRADE)
		throw GradeTooLowException();
	if (this->to_exec < MAXGRADE)
		throw GradeTooHighException();
}

void Form::checkGrade() {
	this->checkGradeToSign();
	this->checkGradeToExec();
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << CYAN << i.getName() << GREEN " is signed: " YELLOW << (i.getSign() ? "true." : "false.") << std::endl;
	o << GREEN "The grade is needed to " MAGNETA "sign" GREEN " is: " YELLOW << i.getToSign() << "." << std::endl;
	o << GREEN "The grade is needed to " MAGNETA "execute" GREEN " is: " YELLOW << i.getToExec() << "." RESET << std::endl;
	return o;
}

const char* Form::GradeTooHighException::what() const throw() {
	return (ERROR_FORM_HIGH);
}

const char* Form::GradeTooLowException::what() const throw() {
	return (ERROR_FORM_LOW);
}
