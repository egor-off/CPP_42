#include "ClapTrap.hpp"

int main()
{
	ClapTrap vasya("Vasya");
	ClapTrap sega("Sega");

	vasya.setAd(2);
	sega.setAd(10);
	vasya.attack("Sega");
	sega.takeDamage(2);
	sega.beRepaired(1);
	sega.attack("Vasya");
	vasya.takeDamage(10);
	std::cout << " --- lets try to repair Vasya --- " << std::endl;
	vasya.beRepaired(88);
	std::cout << " --- nothing happens. hust like it should be --- " << std::endl;
}
