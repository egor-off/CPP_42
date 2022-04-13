#include "RobotomyRequestForm.hpp"
RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45)
{
	std::cout << CYAN "RobotomyRequestForm" YELLOW " deafault constructor called." RESET << std::endl;
	this->setTarget("target");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name, const std::string& target): Form(name, 72, 45)
{
	std::cout << CYAN "RobotomyRequestForm" YELLOW "  constructor with name called." RESET << std::endl;
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
{
	std::cout << CYAN "RobotomyRequestForm" YELLOW " copy constructor called." RESET << std::endl;
	this->setSign(src.getSign());
	this->setTarget(src.target);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << CYAN "RobotomyRequestForm" RED " destructor called." RESET << std::endl;
}

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	std::cout << CYAN "RobotomyRequestForm" YELLOW " copy assigment operator called." RESET << std::endl;
	if ( this == &rhs ) return *this;
	this->setSign(rhs.getSign());
	this->setTarget(rhs.getTarget());
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkExecution(executor);

	std::cout << MAGNETA "* Unbearable drilling noises *" RESET << std::endl;
	if (std::rand() % 2)
		std::cout << GREEN "The victi... " CYAN << this->target << GREEN " has been successfull"
			"y robotomized" RESET << std::endl;
	else
		std::cout << RED "The robotomization on " CYAN << this->target << RED " may or may "
			"not have been a complete and utter failure." RESET << std::endl;
}

void RobotomyRequestForm::checkExecution(Bureaucrat const & executor) const {
	if (this->getToExec() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getSign())
		throw IsNotSignedException();
}

Form* RobotomyRequestForm::makeForm(const std::string& target) {
	return (new RobotomyRequestForm("Robot", target));
}
