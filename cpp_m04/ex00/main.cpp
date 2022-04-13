#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	WrongAnimal* wc = new WrongCat();
	WrongAnimal* wa = new WrongAnimal();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << wa->getType() << std::endl;
	std::cout << wc->getType() << std::endl;
	wa->makeSound();
	wc->makeSound();

	delete wa;
	delete wc;
	delete meta;
	delete j;
	delete i;
}
