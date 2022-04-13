#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "color.hpp"
# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class MateriaSource : public IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		MateriaSource &		operator=( MateriaSource const & rhs );

		void learnMateria(AMateria* am);
		AMateria* createMateria(std::string const & type);
	private:
		static const size_t	counte_type = 4;
		AMateria*			materias[MateriaSource::counte_type];
		size_t				materias_learned;
		void	clean_materials();
		void	set_empty_materias();
		void	copy_materials(const MateriaSource & ms);
		bool	if_learned(const std::string& type);
		void	add_material(AMateria* am);
		size_t	find_adx_materia(const std::string& type);
};

#endif /* *************************************************** MATERIASOURCE_H */
