#include <iostream>
#include "Data.hpp"
#include "color.hpp"

int main(void)
{
	Data *structure = new Data();
	Data *tmpStruct;
	uintptr_t tmp;

	structure->num = 42;
	structure->str = "test";

	std::cout << GREEN "ADRESS struct " CYAN << structure << RESET "\n";
	std::cout << BLUE "tmpStruct num " RED << structure->num << RESET "\n";
	std::cout << BLUE "tmpStruct str " RED << structure->str << "\n";

	std::cout << YELLOW "----------- serialize -----------\n" RESET;
	tmp = serialize(structure);
	std::cout << GREEN "ADRESS tmp " CYAN << &tmp << RESET "\n";
	std::cout << MAGNETA "data tmp " RED << tmp << "\n";

	std::cout << YELLOW "---------- deserialize ----------\n" RESET;
	tmpStruct = deserialize(tmp);
	std::cout << GREEN "ADRESS struct " CYAN << tmpStruct << RESET "\n";
	std::cout << BLUE "tmpStruct num " RED << tmpStruct->num << RESET "\n";
	std::cout << BLUE "tmpStruct str " RED << tmpStruct->str << RESET "\n";

	delete structure;
	return (0);
}
