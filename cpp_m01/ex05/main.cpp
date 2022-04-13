#include "Karen.hpp"
#include <iostream>

int main(void)
{
	Karen k;

	k.complain("debug");
	std::cout << std::endl;
	k.complain("info");
	std::cout << std::endl;
	k.complain("warning");
	std::cout << std::endl;
	k.complain("error");
	std::cout << std::endl;
	k.complain("azaza");
}
