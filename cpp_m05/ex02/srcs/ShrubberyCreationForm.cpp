#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreation", 145, 137)
{
	std::cout << CYAN "ShrubberyCreationForm" YELLOW " deafault constructor called." RESET << std::endl;
	this->setTarget("target");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, const std::string& target): Form(name, 145, 137)
{
	std::cout << CYAN "ShrubberyCreationForm" YELLOW "  constructor with name called." RESET << std::endl;
	this->setTarget(target);
}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ): Form(src.getName())
{
	std::cout << CYAN "ShrubberyCreationForm" YELLOW " copy constructor called." RESET << std::endl;
	this->setSign(src.getSign());
	this->setTarget(src.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << CYAN "ShrubberyCreationForm" RED " destructor called." RESET << std::endl;
}

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	std::cout << CYAN "ShrubberyCreationForm" YELLOW " copy assigment operator called." RESET << std::endl;
	if ( this == &rhs ) return *this;
	this->setSign(rhs.getSign());
	this->setTarget(rhs.getTarget());
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	checkExecution(executor);

	std::ofstream	tree_file;
	std::string		filename = getTarget() + "_shrubbery";
	tree_file.open(filename.c_str(), std::ios::out);
	tree_file << "                      ___" << std::endl;
	tree_file << "                _,-\'\"\"   \"\"\"\"`--." << std::endl;
	tree_file << "             ,-\'          __,,-- \\" << std::endl;
	tree_file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
	tree_file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
	tree_file << "        ,\'       _Hb ___dF\"-._,-\'" << std::endl;
	tree_file << "      ,\'      _,-\"\"\"\"   \"\"--..__" << std::endl;
	tree_file << "     (     ,-\'                  `." << std::endl;
	tree_file << "      `._,\'     _   _             ;" << std::endl;
	tree_file << "       ,\'     ,\' `-\'Hb-.___..._,-\'" << std::endl;
	tree_file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
	tree_file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
	tree_file << "                \"Hb HH dF" << std::endl;
	tree_file << "                 \"HbHHdF" << std::endl;
	tree_file << "                  |HHHF" << std::endl;
	tree_file << "                  |HHH|" << std::endl;
	tree_file << "                  |HHH|" << std::endl;
	tree_file << "                  |HHH|" << std::endl;
	tree_file << "                  |HHH|" << std::endl;
	tree_file << "                  dHHHb" << std::endl;
	tree_file << "                .dFd|bHb.               o" << std::endl;
	tree_file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
	tree_file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
	tree_file << "##########################################" << std::endl;
	tree_file.close();
}

void ShrubberyCreationForm::checkExecution(Bureaucrat const & executor) const {
	if (this->getToExec() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getSign())
		throw IsNotSignedException();
}
