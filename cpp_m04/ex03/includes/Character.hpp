#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{

	public:

		Character();
		Character(const std::string name);
		Character( Character const & src );
		~Character();

		Character &		operator=( Character const & rhs );

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		static const size_t	invent_size = 4;
		std::string			name;
		AMateria*			invent[Character::invent_size];
		size_t				invent_equiped;
		void	clean_invent();
		void	set_empty_invent();
		void	copy_invent( Character const & src );
};

#endif /* ******************************************************* CHARACTER_H */
