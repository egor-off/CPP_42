#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void)
{
	std::cout << "------------------- My Tests -------------------" << std::endl;
	Point a(0.1, 20.);
	Point b(0.1, 0.1);
	Point c(10, 0);
	Point point(1, 1);

	std::cout << bsp(a, b, c, point) << std::endl;
	point = Point(0.1, 1);
	std::cout << bsp(a, b, c, point) << std::endl;

	std::cout << a << " | " << b << " | " << c << " | " << point << std::endl;

	return (0);
}
