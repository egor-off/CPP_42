#include "Karen.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please, enter 1 parameter to start program" << std::endl;
		return (1);
	}
	Karen k;

	k.complain(av[1]);
	return (0);
}
