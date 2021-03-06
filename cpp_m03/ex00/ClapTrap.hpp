#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		unsigned int getAd() const;
		void setAd(unsigned int Ad);

	private:
		std::string	name;
		unsigned int	hp;
		unsigned int	ep;
		unsigned int	ad;
};

#endif /* ******************************************************** CLAPTRAP_H */
