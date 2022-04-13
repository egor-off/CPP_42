#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "color.hpp"
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:
		virtual ~AMateria();

		AMateria(std::string const & type);

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
	protected:
		std::string type;
};


#endif /* ******************************************************** AMATERIA_H */
