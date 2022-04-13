#include <string>
#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *strPTR = &string;
	std::string &strREF = string;

	std::cout << "address string: " << &string << std::endl;
	std::cout << "address strPTR: " << strPTR << std::endl;
	std::cout << "address strREF: " << &strREF << std::endl;

	std::cout << "string: " << string << std::endl;
	std::cout << "strPTR: " << *strPTR << std::endl;
	std::cout << "strREF: " << strREF << std::endl;
}
