#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main()
{
	Animal* a[10];
	Cat* c = new Cat();
	for (size_t i = 0; i < 100; ++i)
		c->setIdea("cat's idea number " + std::to_string(i + 1), i);
	for (size_t i = 0; i < 5; ++i)
		std::cout << MAGNETA << c->getIdea(i) << RESET << std::endl;
	std::cout << MAGNETA "Checking wrong range: " << c->getIdea(200) << RESET << std::endl;
	Cat* c2 = new Cat(*c);
	for (size_t i = 0; i < 5; ++i)
		std::cout << MAGNETA << c2->getIdea(i) << RESET << std::endl;
	for (size_t i = 0; i < 5; ++i)
	{
		std::cout << MAGNETA "Creating Cat " << i << RESET << std::endl;
		a[i] = new Cat();
		a[i]->makeSound();
	}
	std::cout << BLUE "------------------------" RESET << std::endl;
	*a[0] = *c;
	delete c;
	delete c2;
	std::cout << BLUE "------------------------" RESET << std::endl;
	for (size_t i = 5; i < 10; ++i)
	{
		std::cout << MAGNETA "Creating Dog " << i << RESET << std::endl;
		a[i] = new Dog();
		a[i]->makeSound();
	}
	for (size_t i = 0; i < 10; ++i)
	{
		std::cout << MAGNETA "Deleting " << a[i]->getType() << " " << i << RESET << std::endl;
		delete a[i];
	}
	std::cout << BLUE "------------------------" RESET << std::endl;
}
