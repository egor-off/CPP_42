#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGNETA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"


int main()
{
	ClapTrap vasya("Vasya");
	ClapTrap sega("Sega");

	vasya.setAd(2);
	// sega.setAd(10);
	vasya.attack("Sega");
	sega.takeDamage(vasya.getAd());
	sega.beRepaired(1);
	sega.attack("Vasya");
	vasya.takeDamage(sega.getAd());
	vasya.beRepaired(88);

	std::cout << MAGNETA "-------------------------------------------------" RESET << std::endl;

	ScavTrap sasha("Sasha");
	std::cout << CYAN "Sega" RESET" has " << sega.getHp() << " health points. Let's attack him, Sasha!" << std::endl;
	sasha.attack("Sega");
	sega.takeDamage(sasha.getAd());
	sasha.attack("Sega");
	sega.takeDamage(sasha.getAd());
	std::cout << " --- lets try to repair " CYAN "Sega" RESET " -------------------" << std::endl;
	sega.beRepaired(22);
	std::cout << " --- nothing happens. Just like planed." CYAN " Sega" RESET " still has " << sega.getHp() << " hp ---" << std::endl;
	std::cout << "Let's check one more thing." << std::endl;
	sasha.guardGate();
	std::cout << MAGNETA "-------------------------------------------------" RESET << std::endl;

	FragTrap goga("Goga");
	std::cout << "Goga has " << goga.getAd() << " attack damage. But also he likes HighFive! Let's check!" << std::endl;
	goga.highFivesGuys();
	std::cout << "Wow, ty " << goga.getName() << " for this gesture!" << std::endl;
	std::cout << "But what if " << goga.getName() << " will try to attack Sasha? Sasha has " << sasha.getHp() << " hp now." << std::endl;
	goga.attack("Sasha");
	sasha.takeDamage(goga.getAd());
	std::cout << "And now" CYAN " Sasha" RESET " has " CYAN << sasha.getHp() << RESET " hp. Nice! Mb try to kill Sasha?" << std::endl;
	goga.attack("Sasha");
	sasha.takeDamage(goga.getAd());
	goga.attack("Sasha");
	sasha.takeDamage(goga.getAd());
	goga.attack("Sasha");
	sasha.takeDamage(goga.getAd());
	std::cout << "Rest in peace, " CYAN << sasha.getName() << RESET "." << std::endl;
}
