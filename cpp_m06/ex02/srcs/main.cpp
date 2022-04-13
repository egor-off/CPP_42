#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include "color.hpp"

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Base* generate(void)
{
	int rand = getRandomNumber(1, 3);
	switch (rand)
	{
	case 1:
		return (new A());
	case 2:
		return (new B());
	default:
		return (new C());
	}
}

void recust(Base &p){
	try{
		Base a = dynamic_cast<A &>(p);
		std::cout << GREEN "Class" BLUE " A \n" RESET;
	} catch(const std::exception &e) {}
	try{
		Base a = dynamic_cast<B &>(p);
		std::cout << GREEN "Class" BLUE " B \n" RESET;
	} catch(const std::exception &e) {}
	try{
		Base a = dynamic_cast<C &>(p);
		std::cout << GREEN "Class" BLUE " C \n" RESET;
	} catch(const std::exception &e) {}
	return ;
}

void recust(Base *p){
	if (dynamic_cast<A *>(p))
		std::cout << YELLOW "Class" CYAN " A \n" RESET;
	if (dynamic_cast<B *>(p))
		std::cout << YELLOW "Class" CYAN " B \n" RESET;
	if (dynamic_cast<C *>(p))
		std::cout << YELLOW "Class" CYAN " C \n" RESET;
	return ;
}

int	main()
{
	Base *clas;
	std::srand(std::time(nullptr));
	std::cout << MAGNETA "-------------------------" RESET << std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		clas = generate();
		recust(clas);
		recust(*clas);
		delete clas;
	std::cout << MAGNETA "-------------------------" RESET << std::endl;
	}

	return (0);
}
