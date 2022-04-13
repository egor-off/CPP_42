#include "Transformation.hpp"

Transformation::Transformation(const char *input) : input(input) {}

Transformation::Transformation(const Transformation &other)
{
	if (this != &other)
		input = other.input;
}

Transformation::~Transformation() {}

Transformation	&Transformation::operator=(const Transformation &other)
{
	input = other.input;
	return (*this);
}

char	Transformation::getChar() const
{
	char	res;

	try
	{
		res = static_cast<char>(std::stoi(input));
	}
	catch (const std::exception &e)
	{
		throw Transformation::TransformationIsImpossible();
	}
	if (res < 32 || res > 126)
		throw Transformation::NonDisplayableCharacters();
	return (res);
}

int	Transformation::getInt() const
{
	int	res = 0;

	try
	{
		res = std::stoi(input);
	}
	catch (const std::exception &e)
	{
		throw Transformation::TransformationIsImpossible();
	}
	return (res);
}

float	Transformation::getFloat() const
{
	float	res = 0;
	try
	{
		res = std::stof(input);
	}
	catch (const std::exception &e)
	{
		throw Transformation::TransformationIsImpossible();
	}
	return (res);
}

double	Transformation::getDouble() const
{
	double	res = 0;
	try
	{
		res = std::stod(input);
	}
	catch (const std::exception &e)
	{
		throw Transformation::TransformationIsImpossible();
	}
	return (res);
}

const char	*Transformation::NonDisplayableCharacters::what() const throw()
{
	return ("Non displayable");
}

const char	*Transformation::TransformationIsImpossible::what() const throw()
{
	return ("impossible");
}

std::ostream	&operator<<(std::ostream &out, const Transformation &Transformation)
{
	try
	{
		char c = Transformation.getChar();
		out << "char: '" << c << "'" << std::endl;
	}
	catch (const std::exception &e)
	{
		out << "char: ";
		out << e.what() << std::endl;
	}
	try
	{
		out << "int: " << Transformation.getInt() << std::endl;
	}
	catch (const std::exception &e)
	{
		out << e.what() << std::endl;
	}
	try
	{
		out << "float: " << Transformation.getFloat();
		if (Transformation.getFloat() - static_cast<int>(Transformation.getFloat()) == 0)
			out << ".0";
		out << "f" << std::endl;
	}
	catch (const std::exception &e)
	{
		out << e.what() << std::endl;
	}
	try
	{
		out << "double: " << Transformation.getDouble();
		if (Transformation.getDouble() - static_cast<int>(Transformation.getDouble()) == 0)
			out << ".0";
		out << std::endl;
	}
	catch (const std::exception &e)
	{
		out << e.what() << std::endl;
	}
	return (out);
}
