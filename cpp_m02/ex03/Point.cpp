#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : x(0), y(0)
{
}

Point::Point( const Point & src ) : x(src.x), y(src.y)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::Point( float const x, float const y) : x(x), y(y)
{
}

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	if (this == &rhs) return *this;
	this->~Point();
	new (this) Point(rhs);
	return *this;
}

Fixed Point::getX() const{
	return (this->x);
}

Fixed Point::getY() const{
	return (this->y);
}

std::ostream &			operator<<( std::ostream & o, Point const & i )
{
	o << "x = " << i.getX() << ", y = " << i.getY();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
