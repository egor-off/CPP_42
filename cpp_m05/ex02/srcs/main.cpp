#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Form* form;
	Bureaucrat bob("Bob", 1);
	Bureaucrat phil("Phil", 40);
	Bureaucrat luc("Luc", 150);

	{
		form = new ShrubberyCreationForm("28C", "tree");
		bob.signForm(*form);
		phil.executeForm(*form);
		// luc.executeForm(*form);
		delete form;
		form = NULL;
		form = new ShrubberyCreationForm("30A", "nope");
		bob.executeForm(*form);
	}

	delete form;
	form = NULL;

	{
		form = new RobotomyRequestForm("28B", "robot");
		bob.signForm(*form);
		bob.executeForm(*form);
		bob.executeForm(*form);
		bob.executeForm(*form);
		bob.executeForm(*form);
		bob.executeForm(*form);
		bob.executeForm(*form);
		bob.executeForm(*form);
		bob.executeForm(*form);
		delete form;
		form = NULL;
	}

	{
		form = new PresidentialPardonForm("28A", "Other_man");
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
		form = NULL;
	}

	{
		form = new PresidentialPardonForm("28A", "Other_man");
		bob.executeForm(*form);
		luc.executeForm(*form);
	}
	delete form;
	return 0;
}
