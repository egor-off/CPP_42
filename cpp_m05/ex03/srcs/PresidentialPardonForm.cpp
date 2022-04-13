#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5)
{
	std::cout << CYAN "PresidentialPardonForm" YELLOW " deafault constructor called." RESET << std::endl;
	this->setTarget("target");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name, const std::string& target): Form(name, 25, 5)
{
	std::cout << CYAN "PresidentialPardonForm" YELLOW "  constructor with name called." RESET << std::endl;
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
{
	std::cout << CYAN "PresidentialPardonForm" YELLOW " copy constructor called." RESET << std::endl;
	this->setSign(src.getSign());
	this->setTarget(src.getTarget());
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << CYAN "PresidentialPardonForm" RED " destructor called." RESET << std::endl;
}

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	std::cout << CYAN "PresidentialPardonForm" YELLOW " copy assigment operator called." RESET << std::endl;
	if ( this == &rhs ) return *this;
	this->setSign(rhs.getSign());
	this->setTarget(rhs.getTarget());
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	checkExecution(executor);
	std::cout << YELLOW << this->getTarget() << GREEN " has been pardoned by Zafod Beeblebrox." RESET << std::endl;
}

void PresidentialPardonForm::checkExecution(Bureaucrat const & executor) const {
	if (this->getToExec() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getSign())
		throw IsNotSignedException();
}

Form* PresidentialPardonForm::makeForm(const std::string& target) {
	return ( new PresidentialPardonForm("Pardon", target));
}
