#include "Karen.hpp"
#include <iostream>

Karen::Karen()
{
	init();
}

Karen::~Karen()
{
}

void Karen::init(void)
{
	func[0].level = "debug";
	func[1].level = "info";
	func[2].level = "warning";
	func[3].level = "error";

	func[0].ptr = &Karen::debug;
	func[1].ptr = &Karen::info;
	func[2].ptr = &Karen::warning;
	func[3].ptr = &Karen::error;
}

void Karen::complain(std::string level) {
	bool	flag = true;

	for (size_t i = 0; i < 4; i++)
	{
		if (level == func[i].level)
		{
			(this->*(func[i].ptr))();
			flag = false;
			break ;
		}
	}
	if (flag)
		std::cout << "I can't complain this!" << std::endl;
}

void Karen::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Karen::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Karen::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Karen::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
