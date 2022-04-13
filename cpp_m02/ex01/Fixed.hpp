#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					fpNum;
	static const int	fBit = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int fpNum);
	Fixed(const float fpNum);
	~Fixed();
	Fixed & operator=(const Fixed &fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream & operator<<(std::ostream &out, Fixed const &fixed);

#endif
