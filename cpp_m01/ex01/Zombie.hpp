#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name_);
		~Zombie();
		void announce(void);

		void SetName(const std::string &Name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
