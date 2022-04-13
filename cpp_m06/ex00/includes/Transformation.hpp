#ifndef Transformation_HPP
#define Transformation_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

class Transformation
{
public:
	Transformation(const char *input);
	Transformation(const Transformation &other);
	~Transformation();
	Transformation &operator=(const Transformation &other);

	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;

	class NonDisplayableCharacters;
	class TransformationIsImpossible;

private:
	std::string	input;
};

class Transformation::NonDisplayableCharacters: public std::exception
{
	public:
		const char *what() const throw();
};

class Transformation::TransformationIsImpossible: public std::exception
{
	public:
		const char *what() const throw();
};

std::ostream &operator<<(std::ostream &out, const Transformation &Transformation);

#endif
