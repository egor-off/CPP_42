#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{

public:
	Point();
	Point( Point const & src );
	Point( float const x, float const y);
	~Point();
	Point &		operator=( Point const & rhs );
	Fixed getX() const;
	Fixed getY() const;
private:
	Fixed const x;
	Fixed const y;
};

std::ostream &			operator<<( std::ostream & o, Point const & i );
bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif /* *********************************************************** POINT_H */
