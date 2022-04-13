#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define CYAN "\033[0;36m"
# define MAGNETA "\033[0;35m"
# define RESET "\033[0m"

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		unsigned int getAd() const;
		void setAd(const unsigned int ad);

		unsigned int getHp() const;
		void setHp(const unsigned int hp);

		unsigned int getEp() const;
		void setEp(const unsigned int ep);

		std::string getName() const;
		void setName(const std::string name);

	private:
		std::string		name;
		unsigned int	hp;
		unsigned int	ep;
		unsigned int	ad;
};

#endif /* ******************************************************** CLAPTRAP_H */
