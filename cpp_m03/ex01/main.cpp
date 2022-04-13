#include "ScavTrap.hpp"

int main()
{
	ClapTrap vasya("Vasya");
	ClapTrap sega("Sega");

	// vasya.setAd(2);
	// // sega.setAd(10);
	// vasya.attack("Sega");
	// sega.takeDamage(vasya.getAd());
	// sega.beRepaired(1);
	// sega.attack("Vasya");
	// vasya.takeDamage(sega.getAd());
	// vasya.beRepaired(88);

	std::cout << "-------------------------------------------------" << std::endl;

	ScavTrap sasha("Sasha");
	ScavTrap sasha2(sasha);
	// std::cout << "Sega has " << sega.getHp() << " health points. Let's attack him, Sasha!" << std::endl;
	// sasha.attack("Sega");
	// sega.takeDamage(sasha.getAd());
	// sasha.attack("Sega");
	// sega.takeDamage(sasha.getAd());
	// std::cout << " --- lets try to repair Sega --------------------" << std::endl;
	// sega.beRepaired(22);
	// std::cout << " --- nothing happens. Just like planed. Sega still has " << sega.getHp() << " hp ---" << std::endl;
}
