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
