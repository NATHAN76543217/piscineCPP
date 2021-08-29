#include "Point.hpp"

Fixed side (Point const test, Point const corn1, Point const corn2)
{
	Fixed tmp;

	tmp = (test.getAbs() - corn2.getAbs()) * (corn1.getOrd() - corn2.getOrd())
		- (corn1.getAbs() - corn2.getAbs()) * (test.getOrd() - corn2.getOrd()
		+ Fixed::getEpsilonSquare());
	return tmp;
}

bool bsp (Point const a, Point const b, Point const c, Point const point)
{
	bool	all_neg, all_pos;
	Fixed	d1, d2, d3;

	d1 = side(point, a, b);
	d2 = side(point, b, c);
	d3 = side(point, c, a);

	all_neg = (d1 < 0) && (d2 < 0) && (d3 < 0);
    all_pos = (d1 > 0) && (d2 > 0) && (d3 > 0);
	return ( all_neg || all_pos );
}
