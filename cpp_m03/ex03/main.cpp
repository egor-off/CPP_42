#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap vova("Vova");
	DiamondTrap n;

	std::cout << vova.DiamondTrap::ScavTrap::ClapTrap::getName() << " " << vova.DiamondTrap::getName() << " " << vova.getHp() << " " << vova.getEp() << std::endl;

	n.whoAmI();
	n = vova;
	n.whoAmI();
	vova.attack("Nothing");
	vova.highFivesGuys();
	vova.guardGate();
	vova.takeDamage(5);
	vova.whoAmI();
	vova.setName("Vasya");
	vova.whoAmI();
}
