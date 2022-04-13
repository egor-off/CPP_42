#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << CYAN "MateriaSource " YELLOW "default constructor called." RESET << std::endl;
	this->set_empty_materias();
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	std::cout << CYAN "MateriaSource " YELLOW "copy constructor called." RESET << std::endl;
	this->copy_materials(src);
}

MateriaSource::~MateriaSource()
{
	std::cout << CYAN "MateriaSource " RED "default destructor called." RESET << std::endl;
	this->clean_materials();
}

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	std::cout << CYAN "MateriaSource " YELLOW "copy assigment operator called." RESET << std::endl;
	if (this == &rhs) return (*this);
	this->copy_materials(rhs);
	return (*this);
}

void MateriaSource::learnMateria(AMateria* am) {
	if (this->if_learned(am->getType())) return ;
	this->add_material(am);
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (size_t i = 0; i < counte_type; ++i)
	{
		if (this->materias[i]->getType() == type)
			return (this->materias[i]->clone());
	}
	return nullptr;
}

void	MateriaSource::clean_materials() {
	for (size_t i = 0; i < counte_type; ++i)
		delete this->materias[i];
	this->set_empty_materias();
	this->materias_learned = 0;
}

void	MateriaSource::set_empty_materias() {
	for (size_t i = 0; i < counte_type; ++i)
		this->materias[i] = nullptr;
	this->materias_learned = 0;
}

void	MateriaSource::copy_materials(const MateriaSource & ms) {
	this->clean_materials();
	for (size_t i = 0; i < counte_type; ++i)
		this->materias[i] = ms.materias[i]->clone();
	this->materias_learned = ms.materias_learned;
}

bool	MateriaSource::if_learned(const std::string& type) {
	for (size_t i = 0; i < counte_type; ++i)
	{
		if (this->materias[i] != nullptr && this->materias[i]->getType() == type)
			return true;
	}
	return false;
}

void	MateriaSource::add_material(AMateria* am) {
	for (size_t i = 0; i < counte_type; ++i)
	{
		if (this->materias[i] == nullptr)
		{
			this->materias[i] = am;
			break;
		}
	}
}
