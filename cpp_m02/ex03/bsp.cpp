#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed vpp1, vpp2, vpp3;

	vpp1 = ((a.getX() - point.getX()) * (b.getY() - a.getY())) - ((b.getX() - a.getX()) * (a.getY() - point.getY()));
	vpp2 = ((b.getX() - point.getX()) * (c.getY() - b.getY())) - ((c.getX() - b.getX()) * (b.getY() - point.getY()));
	vpp3 = ((c.getX() - point.getX()) * (a.getY() - c.getY())) - ((a.getX() - c.getX()) * (c.getY() - point.getY()));

	if ((vpp1 < 0 && vpp2 < 0 && vpp3 < 0) || (vpp1 > 0 && vpp2 > 0 && vpp3 > 0))
		return true;
	return false;
}
