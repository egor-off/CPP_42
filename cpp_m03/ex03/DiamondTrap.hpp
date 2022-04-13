#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{

	public:

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();
		DiamondTrap &		operator=( DiamondTrap const & rhs );
		void whoAmI(void);

		std::string getName() const;
		void setName(const std::string &Name);
	private:
		std::string	name;
};

#endif /* ***************************************************** DIAMONDTRAP_H */
