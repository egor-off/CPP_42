#include "Transformation.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Expected input: ./convert <value>\n";
		return (1);
	}

	int	a;
	a = std::atoi(av[1]);
	if (a == 0 && av[1][0] != '0' && av[1][1] == '\0')
	{
		int i;
		i = static_cast<int>(av[1][0]);
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
		std::cout << "int: " << static_cast<int>(i) << "\n";
		std::cout << "float: " << static_cast<float>(i) << ".0f\n";
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	}
	else
	{
		Transformation t(av[1]);
		std::cout << t;
	}
	return (0);
}
