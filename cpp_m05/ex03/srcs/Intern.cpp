#include "Intern.hpp"

Intern::Intern()
{
	std::cout << CYAN "Intern" YELLOW " deafault constructor called." RESET << std::endl;
	makeList();
}

Intern::Intern( const Intern & src )
{
	std::cout << CYAN "Intern" YELLOW " copy constructor called." RESET << std::endl;
	makeList();
	(void) src;
}

Intern::~Intern()
{
	std::cout << CYAN "Intern" RED " destructor called." RESET << std::endl;
}

Intern &				Intern::operator=( Intern const & rhs )
{
	std::cout << CYAN "Intern" YELLOW " copy assigment operator called." RESET << std::endl;
	(void) rhs;
	return *this;
}

Form*	Intern::makeForm(const std::string& name_form, const std::string& target) {

	size_t	i = 0;
	Form* form;

	while (list[i].name != name_form && i < 4)
		++i;
	std::cout << YELLOW "Intern creates " GREEN << (list[i].name.empty() ? RED "nothing" : list[i].name) << std::endl;
	if (i == 4)
		return nullptr;
	form = list[i].makeForm(target);
	return (form);
}

void	Intern::makeList() {
	this->list[0].name = "presidential pardon";
	this->list[0].makeForm = PresidentialPardonForm::makeForm;
	this->list[1].name = "shrubbery creation";
	this->list[1].makeForm = ShrubberyCreationForm::makeForm;
	this->list[2].name = "robotomy request";
	this->list[2].makeForm = RobotomyRequestForm::makeForm;
	this->list[3].name = "";
	this->list[3].makeForm = nullptr;
}
